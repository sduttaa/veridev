
from pydantic import BaseModel

from autogen_core.models import ChatCompletionClient

from veridev._prompts import RTL_SYSTEM_PROMPT
from veridev.agent_template import HardwareAssistantAgent
from veridev.tools.syntax_checker import verilator_RTLlint_sv_tool
from veridev.tools.rag import RAGMemory


class RTLGenerator:
    def __init__(self, model_client: ChatCompletionClient):
        self.model_client = model_client
        gen_prompt = RTL_SYSTEM_PROMPT
        #self.rag = RAGMemory()
        self.rtl_gen = HardwareAssistantAgent(name="rtl_generator", 
                                     model_client=self.model_client, 
                                     #tools=[verilator_RTLlint_sv_tool],
                                     #max_tool_iterations=2,
                                     #memory = [self.rag.rag_memory],
                                     system_message=gen_prompt)
    async def generate(self, spec: str, io: str):
        #await self.rag.index_data()      # data is indexed if not done already
        result = await self.rtl_gen.generate(task = f"spec: {spec}\n module_interface: {io}\n")
        if isinstance(result, str):
            return result
        else:
            return "RTL generation failed"