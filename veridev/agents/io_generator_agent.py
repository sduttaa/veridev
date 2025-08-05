

from autogen_core.models import ChatCompletionClient

from veridev._prompts import IO_SYSTEM_PROMPT
from veridev.agent_template import HardwareAssistantAgent
from veridev.tools.syntax_checker import verilator_RTLlint_sv_tool
from veridev.tools.rag import RAGMemory


class IOGenerator:
    def __init__(self, model_client: ChatCompletionClient):
        self.model_client = model_client
        gen_prompt = IO_SYSTEM_PROMPT
        self.io_gen = HardwareAssistantAgent(name="io_generator", 
                                     model_client=self.model_client, 
                                     #tools=[verilator_RTLlint_sv_tool],
                                     #max_tool_iterations=10,
                                     system_message=gen_prompt)
    async def generate(self, spec: str):
      # data is indexed if not done already
        result = await self.io_gen.generate(task = f"spec: {spec}")
        if isinstance(result, str):
            return result
        else:
            return "IO generation failed"