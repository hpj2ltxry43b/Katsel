#include "codegen/context.h"

#include <iostream>
#include <cstdlib>

Type* CodeGenContext::getBuiltinType(BuiltinType::Builtins bty)
{
    for (std::unique_ptr<Type> &ty : types)
    {
        BuiltinType *b (dynamic_cast<BuiltinType*>(ty.get()));
        if  (b && b->type == bty)
            return ty.get();
    }

    std::unique_ptr<Type> ty = std::make_unique<BuiltinType>(bty);

    Type *tyr = ty.get();
    types.push_back(std::move(ty));

    return tyr;
}

Type* CodeGenContext::getFunctionType(Type *ret, std::vector<Type*> paramtys)
{
    for (std::unique_ptr<Type> &ty : types)
    {
        FunctionType *f (dynamic_cast<FunctionType*>(ty.get()));
        if  (f && f->ret == ret && f->paramtys == paramtys)
            return ty.get();
    }

    std::unique_ptr<Type> ty = std::make_unique<FunctionType>(ret, paramtys);

    Type *tyr = ty.get();
    types.push_back(std::move(ty));

    return tyr;
}

llvm::AllocaInst* CodeGenContext::createEntryAlloca(llvm::Function *f, llvm::Type* type, std::string const &name)
{
    llvm::IRBuilder<> b (&f->getEntryBlock(), f->getEntryBlock().begin());
    return b.CreateAlloca(type, 0, name.c_str());
}

void CodeGenContext::addLocal(std::string const &name, Type *type, llvm::AllocaInst *alloca)
{
    Value v {type, alloca};
    Local l {curScope, v, name};
    locals.push_back(l);
}

void CodeGenContext::incScope()
{
    ++curScope;

    if (curScope == 0) // default curScope value is 1
    {
        std::cerr << "Scope index overflowed to 0" << std::endl;
        std::abort();
    }
}

void CodeGenContext::decScope()
{
    --curScope;

    while (locals.size() && locals.back().scopenum > curScope) locals.pop_back();
}

Local* CodeGenContext::findLocal(std::string const &name)
{
    for (auto last = locals.rbegin(); last != locals.rend(); ++last)
        if (last->name == name)
            return &*last;

    return nullptr;
}