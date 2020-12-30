#include "ir/instruction.h"
#include "ir/value.h"
#include "ir/type.h"
#include "ir/visitor.h"
#include "utils/assert.h"
#include "utils/format.h"
#include "codegen/context.h"

// INSTR CPP START
// The following code was autogenerated - see the utils/ directory
IR::Instrs::Store::Store(ASTValue target, ASTValue value): target(target), value(value) {
    ASSERT(dynamic_cast<PointerType*>(target.type()))
    ASSERT(static_cast<PointerType*>(target.type())->ty == value.type())
}
void IR::Instrs::Store::accept(InstructionVisitor *v) { v->visitStore(this); }
IR::Type* IR::Instrs::Store::type() const { return target.type()->context.getVoidType(); }
std::string IR::Instrs::Store::stringify() const { return format("%%%", this); }

IR::Instrs::Phi::Phi(std::vector<std::pair<Block*,ASTValue>> prevs): prevs(prevs) {
    ASSERT(prevs.size() > 0)
}
void IR::Instrs::Phi::accept(InstructionVisitor *v) { v->visitPhi(this); }
IR::Type* IR::Instrs::Phi::type() const { return prevs[0].second.type(); }
std::string IR::Instrs::Phi::stringify() const { return format("%%%", this); }

IR::Instrs::Register::Register(ASTNS::AST *_defAST, Type *ty): _defAST(_defAST), ty(ty) {
}
void IR::Instrs::Register::accept(InstructionVisitor *v) { v->visitRegister(this); }
IR::Type* IR::Instrs::Register::type() const { return ty->context.getPointerType(ty); }
std::string IR::Instrs::Register::stringify() const { return format("%%%", this); }
ASTNS::AST* IR::Instrs::Register::defAST() const { return _defAST; }

