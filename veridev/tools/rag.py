
from autogen_core.memory import Memory, MemoryContent, MemoryMimeType
from autogen_ext.memory.chromadb import (
    ChromaDBVectorMemory,
    PersistentChromaDBVectorMemoryConfig,
    SentenceTransformerEmbeddingFunctionConfig,
)

import json
import os

# ========== CONFIG ==========
JSONL_PATH = os.path.abspath("veridev/rag_data/fine_tune_dataset.jsonl")
COLLECTION_NAME = "dense_specs"
PERSIST_DIR = os.path.abspath("veridev_db")
MODEL_NAME = "all-MiniLM-L6-v2"
# ============================

# Ensure Chroma persistent storage
    

class RAGMemory:
    def __init__(self) -> None:
        self.rag_memory = ChromaDBVectorMemory(
            config=PersistentChromaDBVectorMemoryConfig(
            collection_name=COLLECTION_NAME,
            persistence_path=PERSIST_DIR,
            embedding_function_config=SentenceTransformerEmbeddingFunctionConfig(model_name=MODEL_NAME),
            k=3,  # Return top 3 results
            score_threshold=0.4,  # Minimum similarity score
            )
        )
    async def index_data(self):
        if not os.path.exists(PERSIST_DIR):
            os.makedirs(PERSIST_DIR)
            indexer = DataIndexer(memory=self.rag_memory)
            count = await indexer.index_jsonl(JSONL_PATH)
            print(f"Indexed {count} chunks from JSON data")
        else:
            print(f"Data directory {PERSIST_DIR} exists. Using existing indexed data.")


class DataIndexer:
    def __init__(self, memory: Memory) -> None:
        self.memory = memory
    async def index_jsonl(self, jsonl_path:str):
        count = 0

        with open(jsonl_path, "r", encoding="utf-8") as f:
            for line in f:
                obj = json.loads(line)
                if "problem" not in obj or not obj["problem"]:
                    continue
                await self.memory.add(
                        MemoryContent(content=obj, 
                                      mime_type=MemoryMimeType.JSON, 
                                      #metadata={"ID": obj["id"]}
                                     )
                )
                count += 1
                if count % 1000 == 0:
                    print(f"Indexed 1000 problems starting from Problem {count/1000-1}")
        return count