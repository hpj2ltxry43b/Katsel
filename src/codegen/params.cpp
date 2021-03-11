#include "codegenlocal.h"
#include "message/errmsgs.h"
#include "ast/ast.h"

Codegen::Helpers::ParamVisitor::ParamVisitor::ParamVisitor(Codegen::Context &context, std::vector<std::unique_ptr<ASTNS::ParamB>> &params, TypeVisitor &type_visitor):
    errored(false),
    is_method(false), this_ptr(false), this_mut(false),
    context(context),
    type_visitor(type_visitor),
    index(0) {
    for (std::unique_ptr<ASTNS::ParamB> &p : params) {
        p->ast_accept(*this);
        ++index;
    }
}

void Codegen::Helpers::ParamVisitor::ast_visit(ASTNS::Param &ast) {
    Maybe<IR::Type&> ty (type_visitor->type(*ast.type));
    if (ty.has()) {
        IR::Function::Param p {ty.get(), ast.name.value.name, ast, ast.mut};
        ret.push_back(p);
    } else {
        errored = true;
        return;
    }
}

void Codegen::Helpers::ParamVisitor::ast_visit(ASTNS::ThisParam &ast) {
    if (!type_visitor->this_type.has()) {
        errored = true;
        Errors::TYPELESS_THIS(ast);
        return;
    }

    if (index != 0) {
        errored = true;
        Errors::THIS_NOT_FIRST(ast);
        return;
    }

    NNPtr<IR::Type> this_type = type_visitor->this_type.get();

    is_method = true;
    this_ptr = ast.ptr;
    this_mut = ast.mut;

    NNPtr<IR::Type> ty = ast.ptr ? context->get_pointer_type(ast.mut, *this_type) : this_type;

    IR::Function::Param p {ty, "this", ast, false};
    ret.push_back(p);
}
