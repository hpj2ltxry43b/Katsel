#include "codegenlocal.h"
#include "message/errors.h"
#include "message/errmsgs.h"
#include "ir/unit.h"

CodeGen::ForwDecl::ForwDecl(CodeGen &cg): cg(cg) {}

void CodeGen::ForwDecl::visitCU(ASTNS::CU *ast)
{
    if (ast->dl)
        ast->dl->accept(this);
}

void CodeGen::ForwDecl::visitDeclList(ASTNS::DeclList *ast)
{
    ast->decllist->accept(this);
    ast->anotherdecl->accept(this);
}

void CodeGen::ForwDecl::visitFunctionDecl(ASTNS::FunctionDecl *fun)
{
    std::string fname (fun->name.stringify());
    IR::Value *declbefore = cg.context->getGlobal(fname);

    if (declbefore)
    {
        ERR_REDECL_SYM(fun->name, declbefore);
        cg.errored = true;
        return;
    }

    IR::Type *retty = cg.typeVisitor->type(fun->retty.get());
    if (!retty)
        return;

    std::vector<CodeGen::ParamVisitor::Param> params;
    if (fun->paramlist)
    {
        CodeGen::ParamVisitor p (cg);
        fun->paramlist->accept(&p);
        params = p.ret;
    }

    std::vector<IR::Type*> ptys;
    for (auto const &p : params)
        ptys.push_back(p.ty);

    IR::FunctionType *ft = cg.context->getFunctionType(retty, ptys);
    IR::Function *f = cg.unit->addFunction(ft, fname, fun);

    cg.context->globalSymbolTable[fname] = f;
}