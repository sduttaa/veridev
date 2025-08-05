import subprocess
from autogen_core.tools import FunctionTool

import os
import shutil
import subprocess
from typing import Tuple, Optional
import logging

logger = logging.getLogger(__name__)

class Simulator:
    def __init__(self,
                 tb_path: str,
                 rtl_path: str,
                 output_dir: str,
                 reference_rtl_path: Optional[str] = None,):
        self.tb_path = tb_path
        self.rtl_path = rtl_path
        self.output_dir = output_dir
        self.reference_rtl_path = reference_rtl_path

    def sim_verialtor_sv(self):
        return sim_verilator_sv(tb_path = self.tb_path,
                                rtl_path = self.rtl_path,
                                output_dir = self.output_dir,
                                reference_rtl_path = self.reference_rtl_path)

def extract_mismatch_count_verilator(output: str) -> int:
    """
    Extract mismatch count from Verilator simulation output.
    
    Args:
        output: Simulation output string
        
    Returns:
        Number of mismatches found (0 if simulation passed)
    """
    import re
    
    if "SIMULATION PASSED" in output:
        return 0
    
    # Look for patterns like "SIMULATION FAILED - X MISMATCHES DETECTED"
    patterns = [
        r"SIMULATION FAILED - (\d+) MISMATCHES DETECTED",
        r"(\d+) MISMATCHES DETECTED",
        r"FAILED.*?(\d+).*?MISMATCH",
    ]
    
    for pattern in patterns:
        match = re.search(pattern, output, re.IGNORECASE)
        if match:
            return int(match.group(1))
    
    # If simulation failed but no specific count found, assume at least 1 mismatch
    if "SIMULATION FAILED" in output or "FAILED" in output:
        return 1
    
    return 0

def sim_verilator_sv(
    tb_path: str,
    rtl_path: str,
    output_dir: str,
    reference_rtl_path: Optional[str] = None,
    timeout: int = 60
) -> Tuple[bool, int, str]:
    """
    Run Verilator simulation with given testbench and RTL files.
    
    Args:
        testbench_path: Path to the testbench .sv file
        rtl_path: Path to the RTL .sv file (generated)
        output_dir: Directory where obj_dir will be created
        reference_rtl_path: Optional path to reference RTL file
        timeout: Simulation timeout in seconds
        
    Returns:
        Tuple of (success: bool, sim_output: str)
        - success: True if compilation and simulation both succeeded
        - sim_output: Combined stdout/stderr from simulation execution
    """

    # Ensure output directory exists
    os.makedirs(output_dir, exist_ok=True)
    output_dir = os.path.abspath(output_dir)
    
    # Clean up any existing obj_dir
    obj_dir = os.path.join(output_dir, "obj_dir")
    if os.path.exists(obj_dir):
        shutil.rmtree(obj_dir)
        logger.info(f"Cleaned up existing {obj_dir}")
    
    # Extract testbench module name for executable naming
    executable_path = os.path.join(obj_dir, "sim_exec")
    
    # Build file list for Verilator
    file_list = [os.path.abspath(tb_path), os.path.abspath(rtl_path)]
    if reference_rtl_path and os.path.exists(reference_rtl_path):
        file_list.append(os.path.abspath(reference_rtl_path))
    
    # Construct Verilator compilation command
    compile_cmd = [
        "verilator",
        "-Wno-lint", "-Wno-INITIALDLY",           # Disable warnings for benchmark compatibility
        "--binary",            # Generate executable directly
        "--main",              # Auto-generate main() function
        "--timing",            # Support timing constructs
        "--sv",                # Enable SystemVerilog features
        "-j", "0",             # Use all CPU cores
        #"--Mdir", obj_dir,     # Specify output directory
        "-o", "sim_exec",      # Specify executable file name
    ] + file_list
    
    logger.info(f"Running Verilator compilation: {' '.join(compile_cmd)}")
    
    try:
        # Step 1: Compile with Verilator
        compile_result = subprocess.run(
            compile_cmd,
            cwd=output_dir,
            capture_output=True,
            text=True,
            timeout=timeout
        )
        
        if compile_result.returncode != 0:
            error_msg = f"Verilator compilation failed:\nSTDOUT:\n{compile_result.stdout}\nSTDERR:\n{compile_result.stderr}"
            #logger.error(error_msg)
            return False, -1, error_msg
        
        logger.info("Verilator compilation successful")
        
        # Step 2: Check if executable was created
        if not os.path.exists(executable_path):
            error_msg = f"Executable not found at {executable_path}\nSTDOUT:\n{compile_result.stdout}\nSTDERR:\n{compile_result.stderr}"
            #logger.error(error_msg)
            return False, -1, error_msg
        
        # Step 3: Run the simulation executable
        logger.info(f"Running simulation executable: {executable_path}")
        
        sim_result = subprocess.run(
            [executable_path],
            cwd=output_dir,
            capture_output=True,
            text=True,
            timeout=timeout
        )
        
        # Combine stdout and stderr for complete output
        combined_output = ""
        if sim_result.stdout:
            combined_output += f"STDOUT:\n{sim_result.stdout}\n"
        if sim_result.stderr:
            combined_output += f"STDERR:\n{sim_result.stderr}\n"
        
        # Check simulation success
        simulation_passed = (
            sim_result.returncode == 0 and
            ("SIMULATION PASSED" in sim_result.stdout or "no mismatches" in sim_result.stdout)
        )
        
        if simulation_passed:
            logger.info("Simulation completed successfully")
        else:
            logger.warning(f"Simulation failed or had errors. Return code: {sim_result.returncode}\n {combined_output}")
        
        # Clean up obj_dir after simulation
        try:
            if os.path.exists(obj_dir):
                shutil.rmtree(obj_dir)
                logger.info(f"Cleaned up {obj_dir} after simulation")
        except Exception as cleanup_error:
            logger.warning(f"Failed to cleanup {obj_dir}: {cleanup_error}")
        
        return simulation_passed, extract_mismatch_count_verilator(combined_output), combined_output
        
    except subprocess.TimeoutExpired:
        error_msg = f"Simulation timed out after {timeout} seconds"
        logger.error(error_msg)
        return False, -1, error_msg
        
    except FileNotFoundError as e:
        error_msg = f"Verilator not found. Please ensure Verilator is installed and in PATH: {e}"
        logger.error(error_msg)
        return False, -1, error_msg
        
    except Exception as e:
        error_msg = f"Unexpected error during simulation: {e}"
        logger.error(error_msg)
        return False, -1, error_msg


sim_verilator_sv_tool = FunctionTool(sim_verilator_sv, description = "Run Verilator simulation with given testbench and RTL files. Input: Code to check. Output: Tuple of 'success' (bool) and 'sim_output' (str)", strict=True)