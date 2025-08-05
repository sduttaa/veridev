import os
import logging
from typing import List, Tuple
import asyncio

from veridev.agents.io_generator_agent import IOGenerator
from veridev.agents.rtl_editor_agent import RTLEditor
from veridev.agents.rtl_generator_agent import RTLGenerator
from veridev.agents.tb_generator_agent import TBGenerator
from veridev.tools.simulator import Simulator

from autogen_core.models import ChatCompletionClient

logger = logging.getLogger(__name__)


class TopAgent:
    def __init__(self, simple_model_client: ChatCompletionClient, medium_model_client: ChatCompletionClient, complex_model_client: ChatCompletionClient, output_path: str):
        self.reasoning = False
        self.sim_max_retry = 1
        self.rtl_max_candidates = 4
        self.rtl_selected_candidates = 2
        self.golden_tb_path: str | None = None
        self.golden_rtl_blackbox_path: str | None = None

        self.simple_model_client = simple_model_client
        self.medium_model_client = medium_model_client
        self.complex_model_client = complex_model_client
        self.output_path = output_path

    def write_output(self, content: str | None, file_path: str) -> None:
        if content:
            os.makedirs(os.path.dirname(file_path), exist_ok=True)
            with open(file_path, "w") as f:
                f.write(content)

    async def run_instance(self, spec: str, task_id: str) -> bool:
        """
        Run a single instance of the benchmark
        Return value:
        - is_pass: bool, whether the instance passes the golden testbench
        - rtl_code: str, the generated RTL code
        """

        self.output_dir_per_run = f"{self.output_path}/{task_id}"

        io_path = f"{self.output_dir_per_run}/io.sv"
        tb_path = f"{self.output_dir_per_run}/tb.sv"
        rtl_path = f"{self.output_dir_per_run}/rtl.sv"

        self.io_gen = IOGenerator(model_client=self.simple_model_client)
        self.tb_gen = TBGenerator(model_client=self.medium_model_client)
        self.rtl_gen = RTLGenerator(model_client=self.complex_model_client)
        self.simulator = Simulator(tb_path = tb_path, rtl_path = rtl_path, output_dir=self.output_dir_per_run)

        print("\n\n Generating interface...")
        interface = await self.io_gen.generate(spec=spec)
        self.write_output(interface, io_path)
        logger.info("Interface:")
        logger.info(interface)

        print("\n\n Generating testbench and RTL code...")
        tb_task = self.tb_gen.generate(spec=spec,io=interface)
        rtl_task = self.rtl_gen.generate(spec=spec, io=interface)

        testbench, rtl_code = await asyncio.gather(tb_task, rtl_task)

        self.write_output(testbench, tb_path)
        logger.info("Initial testbench:")
        logger.info(testbench)

        self.write_output(rtl_code, rtl_path)
        logger.info("Initial rtl:")
        logger.info(rtl_code)

        tb_needs_fix = True
        rtl_needs_fix = True

        for i in range(self.sim_max_retry):
            # run simulation judge, overwrite is_sim_pass
            sim_success, sim_mismatch_cnt, sim_log = self.simulator.sim_verialtor_sv()
            if sim_success:
                tb_needs_fix = False
                rtl_needs_fix = False
                break
           
            tb_needs_fix, revised_tb = await self.tb_gen.review(spec=spec, 
                                             io=interface, 
                                             failed_sim_log=sim_log, 
                                             tb=testbench, 
                                             rtl=rtl_code)
            if tb_needs_fix:
                testbench = revised_tb
                self.write_output(revised_tb, tb_path)
                logger.info("Revised tb:")
                logger.info(testbench)
            else:
                break

        tb_needs_fix = False 

        candidates_info: List[Tuple[str, int, str]] = []

        if rtl_needs_fix:
            # Candidates Generation

            for i in range(self.rtl_max_candidates):
                logger.info(f"Candidate generation: round {i + 1} / {self.rtl_max_candidates}")
                rtl_code_candidate = await self.rtl_gen.generate(spec=spec, io=interface)

                self.write_output(rtl_code_candidate, rtl_path)
                logger.info(f"{i+1}-th candidate rtl:")
                logger.info(rtl_code_candidate)
                sim_success_candidate, sim_mismatch_cnt_candidate, sim_log_candidate = self.simulator.sim_verialtor_sv()
                if sim_success_candidate:
                    rtl_code = rtl_code_candidate
                    sim_mismatch_cnt = sim_mismatch_cnt_candidate
                    rtl_needs_fix = False
                    break
                candidates_info.append( (rtl_code_candidate, sim_mismatch_cnt_candidate, sim_log_candidate) )

        candidates_info.sort(key=lambda x: x[1])
        candidates_info_selected = []
        candidates_info_rejected = []
        x = -1
        for candidate in candidates_info:
            if candidate[1] != x:
                candidates_info_selected.append(candidate)
                x = candidate[1]
            else:
                candidates_info_rejected.append(candidate)
        candidates_info_selected += candidates_info_rejected[:self.rtl_selected_candidates-len(candidates_info_selected)]

        if rtl_needs_fix:
            # Editor iteration
            for i in range(self.rtl_selected_candidates):
                logger.info(f"Selected candidate: round {i + 1} / {self.rtl_selected_candidates}")
                rtl_code, sim_mismatch_cnt, sim_log = candidates_info_selected[i]

                self.rtl_editor = RTLEditor(model_client=self.complex_model_client, 
                                            reasoning=self.reasoning,
                                            spec=spec,
                                            testbench=testbench,
                                            rtl_code=rtl_code)
                rtl_code = await self.rtl_editor.edit(sim_failed_log=sim_log,
                                                sim_mismatch_cnt=sim_mismatch_cnt)
                self.write_output(rtl_code, rtl_path)
                logger.info(f"Edited rtl candidate {i+1}:")
                logger.info(rtl_code)

                is_sim_pass, _ , _ = self.simulator.sim_verialtor_sv()
                if is_sim_pass:
                    rtl_needs_fix = False
                    break

        return not rtl_needs_fix   #rtl_needs_fix = False means that testbench was passed successfully


    

