// ASTCPP START

// The following code was autogenerated - see the utils/ directory
#include "parse/ast.h"
ASTNS::AdditionExpr::AdditionExpr(std::unique_ptr<ExprB> lhs, Token op, std::unique_ptr<ExprB> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::AdditionExpr::Form::ATA) {}
void ASTNS::AdditionExpr::accept(ExprBVisitor *v) { v->visitAdditionExpr(this); }
ASTNS::Arg::Arg(std::unique_ptr<ExprB> expr): expr(std::move(expr)), form(ASTNS::Arg::Form::A) {}
void ASTNS::Arg::accept(ArgBVisitor *v) { v->visitArg(this); }
ASTNS::ArgList::ArgList(std::unique_ptr<ArgB> arglist, Token comma, std::unique_ptr<ArgB> arg): arglist(std::move(arglist)), comma(comma), arg(std::move(arg)), form(ASTNS::ArgList::Form::ATA) {}
void ASTNS::ArgList::accept(ArgBVisitor *v) { v->visitArgList(this); }
ASTNS::AssignmentExpr::AssignmentExpr(std::unique_ptr<ExprB> target, Token equal, std::unique_ptr<ExprB> value): target(std::move(target)), equal(equal), value(std::move(value)), form(ASTNS::AssignmentExpr::Form::ATA) {}
void ASTNS::AssignmentExpr::accept(ExprBVisitor *v) { v->visitAssignmentExpr(this); }
ASTNS::BinandExpr::BinandExpr(std::unique_ptr<ExprB> lhs, Token op, std::unique_ptr<ExprB> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::BinandExpr::Form::ATA) {}
void ASTNS::BinandExpr::accept(ExprBVisitor *v) { v->visitBinandExpr(this); }
ASTNS::BinnotExpr::BinnotExpr(Token op, std::unique_ptr<ExprB> operand): op(op), operand(std::move(operand)), form(ASTNS::BinnotExpr::Form::TA) {}
void ASTNS::BinnotExpr::accept(ExprBVisitor *v) { v->visitBinnotExpr(this); }
ASTNS::BinorExpr::BinorExpr(std::unique_ptr<ExprB> lhs, Token op, std::unique_ptr<ExprB> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::BinorExpr::Form::ATA) {}
void ASTNS::BinorExpr::accept(ExprBVisitor *v) { v->visitBinorExpr(this); }
ASTNS::BitandExpr::BitandExpr(std::unique_ptr<ExprB> lhs, Token op, std::unique_ptr<ExprB> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::BitandExpr::Form::ATA) {}
void ASTNS::BitandExpr::accept(ExprBVisitor *v) { v->visitBitandExpr(this); }
ASTNS::BitorExpr::BitorExpr(std::unique_ptr<ExprB> lhs, Token op, std::unique_ptr<ExprB> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::BitorExpr::Form::ATA) {}
void ASTNS::BitorExpr::accept(ExprBVisitor *v) { v->visitBitorExpr(this); }
ASTNS::BitshiftExpr::BitshiftExpr(std::unique_ptr<ExprB> lhs, Token op, std::unique_ptr<ExprB> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::BitshiftExpr::Form::ATA) {}
void ASTNS::BitshiftExpr::accept(ExprBVisitor *v) { v->visitBitshiftExpr(this); }
ASTNS::BitxorExpr::BitxorExpr(std::unique_ptr<ExprB> lhs, Token op, std::unique_ptr<ExprB> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::BitxorExpr::Form::ATA) {}
void ASTNS::BitxorExpr::accept(ExprBVisitor *v) { v->visitBitxorExpr(this); }
ASTNS::Block::Block(Token ocurb, std::unique_ptr<StmtB> stmts, Token ccurb): ocurb(ocurb), stmts(std::move(stmts)), ccurb(ccurb), form(ASTNS::Block::Form::TAT) {}
ASTNS::Block::Block(Token ocurb, Token ccurb): ocurb(ocurb), ccurb(ccurb), form(ASTNS::Block::Form::TT) {}
void ASTNS::Block::accept(StmtBVisitor *v) { v->visitBlock(this); }
ASTNS::BuiltinTypeNoVoid::BuiltinTypeNoVoid(Token type): type(type), form(ASTNS::BuiltinTypeNoVoid::Form::T) {}
void ASTNS::BuiltinTypeNoVoid::accept(TypeBVisitor *v) { v->visitBuiltinTypeNoVoid(this); }
ASTNS::BuiltinTypeVoid::BuiltinTypeVoid(Token type): type(type), form(ASTNS::BuiltinTypeVoid::Form::T) {}
void ASTNS::BuiltinTypeVoid::accept(TypeBVisitor *v) { v->visitBuiltinTypeVoid(this); }
ASTNS::CallExpr::CallExpr(std::unique_ptr<ExprB> callee, Token oparn, std::unique_ptr<ArgB> args, Token cparn): callee(std::move(callee)), oparn(oparn), args(std::move(args)), cparn(cparn), form(ASTNS::CallExpr::Form::ATAT) {}
ASTNS::CallExpr::CallExpr(std::unique_ptr<ExprB> callee, Token oparn, Token cparn): callee(std::move(callee)), oparn(oparn), cparn(cparn), form(ASTNS::CallExpr::Form::ATT) {}
void ASTNS::CallExpr::accept(ExprBVisitor *v) { v->visitCallExpr(this); }
ASTNS::CompeqExpr::CompeqExpr(std::unique_ptr<ExprB> lhs, Token op, std::unique_ptr<ExprB> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::CompeqExpr::Form::ATA) {}
void ASTNS::CompeqExpr::accept(ExprBVisitor *v) { v->visitCompeqExpr(this); }
ASTNS::ComplgtExpr::ComplgtExpr(std::unique_ptr<ExprB> lhs, Token op, std::unique_ptr<ExprB> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::ComplgtExpr::Form::ATA) {}
void ASTNS::ComplgtExpr::accept(ExprBVisitor *v) { v->visitComplgtExpr(this); }
ASTNS::DeclList::DeclList(std::unique_ptr<DeclB> decllist, std::unique_ptr<DeclB> decl): decllist(std::move(decllist)), decl(std::move(decl)), form(ASTNS::DeclList::Form::AA) {}
void ASTNS::DeclList::accept(DeclBVisitor *v) { v->visitDeclList(this); }
ASTNS::EmptyStmt::EmptyStmt(Token semi): semi(semi), form(ASTNS::EmptyStmt::Form::T) {}
void ASTNS::EmptyStmt::accept(StmtBVisitor *v) { v->visitEmptyStmt(this); }
ASTNS::ExprStmt::ExprStmt(std::unique_ptr<ExprB> expr, Token semi): expr(std::move(expr)), semi(semi), form(ASTNS::ExprStmt::Form::AT) {}
void ASTNS::ExprStmt::accept(StmtBVisitor *v) { v->visitExprStmt(this); }
ASTNS::Function::Function(Token fun, std::unique_ptr<TypeB> retty, Token name, Token oparn, Token cparn, std::unique_ptr<StmtB> body): fun(fun), retty(std::move(retty)), name(name), oparn(oparn), cparn(cparn), body(std::move(body)), form(ASTNS::Function::Form::TATTTA) {}
ASTNS::Function::Function(Token fun, std::unique_ptr<TypeB> retty, Token name, Token oparn, std::unique_ptr<PListB> paramlist, Token cparn, std::unique_ptr<StmtB> body): fun(fun), retty(std::move(retty)), name(name), oparn(oparn), paramlist(std::move(paramlist)), cparn(cparn), body(std::move(body)), form(ASTNS::Function::Form::TATTATA) {}
void ASTNS::Function::accept(DeclBVisitor *v) { v->visitFunction(this); }
ASTNS::MultExpr::MultExpr(std::unique_ptr<ExprB> lhs, Token op, std::unique_ptr<ExprB> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::MultExpr::Form::ATA) {}
void ASTNS::MultExpr::accept(ExprBVisitor *v) { v->visitMultExpr(this); }
ASTNS::Param::Param(std::unique_ptr<TypeB> type, Token name): type(std::move(type)), name(name), form(ASTNS::Param::Form::AT) {}
void ASTNS::Param::accept(PListBVisitor *v) { v->visitParam(this); }
ASTNS::ParamList::ParamList(std::unique_ptr<PListB> paramlist, Token comma, std::unique_ptr<PListB> param): paramlist(std::move(paramlist)), comma(comma), param(std::move(param)), form(ASTNS::ParamList::Form::ATA) {}
void ASTNS::ParamList::accept(PListBVisitor *v) { v->visitParamList(this); }
ASTNS::PrimaryExpr::PrimaryExpr(Token value): value(value), form(ASTNS::PrimaryExpr::Form::T) {}
ASTNS::PrimaryExpr::PrimaryExpr(Token oparn, std::unique_ptr<ExprB> expr, Token cparn): oparn(oparn), expr(std::move(expr)), cparn(cparn), form(ASTNS::PrimaryExpr::Form::TAT) {}
void ASTNS::PrimaryExpr::accept(ExprBVisitor *v) { v->visitPrimaryExpr(this); }
ASTNS::RetStmt::RetStmt(Token ret, std::unique_ptr<ExprB> expr, Token semi): ret(ret), expr(std::move(expr)), semi(semi), form(ASTNS::RetStmt::Form::TAT) {}
void ASTNS::RetStmt::accept(StmtBVisitor *v) { v->visitRetStmt(this); }
ASTNS::StmtList::StmtList(std::unique_ptr<StmtB> stmtlist, std::unique_ptr<StmtB> stmt): stmtlist(std::move(stmtlist)), stmt(std::move(stmt)), form(ASTNS::StmtList::Form::AA) {}
void ASTNS::StmtList::accept(StmtBVisitor *v) { v->visitStmtList(this); }
ASTNS::TernaryExpr::TernaryExpr(std::unique_ptr<ExprB> cond, Token quest, std::unique_ptr<ExprB> trues, Token colon, std::unique_ptr<ExprB> falses): cond(std::move(cond)), quest(quest), trues(std::move(trues)), colon(colon), falses(std::move(falses)), form(ASTNS::TernaryExpr::Form::ATATA) {}
void ASTNS::TernaryExpr::accept(ExprBVisitor *v) { v->visitTernaryExpr(this); }
ASTNS::UnaryExpr::UnaryExpr(Token op, std::unique_ptr<ExprB> operand): op(op), operand(std::move(operand)), form(ASTNS::UnaryExpr::Form::TA) {}
void ASTNS::UnaryExpr::accept(ExprBVisitor *v) { v->visitUnaryExpr(this); }
ASTNS::VarStmt::VarStmt(Token var, std::unique_ptr<TypeB> type, std::unique_ptr<VStmtIB> assignments, Token semi): var(var), type(std::move(type)), assignments(std::move(assignments)), semi(semi), form(ASTNS::VarStmt::Form::TAAT) {}
void ASTNS::VarStmt::accept(StmtBVisitor *v) { v->visitVarStmt(this); }
ASTNS::VarStmtItem::VarStmtItem(Token name, Token equal, std::unique_ptr<ExprB> expr): name(name), equal(equal), expr(std::move(expr)), form(ASTNS::VarStmtItem::Form::TTA) {}
ASTNS::VarStmtItem::VarStmtItem(Token name): name(name), form(ASTNS::VarStmtItem::Form::T) {}
void ASTNS::VarStmtItem::accept(VStmtIBVisitor *v) { v->visitVarStmtItem(this); }
ASTNS::VarStmtItemList::VarStmtItemList(std::unique_ptr<VStmtIB> varstmtitemlist, Token comma, std::unique_ptr<VStmtIB> varstmtitem): varstmtitemlist(std::move(varstmtitemlist)), comma(comma), varstmtitem(std::move(varstmtitem)), form(ASTNS::VarStmtItemList::Form::ATA) {}
void ASTNS::VarStmtItemList::accept(VStmtIBVisitor *v) { v->visitVarStmtItemList(this); }
// This code was autogenerated - see the utils/ directory

// ASTCPP END
