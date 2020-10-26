#include "codegen/codegen.h"
#include "message/errors.h"

void CodeGen::visitBlockStmt(ASTNS::BlockStmt *a)
{
    context.incScope();
    for (std::unique_ptr<ASTNS::Stmt> &s : a->stmts)
        s->accept(this);
    context.decScope();
}
void CodeGen::visitExprStmt(ASTNS::ExprStmt *a)
{
    a->expr->accept(this);
}
void CodeGen::visitReturnStmt(ASTNS::ReturnStmt *a)
{
    if (a->val)
    {
        Value v = evalExpr(a->val.get());
        FunctionType *fty = dynamic_cast<FunctionType*>(context.curFunc.type);
        if (!v.val)
            return;
        Value vconv = fty->ret->castTo(context, v);
        if (!vconv.val)
            context.builder.CreateRet(vconv.val);
    }
    else
        context.builder.CreateRetVoid();
}

void CodeGen::visitVarStmt(ASTNS::VarStmt *a)
{
    std::string varname = tokenToStr(a->name);
    Type *ty = evalType(a->type.get());
    if (dynamic_cast<VoidType*>(ty))
    {
        msg::voidVarNotAllowed(a->type.get());
        return;
    }

    Local *var = context.findLocal(varname);
    if (var && var->scopenum == context.curScope)
    {
        msg::cannotRedefineVariable(a->name);
        return;
    }

    llvm::Function *f = context.builder.GetInsertBlock()->getParent();
    llvm::AllocaInst *alloca = context.createEntryAlloca(f, ty->toLLVMType(context.context), varname);
    context.addLocal(varname, ty, alloca);

    a->assign->accept(this);
}
