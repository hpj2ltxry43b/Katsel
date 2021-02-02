#include "codegenlocal.h"
#include "message/internal.h"
#include "message/report_abort.h"
#include "message/errmsgs.h"
#include "ir/unit.h"
#include "ast/ast.h"
#include "ir/instruction.h"
#include "ir/function.h"
#include "ir/block.h"

Codegen::Helpers::ExprCodegen::ExprCodegen(IR::Builder &ir_builder, Helpers::Locals &locals, TypeVisitor &type_visitor, PathVisitor &path_visitor):
    ir_builder(ir_builder),
    locals(locals),
    stmt_cg(ir_builder, locals, *this, type_visitor, path_visitor),
    type_visitor(type_visitor),
    path_visitor(path_visitor) {}

Maybe<IR::ASTValue> Codegen::Helpers::ExprCodegen::expr(ASTNS::Expr &ast) {
    ret = Maybe<IR::ASTValue>();
    ast.accept(*this);
    return ret;
}

void Codegen::Helpers::ExprCodegen::visit(ASTNS::BinaryExpr &ast) {
    Maybe<IR::ASTValue> m_lhs = expr(*ast.lhs);
    Maybe<IR::ASTValue> m_rhs = expr(*ast.rhs);
    if (!m_lhs.has() || !m_rhs.has()) {
        ret = Maybe<IR::ASTValue>();
        return;
    }

    IR::ASTValue lhs = m_lhs.get(), rhs = m_rhs.get();
    ret = lhs.type().bin_op(ir_builder->context(), ir_builder->fun(), ir_builder->cur_block(), ast.op, lhs, rhs, ast);
}
void Codegen::Helpers::ExprCodegen::visit(ASTNS::ShortCircuitExpr &ast) {
    Maybe<IR::ASTValue> m_lhs = expr(*ast.lhs);
    if (!m_lhs.has()) {
        ret = Maybe<IR::ASTValue>();
        return;
    }

    IR::ASTValue lhs = m_lhs.get();

    if (!dynamic_cast<IR::BoolType const *>(&lhs.type())) {
        // ERR_LHS_UNSUPPORTED_OP(lhs, ast.op); TODO: fix this
        ret = Maybe<IR::ASTValue>();
        return;
    }

    NNPtr<IR::Block> skip = ir_builder->fun().add_block("shortcircuit_skip");
    NNPtr<IR::Block> checkboth = ir_builder->fun().add_block("shortcircuit_checkboth");
    NNPtr<IR::Block> after = ir_builder->fun().add_block("shortcircuit_after");

    bool value_if_skipped;

    switch (ast.op.value) {
        case ASTNS::ShortCircuitOperator::DOUBLEPIPE:
            // jump to skip when true
            ir_builder->cur_block()->branch(std::make_unique<IR::Instrs::CondBr>(lhs, skip, checkboth));
            value_if_skipped = true;
            break;
        case ASTNS::ShortCircuitOperator::DOUBLEAMPER:
            // jump to skip when false
            ir_builder->cur_block()->branch(std::make_unique<IR::Instrs::CondBr>(lhs, checkboth, skip));
            value_if_skipped = false;
            break;
    }

    ir_builder->cur_block() = checkboth;

    Maybe<IR::ASTValue> m_rhs = expr(*ast.rhs);
    if (!m_rhs.has()) {
        ret = Maybe<IR::ASTValue>();
        return;
    }

    IR::ASTValue rhs = m_rhs.get();

    if (!dynamic_cast<IR::BoolType const *>(&rhs.type())) {
        // ERR_CONFLICT_TYS_BINARY_OP(lhs, rhs, ast.op); // TODO: fix this
        ret = Maybe<IR::ASTValue>();
        return;
    }
    ir_builder->cur_block()->branch(std::make_unique<IR::Instrs::GotoBr>(after));

    ir_builder->cur_block() = skip;
    ir_builder->cur_block()->branch(std::make_unique<IR::Instrs::GotoBr>(after));

    ir_builder->cur_block() = after;
    ret = IR::ASTValue(ir_builder->cur_block()->add<IR::Instrs::Phi>(std::vector<std::pair<NNPtr<IR::Block const>, IR::ASTValue>>{std::make_pair(checkboth, rhs), std::make_pair(skip, IR::ASTValue(ir_builder->context().get_const_bool(value_if_skipped), ast))}), ast);
}

