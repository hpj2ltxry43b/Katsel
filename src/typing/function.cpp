#include "typing/type.h"
#include "message/errors.h"

#include "llvm/IR/Type.h"
#include "llvm/IR/DerivedTypes.h"

#include <sstream>
#include <iostream>
#include <cstdlib>

FunctionType::FunctionType(Type *ret, std::vector<Type*> paramtys): ret(ret), paramtys(paramtys) {}

llvm::Type* FunctionType::toLLVMType(llvm::LLVMContext &con)
{
    std::vector<llvm::Type*> paramsasllvm;
    for (Type *p : paramtys)
        paramsasllvm.push_back(p->toLLVMType(con));

    return llvm::FunctionType::get(ret->toLLVMType(con), paramsasllvm, false);

}

std::string FunctionType::stringify()
{
    std::stringstream ss;
    ss << ret->stringify() << "(";
    for (Type *pty : paramtys)
        ss << pty->stringify() << ", ";
    ss << ")";
    return ss.str();
}

bool FunctionType::hasOperator(TokenType)
{
    return false; // function has no operators
}

Value FunctionType::binOp(CodeGenContext &, Value, Value, Token op)
{
    report(MsgType::INTERNALERR, "FunctionType::binOp called", op, op);
    return Value();
}

Value FunctionType::unaryOp(CodeGenContext &, Value, Token op)
{
    report(MsgType::INTERNALERR, "FunctionType::unaryOp called", op, op);
    return Value();
}

Value FunctionType::castTo(CodeGenContext &, Value, Type *)
{
    std::cerr << "FunctionType::castTo called" << std::endl; // TODO: this work
    std::abort();
}

Value FunctionType::isTrue(CodeGenContext &, Value)
{
    return Value();
}
Type* FunctionType::pickType(Type *, Type *)
{
    std::cerr << "FunctionType::pickType called" << std::endl;
    std::abort();
}
