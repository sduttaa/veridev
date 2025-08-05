
from typing import Sequence, List, Any, Awaitable, Callable, Union
from pydantic import BaseModel
from autogen_agentchat.agents import AssistantAgent
from autogen_core.tools._base import BaseTool
from autogen_core.models import ChatCompletionClient
from autogen_core.memory import Memory
from autogen_agentchat.messages import StructuredMessage, TextMessage

class HardwareAssistantAgent(AssistantAgent):
    def __init__(self, name: str, model_client: ChatCompletionClient, description: str = "", tools: List[Union[BaseTool[Any, Any], Callable[..., Any], Callable[..., Awaitable[Any]]]]| None = None, system_message: str | None = None, max_tool_iterations: int = 1, output_content_type: type[BaseModel] | None = None, memory: Sequence[Memory] | None = None):
        super().__init__(name=name, model_client=model_client, description=description, tools=tools, system_message=system_message, max_tool_iterations=max_tool_iterations, output_content_type=output_content_type, memory=memory)
    async def generate(self, task: str):
        result = await self.run(task = task)
        if isinstance(result.messages[-1], StructuredMessage):
            return result.messages[-1].content
        elif isinstance(result.messages[-1], TextMessage):
            return result.messages[-1].content