void Codegen::Helpers::ExprCodegen::visit(ASTNS::UnaryExpr &ast) {
    Maybe<IR::ASTValue> m_oper = expr(*ast.expr);
    if (!m_oper.has()) {
        ret = Maybe<IR::ASTValue>();
        return;
    }

    IR::ASTValue oper = m_oper.get();

    ret = oper.type().unary_op(ir_builder->context(), ir_builder->fun(), ir_builder->cur_block(), ast.op, oper, ast);
}

void Codegen::Helpers::ExprCodegen::visit(ASTNS::DerefExpr &ast) {
    Maybe<IR::ASTValue> m_oper = expr(*ast.expr);
    if (!m_oper.has()) {
        ret = Maybe<IR::ASTValue>();
        return;
    }

    IR::ASTValue oper = m_oper.get();

    IR::PointerType const *asptrty (dynamic_cast<IR::PointerType const *>(&oper.type()));
    if (!asptrty) {
        ERR_NO_DEREF(ast.op.span, oper);
        ret = Maybe<IR::ASTValue>();
        return;
    }

    ret = IR::ASTValue(ir_builder->cur_block()->add<IR::Instrs::DerefPtr>(oper), ast);
}
void Codegen::Helpers::ExprCodegen::visit(ASTNS::AddrofExpr &ast) {
    Maybe<IR::ASTValue> m_oper = expr(*ast.expr);
    if (!m_oper.has()) {
        ret = Maybe<IR::ASTValue>();
        return;
    }

    IR::ASTValue oper = m_oper.get();

    IR::Instrs::DerefPtr const *as_deref = dynamic_cast<IR::Instrs::DerefPtr const *>(oper.val.as_raw());
    if (!as_deref) {
        ERR_ADDROF_NOT_LVALUE(ast.op.span, oper);
        ret = Maybe<IR::ASTValue>();
        return;
    }

    if (static_cast<IR::PointerType const *>(&as_deref->ptr.type())->mut == false && ast.mut) {
        ERR_MUT_ADDROF_NONMUT_OP(ast.op.span, *as_deref);
        ret = Maybe<IR::ASTValue>();
        return;
    }

    ret = IR::ASTValue(ir_builder->cur_block()->add<IR::Instrs::Addrof>(as_deref, ast.mut), ast);
}

void Codegen::Helpers::ExprCodegen::visit(ASTNS::CallExpr &ast) {
    Maybe<IR::ASTValue> m_fun = expr(*ast.callee);
    if (!m_fun.has()) {
        ret = Maybe<IR::ASTValue>();
        return;
    }

    IR::ASTValue fun = m_fun.get();

    IR::FunctionType const *fty = dynamic_cast<IR::FunctionType const *>(&fun.type());
    if (!fty) {
        ERR_CALL_NONCALLABLE(fun, ast.oparn.span);
        ret = Maybe<IR::ASTValue>();
        return;
    }

    Codegen::Helpers::ArgVisitor av (*this, ast.args);
    std::vector<IR::ASTValue> args (av.ret);

    if (args.size() != fty->paramtys.size()) {
        ERR_WRONG_NUM_ARGS(*static_cast<IR::Function const *>(fun.val.as_raw()), *ast.callee, ast.oparn.span, args);
        ret = Maybe<IR::ASTValue>();
        return;
    }

    bool argserr = false;
    auto i = args.begin();
    auto j = fty->paramtys.begin();
    for (; i != args.end() && j != fty->paramtys.end(); ++i, ++j) {
        *i = (*j)->impl_cast(ir_builder->context(), ir_builder->fun(), ir_builder->cur_block(), *i);
        if (&i->type() != &**j) {
            ERR_INCORRECT_ARG(*i, **j);
            ret = Maybe<IR::ASTValue>();
            argserr = true;
        }
    }

    if (argserr) {
        ret = Maybe<IR::ASTValue>();
        return;
    }

    ret = IR::ASTValue(ir_builder->cur_block()->add<IR::Instrs::Call>(NNPtr<IR::Function const>(static_cast<IR::Function const *>(fun.val.as_raw())), args), ast);
}

