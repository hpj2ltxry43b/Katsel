#include "codegen/globalsassembler.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/DerivedTypes.h"

#include <iostream>

GlobalsAssembler::GlobalsAssembler(CodeGenContext &con, CodeGen &codeGen): context(con), codeGen(codeGen) {}

void GlobalsAssembler::visitProgram(ASTNS::Program *a)
{
    for (std::unique_ptr<ASTNS::Decl> &d : a->decls)
        d->accept(this);
}

void GlobalsAssembler::visitFunctionDecl(ASTNS::FunctionDecl *a)
{
    std::vector<Type*> paramtys;
    std::vector<llvm::Type*> paramtysllvm;
    Type *ret = codeGen.evalType(a->rettype.get());

    {
        ASTNS::Param *p = a->params.get();
        while (p)
        {
            Type *ty = codeGen.evalType(p->type.get());

            paramtys.push_back(ty);
            paramtysllvm.push_back(Type::toLLVMType(ty, context.context));

            p = p->next.get();
        }
    }

    std::string fnamestr (tokenToStr(a->name));

    llvm::Type *retTyllvm = Type::toLLVMType(ret, context.context);
    llvm::FunctionType *ft = llvm::FunctionType::get(retTyllvm, paramtysllvm, false);
    llvm::Function *f = llvm::Function::Create(ft, llvm::Function::ExternalLinkage, tokenToStr(a->name), context.mod.get());

    context.globalSymbolTable[fnamestr] = Value(context.getFunctionType(ret, paramtys), f);
}

void GlobalsAssembler::visitGlobalVarDecl(ASTNS::GlobalVarDecl *a)
{
    std::cerr << "Global Variable Declarations are not supported yet" << std::endl;
    // TODO: this
}
