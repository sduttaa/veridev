import subprocess, tempfile
from autogen_core.tools import FunctionTool


def process_error_text(error: str, file_name: str) -> str:
    if not error.strip():
        return ""
    lines = error.split('\n')
    processed_error = ""

    for line in lines:
        line = line.strip()
        if not line or 'manual at' in line:
            continue
        if file_name in line:
            parts = line.split(file_name+":",1)
            if len(parts) == 2:
                    line = f"Line {parts[1]}"
        processed_error += (line + '\n')
    
    return processed_error

def verilator_TBlint_sv(code: str) -> dict:
    tmp = None
    try:
        # Create temporary file
        tmp = tempfile.NamedTemporaryFile(suffix=".sv", delete=False, mode='w')
        tmp.write(code)
        tmp.close()
        
        # Run verilator lint check
        cmd = ["verilator", "-Wno-lint", "-Wno-INITIALDLY", "--lint-only", tmp.name, "--error-limit", "0"]
        proc = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
        passed = proc.returncode == 0
        
        return {
            "pass": passed,
            "errors": process_error_text(proc.stderr, tmp.name) if not passed else "",
            #"warnings": proc.stdout,  # Verilator warnings go to stdout
        }
    except subprocess.TimeoutExpired:
        return {
            "pass": False,
            "errors": "Verilator lint check timed out",
            # "warnings": "",
        }
    except FileNotFoundError:
        return {
            "pass": False,
            "errors": "Verilator not found. Please install Verilator.",
            # "warnings": "",
        }
    except Exception as e:
        return {
            "pass": False,
            "errors": f"Error running lint check: {str(e)}",
            # "warnings": "",
        }
    finally:
        # Clean up temporary file
        if tmp and tmp.name:
            try:
                import os
                os.unlink(tmp.name)
            except OSError:
                pass  # File already deleted or doesn't exist

def verilator_RTLlint_sv(code: str) -> dict:
    tmp = None
    try:
        # Create temporary file
        tmp = tempfile.NamedTemporaryFile(suffix=".sv", delete=False, mode='w')
        tmp.write(code)
        tmp.close()
        
        # Run verilator lint check
        cmd = ["verilator", "--lint-only", tmp.name, "--error-limit", "0"]
        proc = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
        passed = proc.returncode == 0
        
        return {
            "pass": passed,
            "errors": process_error_text(proc.stderr, tmp.name) if not passed else "",
            #"warnings": proc.stdout,  # Verilator warnings go to stdout
        }
    except subprocess.TimeoutExpired:
        return {
            "pass": False,
            "errors": "Verilator lint check timed out",
            # "warnings": "",
        }
    except FileNotFoundError:
        return {
            "pass": False,
            "errors": "Verilator not found. Please install Verilator.",
            # "warnings": "",
        }
    except Exception as e:
        return {
            "pass": False,
            "errors": f"Error running lint check: {str(e)}",
            # "warnings": "",
        }
    finally:
        # Clean up temporary file
        if tmp and tmp.name:
            try:
                import os
                os.unlink(tmp.name)
            except OSError:
                pass  # File already deleted or doesn't exist

verilator_TBlint_sv_tool = FunctionTool(verilator_TBlint_sv, description = "Run Verilator lint check on SystemVerilog code. Input: Code to check. Output: dict with 'pass' (bool) and 'errors' (str) keys", strict=True)
verilator_RTLlint_sv_tool = FunctionTool(verilator_RTLlint_sv, description = "Run Verilator lint check on SystemVerilog code. Input: Code to check. Output: dict with 'pass' (bool) and 'errors' (str) keys", strict=True)