void Codegen::Helpers::ExprCodegen::visit(ASTNS::BoolLit &ast) {
    ret = IR::ASTValue(ir_builder->context().get_const_bool(ast.val.value.val), ast);
}
void Codegen::Helpers::ExprCodegen::visit(ASTNS::FloatLit &ast) {
    ret = IR::ASTValue(ir_builder->context().get_const_float(ir_builder->context().get_generic_float_type(), ast.val.value.val), ast);
}
void Codegen::Helpers::ExprCodegen::visit(ASTNS::IntLit &ast) {
    ret = IR::ASTValue(ir_builder->context().get_const_int(ir_builder->context().get_generic_int_type(), ast.val.value.val), ast);
}
void Codegen::Helpers::ExprCodegen::visit(ASTNS::CharLit &ast) {
    ret = IR::ASTValue(ir_builder->context().get_const_char(ast.val.value.val), ast);
}
void Codegen::Helpers::ExprCodegen::visit(ASTNS::StringLit &ast) {
    report_abort_noh("string literals are not supported yet");
}
void Codegen::Helpers::ExprCodegen::visit(ASTNS::ThisExpr &ast) {
    Maybe<Local> m_loc = locals->get_local("this");
    if (m_loc.has()) {
        NNPtr<Local> local = m_loc.get();
        ret = IR::ASTValue(ir_builder->cur_block()->add<IR::Instrs::DerefPtr>(IR::ASTValue(*local->v, ast)), ast);
    } else {
        ERR_NO_THIS(ast.tok.span);
        ret = Maybe<IR::ASTValue>();
    }
}
void Codegen::Helpers::ExprCodegen::visit(ASTNS::IfExpr &ast) {
    Maybe<IR::ASTValue> m_cond = expr(*ast.cond);
    if (!m_cond.has()) {
        ret = Maybe<IR::ASTValue>();
        return;
    }
    IR::ASTValue cond = m_cond.get();

    if (!dynamic_cast<IR::BoolType const *>(&cond.type())) {
        ERR_COND_NOT_BOOL(cond);
        ret = Maybe<IR::ASTValue>();
        return;
    }

    NNPtr<IR::Block> trueb  = ir_builder->fun().add_block("if_true");
    Maybe<NNPtr<IR::Block>> falseb = ast.falses ? Maybe<NNPtr<IR::Block>>(ir_builder->fun().add_block("if_false")) : Maybe<NNPtr<IR::Block>>();
    NNPtr<IR::Block> afterb = ir_builder->fun().add_block("if_after");

    if (falseb.has())
        ir_builder->cur_block()->branch(std::make_unique<IR::Instrs::CondBr>(cond, trueb, falseb.get()));
    else
        ir_builder->cur_block()->branch(std::make_unique<IR::Instrs::CondBr>(cond, trueb, afterb));

    ir_builder->cur_block() = trueb;
    Maybe<IR::ASTValue> m_truev = expr(*ast.trues);
    if (!m_truev.has()) {
        ret = Maybe<IR::ASTValue>();
        return;
    }

    IR::ASTValue truev = m_truev.get();

    ir_builder->cur_block()->branch(std::make_unique<IR::Instrs::GotoBr>(afterb));
    trueb = ir_builder->cur_block();

    Maybe<IR::ASTValue> falsev;
    if (falseb.has()) {
        ir_builder->cur_block() = falseb.get();

        Maybe<IR::ASTValue> m_falsev = expr(*ast.falses);
        if (!m_falsev.has()) {
            ret = Maybe<IR::ASTValue>();
            return;
        }

        falsev = m_falsev;

        ir_builder->cur_block()->branch(std::make_unique<IR::Instrs::GotoBr>(afterb));
        falseb = ir_builder->cur_block();

        // try both implicit casts -- they are mostly asymmetrical so it should be fine
        truev = falsev.get().type().impl_cast(ir_builder->context(), ir_builder->fun(), ir_builder->cur_block(), truev);
        falsev = truev.type().impl_cast(ir_builder->context(), ir_builder->fun(), ir_builder->cur_block(), falsev.get());

        if (&truev.type() != &falsev.get().type()) {
            ERR_CONFL_TYS_IFEXPR(truev, falsev.get(), ast.iftok.span, ast.elsetok.get().span);
            ret = Maybe<IR::ASTValue>();
            return;
        }
    } else {
        if (!dynamic_cast<IR::VoidType const *>(&truev.type())) {
            ERR_NO_ELSE_NOT_VOID(truev, ast.iftok.span);
            ret = Maybe<IR::ASTValue>();
            return;
        }
    }

    ir_builder->cur_block() = afterb;

    if (falseb.has()) {
        ret = IR::ASTValue(afterb->add<IR::Instrs::Phi>(std::vector<std::pair<NNPtr<IR::Block const>, IR::ASTValue>>({ std::make_pair(trueb, truev), std::make_pair(falseb.get(), falsev.get()) })), ast);
    } else
        ret = IR::ASTValue(*truev.val, ast);

}
void Codegen::Helpers::ExprCodegen::visit(ASTNS::WhileExpr &ast) {
    locals->inc_scope();

    IR::Block &loop_check_cond = ir_builder->fun().add_block("loop_checkcond");
    IR::Block &loop_body = ir_builder->fun().add_block("loop_body");
    IR::Block &loop_after = ir_builder->fun().add_block("loop_after");

    ir_builder->cur_block()->branch(std::make_unique<IR::Instrs::GotoBr>(loop_check_cond));
    ir_builder->cur_block() = loop_check_cond;

    Maybe<IR::ASTValue> m_cond = expr(*ast.cond);
    if (!m_cond.has()) {
        ret = Maybe<IR::ASTValue>();
        return;
    }

    IR::ASTValue cond = m_cond.get();

    if (!dynamic_cast<IR::BoolType const *>(&cond.type())) {
        ERR_COND_NOT_BOOL(cond);
        ret = Maybe<IR::ASTValue>();
        return;
    }
    ir_builder->cur_block()->branch(std::make_unique<IR::Instrs::CondBr>(cond, loop_body, loop_after));

    ir_builder->cur_block() = loop_body;
    expr(*ast.body);

    ir_builder->cur_block()->branch(std::make_unique<IR::Instrs::GotoBr>(loop_check_cond));

    locals->dec_scope();

    ir_builder->cur_block() = loop_after;

    ret = IR::ASTValue(ir_builder->context().get_void(), ast);
}

