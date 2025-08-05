
from typing import List
from pydantic import BaseModel

from autogen_core.models import ChatCompletionClient

from veridev._prompts import RTL_EDIT_PROMPT, REASONING_PROMPT
from veridev.agent_template import HardwareAssistantAgent
from veridev.tools.syntax_checker import verilator_RTLlint_sv_tool

class Edit(BaseModel):
    old_content: str
    new_content: str

class RTLEditResponse(BaseModel):
    reasoning: str
    edits: List[Edit]

class RTLEditResponseUnreasoned(BaseModel):
    edits: List[Edit]


class RTLEditor:
    def __init__(self, 
                 model_client: ChatCompletionClient, 
                 reasoning: bool,
                 spec: str,
                 testbench: str,
                 rtl_code: str):
        self.model_client = model_client
        if reasoning:
            self.edit_format = RTLEditResponse
            edit_prompt = RTL_EDIT_PROMPT + REASONING_PROMPT
        else:
            self.edit_format = RTLEditResponseUnreasoned
            edit_prompt = RTL_EDIT_PROMPT
        self.spec = spec
        self.tb = testbench
        self.rtl = rtl_code
        self.rtl_editor = HardwareAssistantAgent(name="rtl_editor", 
                                     model_client=self.model_client, 
                                     #tools=[verilator_RTLlint_sv_tool],
                                     #max_tool_iterations=3,
                                     system_message=edit_prompt,
                                     output_content_type=self.edit_format)
    
    async def edit(self, sim_failed_log: str, sim_mismatch_cnt: int):
        result = await self.rtl_editor.generate(task=f"spec: {self.spec}\n testbench: {self.tb} rtl_code: {self.rtl}\n sim_failed_log: {sim_failed_log}\n sim_mismatch_cnt: {sim_mismatch_cnt}")
        if isinstance(result, self.edit_format):
            # Apply the edits to the RTL code
            edited_code = self._apply_edits(self.rtl, result.edits)
            return edited_code
        else:
            return "RTL editing failed"
    
    def _apply_edits(self, original_code: str, edits: List[Edit]) -> str:
        edited_code = original_code
        for edit in edits:
            # Apply each replacement
            edited_code = edited_code.replace(edit.old_content, edit.new_content)
        
        return edited_code