#include "ir/type.h"
#include "ir/block.h"
#include "ir/instruction.h"
#include "message/errmsgs.h"
#include "utils/format.h"
#include "utils/assert.h"

#include "codegen/codegen.h"
#include "codegen/context.h"

#include "llvm/IR/DerivedTypes.h"

IR::PointerType::PointerType(CodeGen::Context &context, ASTNS::AST const &decl_ast, bool mut, Type const &ty): Type(context), ty(ty), mut(mut), _decl_ast(decl_ast) {}
ASTNS::AST const &IR::PointerType::decl_ast() const {
    return *_decl_ast;
}

std::string IR::PointerType::name() const {
    if (mut)
        return format("*mut {}", ty->name());
    else
        return format("*{}", ty->name());
}

DERIVE_DECLSYMBOL_ITEMS_IMPL(IR::PointerType)
DERIVE_TYPE_METHOD_TABLE_IMPL(IR::PointerType)
DERIVE_TYPE_NO_FIELDS(IR::PointerType)

Maybe<IR::ASTValue> IR::PointerType::bin_op(CodeGen::Context &cgc, IR::Function &fun, NNPtr<IR::Block> &cur_block, Located<ASTNS::BinaryOperator> op, IR::ASTValue l, IR::ASTValue r, ASTNS::AST const &ast) const {
    ASSERT(&l.type() == this);

    r = cgc.get_int_type(64, true).impl_cast(cgc, fun, cur_block, r);
    if (!dynamic_cast<IntType const *>(&r.type())) {
        ERR_PTR_ARITH_RHS_NOT_NUM(l, op, r);
        return Maybe<IR::ASTValue>();
    }

    switch (op.value) {
        case ASTNS::BinaryOperator::PLUS:
            return IR::ASTValue(cur_block->add<IR::Instrs::PtrArith>(l, r), ast);
        case ASTNS::BinaryOperator::MINUS: {
                IR::ASTValue r_negated = IR::ASTValue(cur_block->add<IR::Instrs::INeg>(r), *r.ast);
                return IR::ASTValue(cur_block->add<IR::Instrs::PtrArith>(l, r_negated), ast);
            }
        case ASTNS::BinaryOperator::GREATER:
            return IR::ASTValue(cur_block->add<IR::Instrs::ICmpGT>(l, r), ast);
        case ASTNS::BinaryOperator::LESS:
            return IR::ASTValue(cur_block->add<IR::Instrs::ICmpLT>(l, r), ast);
        case ASTNS::BinaryOperator::GREATEREQUAL:
            return IR::ASTValue(cur_block->add<IR::Instrs::ICmpGE>(l, r), ast);
        case ASTNS::BinaryOperator::LESSEQUAL:
            return IR::ASTValue(cur_block->add<IR::Instrs::ICmpLE>(l, r), ast);
        case ASTNS::BinaryOperator::DOUBLEEQUAL:
            return IR::ASTValue(cur_block->add<IR::Instrs::ICmpEQ>(l, r), ast);
        case ASTNS::BinaryOperator::BANGEQUAL:
            return IR::ASTValue(cur_block->add<IR::Instrs::ICmpNE>(l, r), ast);

        default:
            ERR_LHS_UNSUPPORTED_OP(l, op);
            return Maybe<IR::ASTValue>();
    }
}
Maybe<IR::ASTValue> IR::PointerType::unary_op(CodeGen::Context &cgc, IR::Function &fun, NNPtr<IR::Block> &cur_block, Located<ASTNS::UnaryOperator> op, IR::ASTValue operand, ASTNS::AST const &ast) const {
    ASSERT(&operand.type() == this);

    ERR_UNARY_UNSUPPORTED_OP(operand, op);
    return Maybe<ASTValue>();
}
Maybe<IR::ASTValue> IR::PointerType::cast_from(CodeGen::Context &cgc, IR::Function &fun, NNPtr<IR::Block> &cur_block, IR::ASTValue v, ASTNS::AST const &ast) const {
    if (dynamic_cast<IR::PointerType const *>(&v.type())) {
        return ASTValue(cur_block->add<IR::Instrs::NoOpCast>(v, this), ast);
    }

    ERR_INVALID_CAST(ast, v, *this);
    return Maybe<ASTValue>();
}
llvm::Type& IR::PointerType::to_llvmtype(llvm::LLVMContext &con) const {
    return *llvm::PointerType::getUnqual(&ty->to_llvmtype(con));
}
IR::ASTValue IR::PointerType::impl_cast(CodeGen::Context &cgc, IR::Function &fun, NNPtr<IR::Block> &cur_block, IR::ASTValue v) const {
    return v;
}