void Codegen::Helpers::ExprCodegen::visit(ASTNS::AssignmentExpr &ast) {
    Maybe<IR::ASTValue> m_lhs = expr(*ast.target);
    Maybe<IR::ASTValue> m_rhs = expr(*ast.expr);

    if (!m_lhs.has() || !m_rhs.has()) {
        ret = Maybe<IR::ASTValue>();
        return;
    }

    IR::ASTValue lhs = m_lhs.get();
    IR::ASTValue rhs = m_rhs.get();

    IR::Instrs::DerefPtr const *target_deref = dynamic_cast<IR::Instrs::DerefPtr const *>(lhs.val.as_raw());

    if (!target_deref) {
        ERR_ASSIGN_INVALID_LHS(ast.equal.span, lhs);
        ret = Maybe<IR::ASTValue>();
        return;
    }

    if (!static_cast<IR::PointerType const *>(&target_deref->ptr.type())->mut) {
        ERR_ASSIGN_NOT_MUT(lhs, ast.equal.span, *target_deref);
        ret = Maybe<IR::ASTValue>();
        return;
    }

    NNPtr<IR::Type const> expect_type = target_deref->type();
    rhs = expect_type->impl_cast(ir_builder->context(), ir_builder->fun(), ir_builder->cur_block(), rhs);
    if (expect_type.as_raw() != &rhs.type()) {
        ERR_ASSIGN_CONFLICT_TYS(lhs, rhs, ast.equal.span);
        ret = Maybe<IR::ASTValue>();
        return;
    }

    ir_builder->cur_block()->add<IR::Instrs::Store>(target_deref->ptr, rhs, false);

    ret = rhs;
}
void Codegen::Helpers::ExprCodegen::visit(ASTNS::CastExpr &ast) {
    Maybe<IR::ASTValue> m_oper = expr(*ast.expr);
    if (!m_oper.has()) {
        ret = Maybe<IR::ASTValue>();
        return;
    }

    IR::ASTValue oper = m_oper.get();

    Maybe<IR::Type&> m_cast_to_ty = type_visitor->type(*ast.type);
    if (!m_cast_to_ty.has()) {
        return;
    }

    NNPtr<IR::Type> cast_to_ty = m_cast_to_ty.get();

    ret = cast_to_ty->cast_from(ir_builder->context(), ir_builder->fun(), ir_builder->cur_block(), oper, ast);
}

