#include "ir/instruction.h"
#include "ir/value.h"
#include "ir/visitor.h"
#include <ostream>

// INSTR CPP START

// The following code was autogenerated - see the utils/ directory
IR::Instrs::Store::Store(Register *target, Value *value): target(target), value(value) {}
void IR::Instrs::Store::accept(InstructionVisitor *v) { v->visitStore(this); }
IR::Instrs::Or::Or(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::Or::accept(InstructionVisitor *v) { v->visitOr(this); }
IR::Instrs::And::And(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::And::accept(InstructionVisitor *v) { v->visitAnd(this); }
IR::Instrs::CmpNE::CmpNE(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::CmpNE::accept(InstructionVisitor *v) { v->visitCmpNE(this); }
IR::Instrs::CmpEQ::CmpEQ(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::CmpEQ::accept(InstructionVisitor *v) { v->visitCmpEQ(this); }
IR::Instrs::CmpLT::CmpLT(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::CmpLT::accept(InstructionVisitor *v) { v->visitCmpLT(this); }
IR::Instrs::CmpGT::CmpGT(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::CmpGT::accept(InstructionVisitor *v) { v->visitCmpGT(this); }
IR::Instrs::CmpLE::CmpLE(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::CmpLE::accept(InstructionVisitor *v) { v->visitCmpLE(this); }
IR::Instrs::CmpGE::CmpGE(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::CmpGE::accept(InstructionVisitor *v) { v->visitCmpGE(this); }
IR::Instrs::BitXor::BitXor(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::BitXor::accept(InstructionVisitor *v) { v->visitBitXor(this); }
IR::Instrs::BitOr::BitOr(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::BitOr::accept(InstructionVisitor *v) { v->visitBitOr(this); }
IR::Instrs::BitAnd::BitAnd(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::BitAnd::accept(InstructionVisitor *v) { v->visitBitAnd(this); }
IR::Instrs::BitNot::BitNot(Register *target, Value *op): target(target), op(op) {}
void IR::Instrs::BitNot::accept(InstructionVisitor *v) { v->visitBitNot(this); }
IR::Instrs::ShiftR::ShiftR(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::ShiftR::accept(InstructionVisitor *v) { v->visitShiftR(this); }
IR::Instrs::ShiftL::ShiftL(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::ShiftL::accept(InstructionVisitor *v) { v->visitShiftL(this); }
IR::Instrs::Add::Add(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::Add::accept(InstructionVisitor *v) { v->visitAdd(this); }
IR::Instrs::Sub::Sub(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::Sub::accept(InstructionVisitor *v) { v->visitSub(this); }
IR::Instrs::Mult::Mult(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::Mult::accept(InstructionVisitor *v) { v->visitMult(this); }
IR::Instrs::Div::Div(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::Div::accept(InstructionVisitor *v) { v->visitDiv(this); }
IR::Instrs::Mod::Mod(Register *target, Value *lhs, Value *rhs): target(target), lhs(lhs), rhs(rhs) {}
void IR::Instrs::Mod::accept(InstructionVisitor *v) { v->visitMod(this); }
IR::Instrs::Neg::Neg(Register *target, Value *op): target(target), op(op) {}
void IR::Instrs::Neg::accept(InstructionVisitor *v) { v->visitNeg(this); }
IR::Instrs::Trunc::Trunc(Register *target, Value *op, Type *newt): target(target), op(op), newt(newt) {}
void IR::Instrs::Trunc::accept(InstructionVisitor *v) { v->visitTrunc(this); }
IR::Instrs::Ext::Ext(Register *target, Value *op, Type *newt): target(target), op(op), newt(newt) {}
void IR::Instrs::Ext::accept(InstructionVisitor *v) { v->visitExt(this); }
IR::Instrs::IntToFloat::IntToFloat(Register *target, Value *op, Type *newt): target(target), op(op), newt(newt) {}
void IR::Instrs::IntToFloat::accept(InstructionVisitor *v) { v->visitIntToFloat(this); }
IR::Instrs::FloatToInt::FloatToInt(Register *target, Value *op, Type *newt): target(target), op(op), newt(newt) {}
void IR::Instrs::FloatToInt::accept(InstructionVisitor *v) { v->visitFloatToInt(this); }
IR::Instrs::Return::Return(Value *value): value(value) {}
void IR::Instrs::Return::accept(InstructionVisitor *v) { v->visitReturn(this); }
IR::Instrs::Call::Call(Register *reg, Function *f, std::vector<Value*> args): reg(reg), f(f), args(args) {}
void IR::Instrs::Call::accept(InstructionVisitor *v) { v->visitCall(this); }
IR::Instrs::GotoBr::GotoBr(Block *to): to(to) {}
void IR::Instrs::GotoBr::accept(BrVisitor *v) { v->visitGotoBr(this); }
IR::Instrs::CondBr::CondBr(Value *v, Block *trueB, Block *falseB): v(v), trueB(trueB), falseB(falseB) {}
void IR::Instrs::CondBr::accept(BrVisitor *v) { v->visitCondBr(this); }
// This code was autogenerated - see the utils/ directory

// INSTR CPP END
