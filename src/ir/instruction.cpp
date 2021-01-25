#include "ir/instruction.h"
#include "ir/function.h"
#include "ir/value.h"
#include "ir/type.h"
#include "ir/visitor.h"
#include "utils/assert.h"
#include "utils/format.h"
#include "codegen/context.h"

// INSTR CPP START
// The following code was autogenerated - see the utils/ directory
IR::Instrs::Store::Store(ASTValue target, ASTValue value, bool init): target(target), value(value), init(init) {
    ASSERT(dynamic_cast<PointerType const *>(&target.type()))
    ASSERT(static_cast<PointerType const *>(&target.type())->ty.as_raw() == &value.type())
    ASSERT(init || static_cast<PointerType const *>(&target.type())->mut)
}
void IR::Instrs::Store::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::Store::type() const { return target.type().context.get_void_type(); }

IR::Instrs::Phi::Phi(std::vector<std::pair<NNPtr<Block const>, ASTValue>> prevs): prevs(prevs) {
    ASSERT(prevs.size() > 0)
}
void IR::Instrs::Phi::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::Phi::type() const { return prevs[0].second.type(); }

IR::Instrs::Register::Register(NNPtr<ASTNS::AST> _def_ast, NNPtr<Type const> ty, bool mut): _def_ast(_def_ast), ty(ty), mut(mut) {
}
void IR::Instrs::Register::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::Register::type() const { return ty->context.get_pointer_type(mut, *ty); }
ASTNS::AST& IR::Instrs::Register::def_ast() const { return *_def_ast; }