void Codegen::Helpers::ExprCodegen::visit(ASTNS::Block &ast) {
    locals->inc_scope();

    for (auto stmt = ast.stmts.begin(); stmt != ast.stmts.end(); ++stmt) {
        stmt_cg.stmt(**stmt);
    }

    ASTNS::AST &void_ast = ast.stmts.size() ? *static_cast<ASTNS::AST*>(ast.stmts[ast.stmts.size() - 1].get()) : *static_cast<ASTNS::AST*>(&ast);

    if (ast.ret)
        ret = expr(*ast.ret);
    else
        ret = IR::ASTValue(ir_builder->context().get_void(), void_ast);

    if (!stmt_cg.success)
        ret = Maybe<IR::ASTValue>();

    locals->dec_scope();
}

void Codegen::Helpers::ExprCodegen::visit(ASTNS::PathExpr &ast) {
    ret = path_visitor->resolve_value(*ast.path);
    if (ret.has())
        if (dynamic_cast<IR::Instrs::Register const *>(ret.get().val.as_raw()))
            ret = IR::ASTValue(ir_builder->cur_block()->add<IR::Instrs::DerefPtr>(ret.get()), ast);
}
void Codegen::Helpers::ExprCodegen::visit(ASTNS::FieldAccessExpr &ast) {
    Maybe<IR::ASTValue> m_op = expr(*ast.operand);
    if (!m_op.has()) {
        return;
    }

    IR::ASTValue op = m_op.get();

    std::string fieldName = ast.field.value.name;
    bool has = op.type().has_field(fieldName);
    if (!has) {
        ERR_NO_FIELD(op, ast.field.span);
        return;
    }

    int ind = op.type().get_field_index(fieldName);
    // TODO: do this
}
void Codegen::Helpers::ExprCodegen::visit(ASTNS::MethodCallExpr &ast) {
    Maybe<IR::ASTValue> m_op = expr(*ast.operand);
    if (!m_op.has()) {
        return;
    }

    IR::ASTValue op = m_op.get();

    Maybe<IR::Type::Method const> m_method = op.type().get_method(ast.method.value.name);
    if (!m_method.has()) {
        ERR_NO_METHOD(op, ast.method.span);
        return;
    }

    IR::Type::Method method = m_method.get();

    Maybe<IR::ASTValue> m_this_arg;
    if (method.this_ptr) {
        IR::Instrs::DerefPtr const *op_as_deref = dynamic_cast<IR::Instrs::DerefPtr const *>(op.val.as_raw());
        if (!op_as_deref) {
            ERR_ADDROF_NOT_LVALUE(ast.dot.span, op);
            ret = Maybe<IR::ASTValue>();
            return;
        }

        if (static_cast<IR::PointerType const *>(&op_as_deref->ptr.type())->mut == false && method.this_mut) {
            ERR_MUT_ADDROF_NONMUT_OP(ast.dot.span, *op_as_deref);
            ret = Maybe<IR::ASTValue>();
            return;
        }

        m_this_arg = Maybe<IR::ASTValue>(IR::ASTValue(ir_builder->cur_block()->add<IR::Instrs::Addrof>(op_as_deref, method.this_mut), *op.ast));
    } else
        m_this_arg = op;

    IR::ASTValue this_arg = m_this_arg.get();

    std::vector<IR::ASTValue> args { this_arg };

    Codegen::Helpers::ArgVisitor av (*this, ast.args);
    args.insert(args.end(), av.ret.begin(), av.ret.end());

    std::vector<NNPtr<IR::Type const>> &paramtys (method.fun->ty->paramtys);
    if (args.size() != paramtys.size()) {
        ERR_WRONG_NUM_ARGS(*method.fun, ast, ast.oparn.span, args);
        ret = Maybe<IR::ASTValue>();
        return;
    }

    // TODO: move this code somewhere else so that it does not have to be copied and pasted from visiting call exprs
    bool argserr = false;
    auto i = args.begin();
    auto j = paramtys.begin();
    for (; i != args.end() && j != paramtys.end(); ++i, ++j) {
        *i = (*j)->impl_cast(ir_builder->context(), ir_builder->fun(), ir_builder->cur_block(), *i);
        if (&i->type() != j->as_raw()) {
            ERR_INCORRECT_ARG(*i, **j);
            ret = Maybe<IR::ASTValue>();
            argserr = true;
        }
    }

    if (argserr) {
        ret = Maybe<IR::ASTValue>();
        return;
    }

    ret = IR::ASTValue(ir_builder->cur_block()->add<IR::Instrs::Call>(method.fun, args), ast);
}