IR::Instrs::Or::Or(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<BoolType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::Or::accept(InstructionVisitor *v) { v->visitOr(this); }
IR::Type* IR::Instrs::Or::type() const { return lhs.type()->context.getBoolType(); }
std::string IR::Instrs::Or::stringify() const { return format("%%%", this); }

IR::Instrs::And::And(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<BoolType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::And::accept(InstructionVisitor *v) { v->visitAnd(this); }
IR::Type* IR::Instrs::And::type() const { return lhs.type()->context.getBoolType(); }
std::string IR::Instrs::And::stringify() const { return format("%%%", this); }

IR::Instrs::Not::Not(ASTValue op): op(op) {
}
void IR::Instrs::Not::accept(InstructionVisitor *v) { v->visitNot(this); }
IR::Type* IR::Instrs::Not::type() const { return op.type()->context.getBoolType(); }
std::string IR::Instrs::Not::stringify() const { return format("%%%", this); }

IR::Instrs::ICmpNE::ICmpNE(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::ICmpNE::accept(InstructionVisitor *v) { v->visitICmpNE(this); }
IR::Type* IR::Instrs::ICmpNE::type() const { return lhs.type()->context.getBoolType(); }
std::string IR::Instrs::ICmpNE::stringify() const { return format("%%%", this); }

IR::Instrs::ICmpEQ::ICmpEQ(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::ICmpEQ::accept(InstructionVisitor *v) { v->visitICmpEQ(this); }
IR::Type* IR::Instrs::ICmpEQ::type() const { return lhs.type()->context.getBoolType(); }
std::string IR::Instrs::ICmpEQ::stringify() const { return format("%%%", this); }

IR::Instrs::ICmpLT::ICmpLT(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::ICmpLT::accept(InstructionVisitor *v) { v->visitICmpLT(this); }
IR::Type* IR::Instrs::ICmpLT::type() const { return lhs.type()->context.getBoolType(); }
std::string IR::Instrs::ICmpLT::stringify() const { return format("%%%", this); }

IR::Instrs::ICmpGT::ICmpGT(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::ICmpGT::accept(InstructionVisitor *v) { v->visitICmpGT(this); }
IR::Type* IR::Instrs::ICmpGT::type() const { return lhs.type()->context.getBoolType(); }
std::string IR::Instrs::ICmpGT::stringify() const { return format("%%%", this); }

IR::Instrs::ICmpLE::ICmpLE(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::ICmpLE::accept(InstructionVisitor *v) { v->visitICmpLE(this); }
IR::Type* IR::Instrs::ICmpLE::type() const { return lhs.type()->context.getBoolType(); }
std::string IR::Instrs::ICmpLE::stringify() const { return format("%%%", this); }

IR::Instrs::ICmpGE::ICmpGE(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::ICmpGE::accept(InstructionVisitor *v) { v->visitICmpGE(this); }
IR::Type* IR::Instrs::ICmpGE::type() const { return lhs.type()->context.getBoolType(); }
std::string IR::Instrs::ICmpGE::stringify() const { return format("%%%", this); }

IR::Instrs::IAdd::IAdd(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::IAdd::accept(InstructionVisitor *v) { v->visitIAdd(this); }
IR::Type* IR::Instrs::IAdd::type() const { return lhs.type(); }
std::string IR::Instrs::IAdd::stringify() const { return format("%%%", this); }

IR::Instrs::ISub::ISub(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::ISub::accept(InstructionVisitor *v) { v->visitISub(this); }
IR::Type* IR::Instrs::ISub::type() const { return lhs.type(); }
std::string IR::Instrs::ISub::stringify() const { return format("%%%", this); }

IR::Instrs::IMult::IMult(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::IMult::accept(InstructionVisitor *v) { v->visitIMult(this); }
IR::Type* IR::Instrs::IMult::type() const { return lhs.type(); }
std::string IR::Instrs::IMult::stringify() const { return format("%%%", this); }

IR::Instrs::IDiv::IDiv(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::IDiv::accept(InstructionVisitor *v) { v->visitIDiv(this); }
IR::Type* IR::Instrs::IDiv::type() const { return lhs.type(); }
std::string IR::Instrs::IDiv::stringify() const { return format("%%%", this); }

IR::Instrs::IMod::IMod(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::IMod::accept(InstructionVisitor *v) { v->visitIMod(this); }
IR::Type* IR::Instrs::IMod::type() const { return lhs.type(); }
std::string IR::Instrs::IMod::stringify() const { return format("%%%", this); }

IR::Instrs::INeg::INeg(ASTValue op): op(op) {
    ASSERT(dynamic_cast<IntType*>(op.type()) || dynamic_cast<GenericIntType*>(op.type()))
}
void IR::Instrs::INeg::accept(InstructionVisitor *v) { v->visitINeg(this); }
IR::Type* IR::Instrs::INeg::type() const { return op.type(); }
std::string IR::Instrs::INeg::stringify() const { return format("%%%", this); }

IR::Instrs::FCmpNE::FCmpNE(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType*>(lhs.type()) || dynamic_cast<GenericFloatType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::FCmpNE::accept(InstructionVisitor *v) { v->visitFCmpNE(this); }
IR::Type* IR::Instrs::FCmpNE::type() const { return lhs.type()->context.getBoolType(); }
std::string IR::Instrs::FCmpNE::stringify() const { return format("%%%", this); }

IR::Instrs::FCmpEQ::FCmpEQ(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType*>(lhs.type()) || dynamic_cast<GenericFloatType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::FCmpEQ::accept(InstructionVisitor *v) { v->visitFCmpEQ(this); }
IR::Type* IR::Instrs::FCmpEQ::type() const { return lhs.type()->context.getBoolType(); }
std::string IR::Instrs::FCmpEQ::stringify() const { return format("%%%", this); }

IR::Instrs::FCmpLT::FCmpLT(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType*>(lhs.type()) || dynamic_cast<GenericFloatType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::FCmpLT::accept(InstructionVisitor *v) { v->visitFCmpLT(this); }
IR::Type* IR::Instrs::FCmpLT::type() const { return lhs.type()->context.getBoolType(); }
std::string IR::Instrs::FCmpLT::stringify() const { return format("%%%", this); }

IR::Instrs::FCmpGT::FCmpGT(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType*>(lhs.type()) || dynamic_cast<GenericFloatType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::FCmpGT::accept(InstructionVisitor *v) { v->visitFCmpGT(this); }
IR::Type* IR::Instrs::FCmpGT::type() const { return lhs.type()->context.getBoolType(); }
std::string IR::Instrs::FCmpGT::stringify() const { return format("%%%", this); }

IR::Instrs::FCmpLE::FCmpLE(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType*>(lhs.type()) || dynamic_cast<GenericFloatType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::FCmpLE::accept(InstructionVisitor *v) { v->visitFCmpLE(this); }
IR::Type* IR::Instrs::FCmpLE::type() const { return lhs.type()->context.getBoolType(); }
std::string IR::Instrs::FCmpLE::stringify() const { return format("%%%", this); }

IR::Instrs::FCmpGE::FCmpGE(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType*>(lhs.type()) || dynamic_cast<GenericFloatType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::FCmpGE::accept(InstructionVisitor *v) { v->visitFCmpGE(this); }
IR::Type* IR::Instrs::FCmpGE::type() const { return lhs.type()->context.getBoolType(); }
std::string IR::Instrs::FCmpGE::stringify() const { return format("%%%", this); }

IR::Instrs::FAdd::FAdd(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType*>(lhs.type()) || dynamic_cast<GenericFloatType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::FAdd::accept(InstructionVisitor *v) { v->visitFAdd(this); }
IR::Type* IR::Instrs::FAdd::type() const { return lhs.type(); }
std::string IR::Instrs::FAdd::stringify() const { return format("%%%", this); }

IR::Instrs::FSub::FSub(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType*>(lhs.type()) || dynamic_cast<GenericFloatType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::FSub::accept(InstructionVisitor *v) { v->visitFSub(this); }
IR::Type* IR::Instrs::FSub::type() const { return lhs.type(); }
std::string IR::Instrs::FSub::stringify() const { return format("%%%", this); }

IR::Instrs::FMult::FMult(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType*>(lhs.type()) || dynamic_cast<GenericFloatType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::FMult::accept(InstructionVisitor *v) { v->visitFMult(this); }
IR::Type* IR::Instrs::FMult::type() const { return lhs.type(); }
std::string IR::Instrs::FMult::stringify() const { return format("%%%", this); }

IR::Instrs::FDiv::FDiv(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType*>(lhs.type()) || dynamic_cast<GenericFloatType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::FDiv::accept(InstructionVisitor *v) { v->visitFDiv(this); }
IR::Type* IR::Instrs::FDiv::type() const { return lhs.type(); }
std::string IR::Instrs::FDiv::stringify() const { return format("%%%", this); }

IR::Instrs::FMod::FMod(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<FloatType*>(lhs.type()) || dynamic_cast<GenericFloatType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::FMod::accept(InstructionVisitor *v) { v->visitFMod(this); }
IR::Type* IR::Instrs::FMod::type() const { return lhs.type(); }
std::string IR::Instrs::FMod::stringify() const { return format("%%%", this); }

IR::Instrs::FNeg::FNeg(ASTValue op): op(op) {
    ASSERT(dynamic_cast<FloatType*>(op.type()) || dynamic_cast<GenericFloatType*>(op.type()))
}
void IR::Instrs::FNeg::accept(InstructionVisitor *v) { v->visitFNeg(this); }
IR::Type* IR::Instrs::FNeg::type() const { return op.type(); }
std::string IR::Instrs::FNeg::stringify() const { return format("%%%", this); }

IR::Instrs::BitXor::BitXor(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::BitXor::accept(InstructionVisitor *v) { v->visitBitXor(this); }
IR::Type* IR::Instrs::BitXor::type() const { return lhs.type(); }
std::string IR::Instrs::BitXor::stringify() const { return format("%%%", this); }

IR::Instrs::BitOr::BitOr(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::BitOr::accept(InstructionVisitor *v) { v->visitBitOr(this); }
IR::Type* IR::Instrs::BitOr::type() const { return lhs.type(); }
std::string IR::Instrs::BitOr::stringify() const { return format("%%%", this); }

IR::Instrs::BitAnd::BitAnd(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
    ASSERT(lhs.type() == rhs.type())
}
void IR::Instrs::BitAnd::accept(InstructionVisitor *v) { v->visitBitAnd(this); }
IR::Type* IR::Instrs::BitAnd::type() const { return lhs.type(); }
std::string IR::Instrs::BitAnd::stringify() const { return format("%%%", this); }

IR::Instrs::BitNot::BitNot(ASTValue op): op(op) {
    ASSERT(dynamic_cast<IntType*>(op.type()) || dynamic_cast<GenericIntType*>(op.type()))
}
void IR::Instrs::BitNot::accept(InstructionVisitor *v) { v->visitBitNot(this); }
IR::Type* IR::Instrs::BitNot::type() const { return op.type(); }
std::string IR::Instrs::BitNot::stringify() const { return format("%%%", this); }

IR::Instrs::ShiftR::ShiftR(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
}
void IR::Instrs::ShiftR::accept(InstructionVisitor *v) { v->visitShiftR(this); }
IR::Type* IR::Instrs::ShiftR::type() const { return lhs.type(); }
std::string IR::Instrs::ShiftR::stringify() const { return format("%%%", this); }

IR::Instrs::ShiftL::ShiftL(ASTValue lhs, ASTValue rhs): lhs(lhs), rhs(rhs) {
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
    ASSERT(dynamic_cast<IntType*>(lhs.type()) || dynamic_cast<GenericIntType*>(lhs.type()))
}
void IR::Instrs::ShiftL::accept(InstructionVisitor *v) { v->visitShiftL(this); }
IR::Type* IR::Instrs::ShiftL::type() const { return lhs.type(); }
std::string IR::Instrs::ShiftL::stringify() const { return format("%%%", this); }

IR::Instrs::NoOpCast::NoOpCast(ASTValue op, Type *newt): op(op), newt(newt) {
}
void IR::Instrs::NoOpCast::accept(InstructionVisitor *v) { v->visitNoOpCast(this); }
IR::Type* IR::Instrs::NoOpCast::type() const { return newt; }
std::string IR::Instrs::NoOpCast::stringify() const { return format("%%%", this); }

IR::Instrs::IntToInt::IntToInt(ASTValue op, IntType *newt): op(op), newt(newt) {
    ASSERT(dynamic_cast<IntType*>(op.type()) || dynamic_cast<GenericIntType*>(op.type()))
}
void IR::Instrs::IntToInt::accept(InstructionVisitor *v) { v->visitIntToInt(this); }
IR::Type* IR::Instrs::IntToInt::type() const { return newt; }
std::string IR::Instrs::IntToInt::stringify() const { return format("%%%", this); }

IR::Instrs::IntToFloat::IntToFloat(ASTValue op, FloatType *newt): op(op), newt(newt) {
    ASSERT(dynamic_cast<IntType*>(op.type()) || dynamic_cast<GenericIntType*>(op.type()))
}
void IR::Instrs::IntToFloat::accept(InstructionVisitor *v) { v->visitIntToFloat(this); }
IR::Type* IR::Instrs::IntToFloat::type() const { return newt; }
std::string IR::Instrs::IntToFloat::stringify() const { return format("%%%", this); }

IR::Instrs::FloatToFloat::FloatToFloat(ASTValue op, FloatType *newt): op(op), newt(newt) {
    ASSERT(dynamic_cast<FloatType*>(op.type()) || dynamic_cast<GenericFloatType*>(op.type()))
}
void IR::Instrs::FloatToFloat::accept(InstructionVisitor *v) { v->visitFloatToFloat(this); }
IR::Type* IR::Instrs::FloatToFloat::type() const { return newt; }
std::string IR::Instrs::FloatToFloat::stringify() const { return format("%%%", this); }

IR::Instrs::FloatToInt::FloatToInt(ASTValue op, IntType *newt): op(op), newt(newt) {
    ASSERT(dynamic_cast<FloatType*>(op.type()) || dynamic_cast<GenericFloatType*>(op.type()))
}
void IR::Instrs::FloatToInt::accept(InstructionVisitor *v) { v->visitFloatToInt(this); }
IR::Type* IR::Instrs::FloatToInt::type() const { return newt; }
std::string IR::Instrs::FloatToInt::stringify() const { return format("%%%", this); }

IR::Instrs::Call::Call(Function *f, std::vector<ASTValue> args): f(f), args(args) {
    ASSERT(args.size() == f->ty->paramtys.size())
}
void IR::Instrs::Call::accept(InstructionVisitor *v) { v->visitCall(this); }
IR::Type* IR::Instrs::Call::type() const { return f->ty->ret; }
std::string IR::Instrs::Call::stringify() const { return format("%%%", this); }

IR::Instrs::DerefPtr::DerefPtr(ASTValue ptr): ptr(ptr) {
    ASSERT(dynamic_cast<PointerType*>(ptr.type()))
}
void IR::Instrs::DerefPtr::accept(InstructionVisitor *v) { v->visitDerefPtr(this); }
IR::Type* IR::Instrs::DerefPtr::type() const { return static_cast<PointerType*>(ptr.type())->ty; }
std::string IR::Instrs::DerefPtr::stringify() const { return format("%%%", this); }

IR::Instrs::Return::Return(ASTValue value): value(value) {
}
void IR::Instrs::Return::accept(BrVisitor *v) { v->visitReturn(this); }

IR::Instrs::GotoBr::GotoBr(Block *to): to(to) {
}
void IR::Instrs::GotoBr::accept(BrVisitor *v) { v->visitGotoBr(this); }

IR::Instrs::CondBr::CondBr(ASTValue v, Block *trueB, Block *falseB): v(v), trueB(trueB), falseB(falseB) {
    ASSERT(dynamic_cast<BoolType*>(v.type()))
}
void IR::Instrs::CondBr::accept(BrVisitor *v) { v->visitCondBr(this); }

// This code was autogenerated - see the utils/ directory
// INSTR CPP END
