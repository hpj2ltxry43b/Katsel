#include "codegenlocal.h"
#include "message/errmsgs.h"
#include "ir/unit.h"

CodeGen::Declarator::Declarator(CodeGen &cg): cg(cg) {}

void CodeGen::Declarator::visitCU(ASTNS::CU *ast) {
    ast->decls->accept(this);
}

void CodeGen::Declarator::visitDeclList(ASTNS::DeclList *ast) {
    for (std::unique_ptr<ASTNS::Decl> &decl : ast->decls)
        decl->accept(this);
}

void CodeGen::Declarator::visitFunctionDecl(ASTNS::FunctionDecl *fun) {
    std::string fname (fun->name.stringify());
    IR::Value *declbefore = cg.unit->mod.getValue(fname);

    if (declbefore) {
        ERR_REDECL_SYM(fun->name, declbefore);
        cg.errored = true;
        return;
    }

    IR::Type *retty = cg.typeVisitor->type(fun->retty.get());
    if (!retty)
        return;

    std::vector<CodeGen::ParamVisitor::Param> params;
    if (fun->params) {
        CodeGen::ParamVisitor p (cg);
        fun->params->accept(&p);
        params = p.ret;
    }

    std::vector<IR::Type*> ptys;
    for (auto const &p : params)
        ptys.push_back(p.ty);

    IR::FunctionType *ft = cg.context->getFunctionType(retty, ptys);

    std::unique_ptr<IR::Function> f = std::make_unique<IR::Function>(ft, fname, fun);
    IR::Function *fraw = f.get();
    cg.unit->functions.push_back(std::move(f));
    cg.unit->mod.addValue(fname, fraw);
}

void CodeGen::Declarator::visitImplDecl(ASTNS::ImplDecl *impl) {
    IR::Type *implFor = cg.typeVisitor->type(impl->implFor.get());
    if (!implFor) {
        cg.errored = true;
        ERR_UNDECL_SYMB(impl->implFor.get());
        return;
    }

    // TODO
}

void CodeGen::Declarator::visitImplicitDecl(ASTNS::ImplicitDecl *) {}
