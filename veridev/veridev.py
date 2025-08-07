import argparse
import time
from datetime import timedelta
import asyncio
import sys
import os
from dotenv import load_dotenv

# Load environment variables from .env file
load_dotenv()


from veridev.agents.top_agent import TopAgent
from veridev.tools.benchmark_reader import TypeBenchmarkFile, get_benchmark_contents
from veridev.tools.simulator import sim_verilator_sv

from autogen_core.models._model_client import ModelInfo
from autogen_ext.models.openai import OpenAIChatCompletionClient

from logging import getLogger

logger = getLogger(__name__)


args_dict = {
    "filter_instance": "^(Prob018_mux256to1)$",
    # "filter_instance": "^(Prob070_ece241_2013_q2|Prob151_review2015_fsm)$",
    # "filter_instance": "^(Prob147_circuit10)$",
    # "filter_instance": "^(ExtraProb158)$",
    #"filter_instance": "^Prob.*$",
    # "filter_instance": "^(.*)$",
    "path_benchmark": "./verilog-eval/dataset_spec-to-rtl",
    "output_path": "./output"
}                                       # Note that we are using shortened prompts 


async def run(args: argparse.Namespace):
    total_start_time = time.monotonic()
    spec_dict = get_benchmark_contents(
        TypeBenchmarkFile.SPEC,
        args.path_benchmark,
        args.filter_instance,
    )
    golden_tb_path_dict = get_benchmark_contents(
        TypeBenchmarkFile.TEST_PATH,
        args.path_benchmark,
        args.filter_instance,
    )
    golden_rtl_path_dict = get_benchmark_contents(
        TypeBenchmarkFile.GOLDEN_PATH,
        args.path_benchmark,
        args.filter_instance,
    )
    gemini_api_key = os.environ.get("GEMINI_API_KEY")
    if gemini_api_key is None:
        raise ValueError("GEMINI_API_KEY environment variable is not set")

    simple_model_client = OpenAIChatCompletionClient(model="gemini-2.0-flash",
                                                    #model_info=ModelInfo(vision=True, function_calling=True, json_output=True, family="unknown", structured_output=True),
                                                    api_key=gemini_api_key,
                                                    )
    medium_model_client = OpenAIChatCompletionClient(model="gemini-2.5-flash",
                                                    model_info=ModelInfo(vision=True, function_calling=True, json_output=True, family="unknown", structured_output=True),
                                                    api_key=gemini_api_key,
                                                    temperature=0.2,
                                                    top_p=0.8)
    complex_model_client = OpenAIChatCompletionClient(model="gemini-2.5-flash",
                                                    model_info=ModelInfo(vision=True, function_calling=True, json_output=True, family="unknown", structured_output=True, multiple_system_messages=True),
                                                    api_key=gemini_api_key,
                                                    temperature=0.85,
                                                    top_p=0.9)
    # self.cons_model_client not implemented

    top_agent = TopAgent(simple_model_client=simple_model_client, 
                         medium_model_client=medium_model_client,
                         complex_model_client = complex_model_client, 
                         output_path=args.output_path)

    ret: dict[str, bool] = {}
    pass_cnt = 0
  
    for i, (task_id, spec) in enumerate(spec_dict.items()):
        start_time = time.monotonic()
        print(f"({i+1:03d}/{len(spec_dict):03d}) Current task: {task_id}")
        ret[task_id] = await top_agent.run_instance(task_id=task_id, spec=spec)
        
        run_time = timedelta(seconds=time.monotonic() - start_time)
        print(f"{task_id} took {run_time} to execute")
        is_pass , _ , _ = sim_verilator_sv( tb_path=golden_tb_path_dict[task_id],
                                            rtl_path=f"{args.output_path}/{task_id}/rtl.sv", 
                                            reference_rtl_path=golden_rtl_path_dict[task_id],
                                            output_dir=f"{args.output_path}/{task_id}")
        
        print(f"({i+1:03d}/{len(spec_dict):03d}) {task_id}: is_pass = {is_pass}")
        
        pass_cnt += is_pass

    print(f"Pass rate: {pass_cnt}/{len(spec_dict)}")

    total_run_time = timedelta(seconds=time.monotonic() - total_start_time)
    print(f"Totally took {total_run_time} to execute")


async def run_interactive(args: argparse.Namespace, spec:str):

    gemini_api_key = os.environ.get("GEMINI_API_KEY")
    if gemini_api_key is None:
        raise ValueError("GEMINI_API_KEY environment variable is not set")

    simple_model_client = OpenAIChatCompletionClient(model="gemini-2.0-flash",
                                                    #model_info=ModelInfo(vision=True, function_calling=True, json_output=True, family="unknown", structured_output=True),
                                                    api_key=gemini_api_key,
                                                    )
    medium_model_client = OpenAIChatCompletionClient(model="gemini-2.5-flash",
                                                    model_info=ModelInfo(vision=True, function_calling=True, json_output=True, family="unknown", structured_output=True),
                                                    api_key=gemini_api_key,
                                                    temperature=0.2,
                                                    top_p=0.8)
    complex_model_client = OpenAIChatCompletionClient(model="gemini-2.5-flash",
                                                    model_info=ModelInfo(vision=True, function_calling=True, json_output=True, family="unknown", structured_output=True, multiple_system_messages=True),
                                                    api_key=gemini_api_key,
                                                    temperature=0.85,
                                                    top_p=0.9)
    # self.cons_model_client not implemented

    top_agent = TopAgent(simple_model_client=simple_model_client, 
                         medium_model_client=medium_model_client,
                         complex_model_client = complex_model_client, 
                         output_path=args.output_path)

    ret: dict[str, bool] = {}

    task_id = "Problem_1"
    ret[task_id] = await top_agent.run_instance(task_id=task_id, spec=spec)
    
    tb_path = f"{args.output_path}/{task_id}/tb.sv"
    rtl_path = f"{args.output_path}/{task_id}/rtl.sv"

    is_pass , _ , sim_output = sim_verilator_sv( tb_path=tb_path,
                                        rtl_path=rtl_path, 
                                        output_dir=f"{args.output_path}/{task_id}")
    
    with open(tb_path, "r") as f:
        tb = f.read()
        print(f"\n\nTestbench:\n {tb}\n")

    with open(rtl_path, "r") as f:
        rtl = f.read()
        print(f"\n\nRTL code:\n {rtl}\n")

    verdict = "YES" if is_pass else "NO"
    print(f"\n\n Did the RTL code pass the testbench: {verdict}\n")

    print(f"\n\n Simulation results:\n {sim_output}")



def main():
    args = argparse.Namespace(**args_dict)
    # Regular benchmark mode
    if len(sys.argv) <= 1:
        asyncio.run(run(args))
    elif sys.argv[1] == "--spec" and len(sys.argv) > 2:
        spec = sys.argv[2]
        asyncio.run(run_interactive(args,spec))
    elif "--web" in sys.argv:
        import uvicorn
        from veridev.api import app
        port = int(os.environ.get("PORT", 8000))
        uvicorn.run(app, host="0.0.0.0", port=port)
        return

if __name__ == "__main__":
    main()