IR::Instrs::Or::Or(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<BoolType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::Or::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::Or::type() const { return lhs.type().context.get_bool_type(); }

IR::Instrs::And::And(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<BoolType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::And::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::And::type() const { return lhs.type().context.get_bool_type(); }

IR::Instrs::Not::Not(ASTValue op): op(op) {
}
void IR::Instrs::Not::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::Not::type() const { return op.type().context.get_bool_type(); }

IR::Instrs::ICmpNE::ICmpNE(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::ICmpNE::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::ICmpNE::type() const { return lhs.type().context.get_bool_type(); }

IR::Instrs::ICmpEQ::ICmpEQ(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::ICmpEQ::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::ICmpEQ::type() const { return lhs.type().context.get_bool_type(); }

IR::Instrs::ICmpLT::ICmpLT(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::ICmpLT::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::ICmpLT::type() const { return lhs.type().context.get_bool_type(); }

IR::Instrs::ICmpGT::ICmpGT(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::ICmpGT::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::ICmpGT::type() const { return lhs.type().context.get_bool_type(); }

IR::Instrs::ICmpLE::ICmpLE(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::ICmpLE::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::ICmpLE::type() const { return lhs.type().context.get_bool_type(); }

IR::Instrs::ICmpGE::ICmpGE(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::ICmpGE::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::ICmpGE::type() const { return lhs.type().context.get_bool_type(); }

IR::Instrs::IAdd::IAdd(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType const *>(&lhs.type()) || dynamic_cast<GenericIntType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::IAdd::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::IAdd::type() const { return lhs.type(); }

IR::Instrs::ISub::ISub(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType const *>(&lhs.type()) || dynamic_cast<GenericIntType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::ISub::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::ISub::type() const { return lhs.type(); }

IR::Instrs::IMult::IMult(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType const *>(&lhs.type()) || dynamic_cast<GenericIntType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::IMult::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::IMult::type() const { return lhs.type(); }

IR::Instrs::IDiv::IDiv(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType const *>(&lhs.type()) || dynamic_cast<GenericIntType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::IDiv::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::IDiv::type() const { return lhs.type(); }

IR::Instrs::IMod::IMod(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType const *>(&lhs.type()) || dynamic_cast<GenericIntType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::IMod::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::IMod::type() const { return lhs.type(); }

IR::Instrs::INeg::INeg(ASTValue op): op(op) {
    ASSERT(dynamic_cast<IntType const *>(&op.type()) || dynamic_cast<GenericIntType const *>(&op.type()))
}
void IR::Instrs::INeg::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::INeg::type() const { return op.type(); }

IR::Instrs::FCmpNE::FCmpNE(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType const *>(&lhs.type()) || dynamic_cast<GenericFloatType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::FCmpNE::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::FCmpNE::type() const { return lhs.type().context.get_bool_type(); }

IR::Instrs::FCmpEQ::FCmpEQ(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType const *>(&lhs.type()) || dynamic_cast<GenericFloatType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::FCmpEQ::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::FCmpEQ::type() const { return lhs.type().context.get_bool_type(); }

IR::Instrs::FCmpLT::FCmpLT(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType const *>(&lhs.type()) || dynamic_cast<GenericFloatType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::FCmpLT::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::FCmpLT::type() const { return lhs.type().context.get_bool_type(); }

IR::Instrs::FCmpGT::FCmpGT(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType const *>(&lhs.type()) || dynamic_cast<GenericFloatType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::FCmpGT::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::FCmpGT::type() const { return lhs.type().context.get_bool_type(); }

IR::Instrs::FCmpLE::FCmpLE(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType const *>(&lhs.type()) || dynamic_cast<GenericFloatType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::FCmpLE::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::FCmpLE::type() const { return lhs.type().context.get_bool_type(); }

IR::Instrs::FCmpGE::FCmpGE(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType const *>(&lhs.type()) || dynamic_cast<GenericFloatType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::FCmpGE::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::FCmpGE::type() const { return lhs.type().context.get_bool_type(); }

IR::Instrs::FAdd::FAdd(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType const *>(&lhs.type()) || dynamic_cast<GenericFloatType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::FAdd::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::FAdd::type() const { return lhs.type(); }

IR::Instrs::FSub::FSub(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType const *>(&lhs.type()) || dynamic_cast<GenericFloatType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::FSub::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::FSub::type() const { return lhs.type(); }

IR::Instrs::FMult::FMult(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType const *>(&lhs.type()) || dynamic_cast<GenericFloatType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::FMult::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::FMult::type() const { return lhs.type(); }

IR::Instrs::FDiv::FDiv(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType const *>(&lhs.type()) || dynamic_cast<GenericFloatType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::FDiv::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::FDiv::type() const { return lhs.type(); }

IR::Instrs::FMod::FMod(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType const *>(&lhs.type()) || dynamic_cast<GenericFloatType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::FMod::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::FMod::type() const { return lhs.type(); }

IR::Instrs::FNeg::FNeg(ASTValue op): op(op) {
    ASSERT(dynamic_cast<FloatType const *>(&op.type()) || dynamic_cast<GenericFloatType const *>(&op.type()))
}
void IR::Instrs::FNeg::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::FNeg::type() const { return op.type(); }

IR::Instrs::BitXor::BitXor(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType const *>(&lhs.type()) || dynamic_cast<GenericIntType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::BitXor::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::BitXor::type() const { return lhs.type(); }

IR::Instrs::BitOr::BitOr(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType const *>(&lhs.type()) || dynamic_cast<GenericIntType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::BitOr::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::BitOr::type() const { return lhs.type(); }

IR::Instrs::BitAnd::BitAnd(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType const *>(&lhs.type()) || dynamic_cast<GenericIntType const *>(&lhs.type()))
    ASSERT(&lhs.type() == &rhs.type())
}
void IR::Instrs::BitAnd::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::BitAnd::type() const { return lhs.type(); }

IR::Instrs::BitNot::BitNot(ASTValue op): op(op) {
    ASSERT(dynamic_cast<IntType const *>(&op.type()) || dynamic_cast<GenericIntType const *>(&op.type()))
}
void IR::Instrs::BitNot::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::BitNot::type() const { return op.type(); }

IR::Instrs::ShiftR::ShiftR(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType const *>(&lhs.type()) || dynamic_cast<GenericIntType const *>(&lhs.type()))
    ASSERT(dynamic_cast<IntType const *>(&lhs.type()) || dynamic_cast<GenericIntType const *>(&lhs.type()))
}
void IR::Instrs::ShiftR::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::ShiftR::type() const { return lhs.type(); }

IR::Instrs::ShiftL::ShiftL(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType const *>(&lhs.type()) || dynamic_cast<GenericIntType const *>(&lhs.type()))
    ASSERT(dynamic_cast<IntType const *>(&lhs.type()) || dynamic_cast<GenericIntType const *>(&lhs.type()))
}
void IR::Instrs::ShiftL::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::ShiftL::type() const { return lhs.type(); }

IR::Instrs::NoOpCast::NoOpCast(ASTValue op, NNPtr<Type const> newt): op(op), newt(newt) {
}
void IR::Instrs::NoOpCast::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::NoOpCast::type() const { return *newt; }

IR::Instrs::IntToInt::IntToInt(ASTValue op, NNPtr<IntType const> newt): op(op), newt(newt) {
    ASSERT(dynamic_cast<IntType const *>(&op.type()) || dynamic_cast<GenericIntType const *>(&op.type()))
}
void IR::Instrs::IntToInt::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::IntToInt::type() const { return *newt; }

IR::Instrs::IntToFloat::IntToFloat(ASTValue op, NNPtr<FloatType const> newt): op(op), newt(newt) {
    ASSERT(dynamic_cast<IntType const *>(&op.type()) || dynamic_cast<GenericIntType const *>(&op.type()))
}
void IR::Instrs::IntToFloat::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::IntToFloat::type() const { return *newt; }

IR::Instrs::FloatToFloat::FloatToFloat(ASTValue op, NNPtr<FloatType const> newt): op(op), newt(newt) {
    ASSERT(dynamic_cast<FloatType const *>(&op.type()) || dynamic_cast<GenericFloatType const *>(&op.type()))
}
void IR::Instrs::FloatToFloat::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::FloatToFloat::type() const { return *newt; }

IR::Instrs::FloatToInt::FloatToInt(ASTValue op, NNPtr<IntType const> newt): op(op), newt(newt) {
    ASSERT(dynamic_cast<FloatType const *>(&op.type()) || dynamic_cast<GenericFloatType const *>(&op.type()))
}
void IR::Instrs::FloatToInt::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::FloatToInt::type() const { return *newt; }

IR::Instrs::Call::Call(NNPtr<Function const> f, std::vector<ASTValue> args): f(f), args(args) {
    ASSERT(args.size() == f->ty->paramtys.size())
}
void IR::Instrs::Call::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::Call::type() const { return *f->ty->ret; }

IR::Instrs::Addrof::Addrof(NNPtr<DerefPtr const> deref, bool mut): deref(deref), mut(mut) {
    ASSERT(static_cast<int>(mut) <= static_cast<int>(static_cast<PointerType const *>(&deref->ptr.type())->mut))
}
void IR::Instrs::Addrof::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::Addrof::type() const { return deref->type().context.get_pointer_type(mut, deref->type()); }

IR::Instrs::DerefPtr::DerefPtr(ASTValue ptr): ptr(ptr) {
    ASSERT(dynamic_cast<PointerType const *>(&ptr.type()))
}
void IR::Instrs::DerefPtr::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::DerefPtr::type() const { return *static_cast<PointerType const *>(&ptr.type())->ty; }

IR::Instrs::PtrArith::PtrArith(ASTValue ptr, ASTValue offset): ptr(ptr), offset(offset) {
    ASSERT(dynamic_cast<PointerType const *>(&ptr.type()))
    ASSERT(dynamic_cast<IntType const *>(&offset.type()) || dynamic_cast<GenericIntType const *>(&offset.type()))
}
void IR::Instrs::PtrArith::accept(InstructionVisitor &v) const { v.visit(*this); }
IR::Type const &IR::Instrs::PtrArith::type() const { return ptr.type(); }

IR::Instrs::Return::Return(ASTValue value): value(value) {
}
void IR::Instrs::Return::accept(BrVisitor &v) const { v.visit(*this); }

IR::Instrs::GotoBr::GotoBr(NNPtr<Block> to): to(to) {
}
void IR::Instrs::GotoBr::accept(BrVisitor &v) const { v.visit(*this); }

IR::Instrs::CondBr::CondBr(ASTValue v, NNPtr<Block> true_b, NNPtr<Block> false_b): v(v), true_b(true_b), false_b(false_b) {
    ASSERT(dynamic_cast<BoolType const *>(&v.type()))
}
void IR::Instrs::CondBr::accept(BrVisitor &v) const { v.visit(*this); }

// This code was autogenerated - see the utils/ directory
// INSTR CPP END
