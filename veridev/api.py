from fastapi import FastAPI, HTTPException, BackgroundTasks
from pydantic import BaseModel
import asyncio
import os
import tempfile
import shutil
from typing import Optional
import logging

# Import your existing veridev modules
from veridev.tools.simulator import sim_verilator_sv
from veridev.agents.top_agent import TopAgent
from config import Config
from autogen_core.models._model_client import ModelInfo
from autogen_ext.models.openai import OpenAIChatCompletionClient
from dotenv import load_dotenv

# Load environment variables from .env file
load_dotenv()

app = FastAPI(title="VeriDev API", description="AI-powered SystemVerilog generation")

class GenerationRequest(BaseModel):
    spec: str

class GenerationResponse(BaseModel):
    testbench: str = ""
    rtl: str = ""
    sim_output: str = ""

@app.get("/health")
async def health_check():
    return {"status": "healthy", "service": "veridev"}

@app.post("/generate", response_model=GenerationResponse)
async def generate_verilog(request: GenerationRequest):
    """
    Generate SystemVerilog code from natural language specification
    """
    # Generate task ID if not provided
    task_id = ""
    try:
        
        # Create temporary output directory
        with tempfile.TemporaryDirectory() as temp_dir:
            output_path = temp_dir
            
            # Initialize model clients (same as veridev.py)
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
            
            # Create TopAgent
            top_agent = TopAgent(
                simple_model_client=simple_model_client,
                medium_model_client=medium_model_client,
                complex_model_client=complex_model_client,
                output_path=output_path
            )
            
            # Run generation
            await top_agent.run_instance(spec=request.spec, task_id = task_id)
            
            # Read generated files
            testbench = ""
            rtl = ""
            
            
            tb_path = f"{output_path}/{task_id}/tb.sv"
            rtl_path = f"{output_path}/{task_id}/rtl.sv"
            
            
            if os.path.exists(tb_path):
                with open(tb_path, "r") as f:
                    testbench = f.read()
            
            if os.path.exists(rtl_path):
                with open(rtl_path, "r") as f:
                    rtl = f.read()

            _ , _ , sim_output = sim_verilator_sv( tb_path=tb_path,
                                        rtl_path=rtl_path, 
                                        output_dir=f"{output_path}/{task_id}")       
            
            return GenerationResponse(
                testbench=testbench,
                rtl=rtl,
                sim_output = sim_output
            )
            
    except Exception as e:
        
        return GenerationResponse(
            sim_output = str(e)
        )

@app.get("/")
async def root():
    return {
        "message": "VeriDev API", 
        "version": "1.0.0",
        "endpoints": {
            "POST /generate": "Generate SystemVerilog from specification",
            "GET /health": "Health check"
        }
    }

if __name__ == "__main__":
    import uvicorn
    port = int(os.environ.get("PORT", 8000))
    uvicorn.run(app, host="0.0.0.0", port=port)