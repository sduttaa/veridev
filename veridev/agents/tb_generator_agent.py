

from pydantic import BaseModel

from outlines.generate.cfg import cfg   

from autogen_core.models import ChatCompletionClient

from veridev._prompts import TB_SYSTEM_PROMPT, TB_REVIEW_SYSTEM_PROMPT
from veridev.agent_template import HardwareAssistantAgent
from veridev.tools.syntax_checker import verilator_TBlint_sv_tool


# SV_LANG = Language('build/sv.so', 'systemverilog')
# grammar = Grammar.from_path("tree-sitter-sv")     # Outlines grammar obj

# class GrammarModelClient(ChatCompletionClient):
#     """ChatCompletionClient that masks logits using a Tree-sitter CFG"""

#     def __init__(self, model="gpt-4o-mini", **kwargs):
#         super().__init__(**kwargs)
#         self._llm   = OpenAI(model)
#         self._parser = Parser()
#         self._parser.set_language(SV_LANG)

#     def _constrained_generate(self, prompt: str) -> str:
#         gen = cfg(self._llm, grammar, max_tokens=80)
#         for tok in gen.stream(prompt):
#             partial += tok.encode()
#             tree = self._parser.parse(partial)       # advance parser
#             yield tok                                # stream back

#     # --- AutoGen 0.6.4 async interface --------------------------------------
#     # async def create_stream(self, messages, **kwargs):
#     #     # LLM prompt = last user/assistant content glue
#     #     prompt = "\n".join(m.content for m in messages)
#     #     for tok in self._constrained_generate(prompt):
#     #         yield ChatCompletionChunk(token=tok)     # stream token

#     async def create(self, messages, **kwargs):
#         content = "".join(self._constrained_generate(
#             "\n".join(m.content for m in messages)))
#         return CreateResult(content=content, finish_reason="stop", usage=None, cached=False)


class TBReviewResponse(BaseModel):
    tb_needs_fix: bool
    testbench: str


class TBGenerator:
    def __init__(self, model_client: ChatCompletionClient):
        self.model_client = model_client
        gen_prompt = TB_SYSTEM_PROMPT
        review_prompt = TB_REVIEW_SYSTEM_PROMPT
        self.tb_gen = HardwareAssistantAgent(name="tb_generator", 
                                     model_client=self.model_client, 
                                     #tools=[verilator_TBlint_sv_tool],
                                     #max_tool_iterations=2,
                                     system_message=gen_prompt)
        self.tb_review = HardwareAssistantAgent(name="tb_reviewer", 
                                     model_client=self.model_client, 
                                     #tools=[verilator_TBlint_sv_tool],
                                     #max_tool_iterations=1,
                                     system_message=review_prompt,
                                     output_content_type=TBReviewResponse)
    async def generate(self, spec: str, io:str):
        result = await self.tb_gen.generate(task = f"spec: {spec}\n interface: {io}")
        if isinstance(result, str):
            return result
        else:
            return "testbench generation failed"
    async def review(self, spec: str, io: str, failed_sim_log: str, tb: str, rtl: str):
        result = await self.tb_review.generate(task = f"spec: {spec}\n interface: {io}\n failed_sim_log: {failed_sim_log}\n failed_testbench: {tb}\n failed_rtl: {rtl}")
        if isinstance(result, TBReviewResponse):
            return result.tb_needs_fix, result.testbench
        else:
            return False, "testbench review failed"