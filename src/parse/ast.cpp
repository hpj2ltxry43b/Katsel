// ASTCPP START

// The following code was autogenerated - see the utils/ directory
#include "parse/ast.h"
ASTNS::AdditionExpr::AdditionExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::AdditionExpr::Form::ATA) {}
void ASTNS::AdditionExpr::accept(ExprVisitor *v) { v->visitAdditionExpr(this); }
ASTNS::Args::Args(std::unique_ptr<_ARGSBASE> args, Token comma, std::unique_ptr<Expr> expr): args(std::move(args)), comma(comma), expr(std::move(expr)), form(ASTNS::Args::Form::ATA) {}
ASTNS::Args::Args(std::unique_ptr<Expr> expr): expr(std::move(expr)), form(ASTNS::Args::Form::A) {}
void ASTNS::Args::accept(_ARGSBASEVisitor *v) { v->visitArgs(this); }
ASTNS::AssignmentExpr::AssignmentExpr(std::unique_ptr<Expr> target, Token equal, std::unique_ptr<Expr> value): target(std::move(target)), equal(equal), value(std::move(value)), form(ASTNS::AssignmentExpr::Form::ATA) {}
void ASTNS::AssignmentExpr::accept(ExprVisitor *v) { v->visitAssignmentExpr(this); }
ASTNS::BinandExpr::BinandExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::BinandExpr::Form::ATA) {}
void ASTNS::BinandExpr::accept(ExprVisitor *v) { v->visitBinandExpr(this); }
ASTNS::BinnotExpr::BinnotExpr(Token op, std::unique_ptr<Expr> operand): op(op), operand(std::move(operand)), form(ASTNS::BinnotExpr::Form::TA) {}
void ASTNS::BinnotExpr::accept(ExprVisitor *v) { v->visitBinnotExpr(this); }
ASTNS::BinorExpr::BinorExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::BinorExpr::Form::ATA) {}
void ASTNS::BinorExpr::accept(ExprVisitor *v) { v->visitBinorExpr(this); }
ASTNS::BitandExpr::BitandExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::BitandExpr::Form::ATA) {}
void ASTNS::BitandExpr::accept(ExprVisitor *v) { v->visitBitandExpr(this); }
ASTNS::BitorExpr::BitorExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::BitorExpr::Form::ATA) {}
void ASTNS::BitorExpr::accept(ExprVisitor *v) { v->visitBitorExpr(this); }
ASTNS::BitshiftExpr::BitshiftExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::BitshiftExpr::Form::ATA) {}
void ASTNS::BitshiftExpr::accept(ExprVisitor *v) { v->visitBitshiftExpr(this); }
ASTNS::BitxorExpr::BitxorExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::BitxorExpr::Form::ATA) {}
void ASTNS::BitxorExpr::accept(ExprVisitor *v) { v->visitBitxorExpr(this); }
ASTNS::Block::Block(Token ocurb, std::unique_ptr<_STMTBASE> stmts, Token ccurb): ocurb(ocurb), stmts(std::move(stmts)), ccurb(ccurb), form(ASTNS::Block::Form::TAT) {}
ASTNS::Block::Block(Token ocurb, Token ccurb): ocurb(ocurb), ccurb(ccurb), form(ASTNS::Block::Form::TT) {}
void ASTNS::Block::accept(_STMTBASEVisitor *v) { v->visitBlock(this); }
ASTNS::CallExpr::CallExpr(std::unique_ptr<Expr> callee, Token oparn, std::unique_ptr<_ARGSBASE> args, Token cparn): callee(std::move(callee)), oparn(oparn), args(std::move(args)), cparn(cparn), form(ASTNS::CallExpr::Form::ATAT) {}
ASTNS::CallExpr::CallExpr(std::unique_ptr<Expr> callee, Token oparn, Token cparn): callee(std::move(callee)), oparn(oparn), cparn(cparn), form(ASTNS::CallExpr::Form::ATT) {}
void ASTNS::CallExpr::accept(ExprVisitor *v) { v->visitCallExpr(this); }
ASTNS::CompeqExpr::CompeqExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::CompeqExpr::Form::ATA) {}
void ASTNS::CompeqExpr::accept(ExprVisitor *v) { v->visitCompeqExpr(this); }
ASTNS::ComplgtExpr::ComplgtExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::ComplgtExpr::Form::ATA) {}
void ASTNS::ComplgtExpr::accept(ExprVisitor *v) { v->visitComplgtExpr(this); }
void ASTNS::Decl::accept(_DECLBASEVisitor *v) { v->visitDecl(this); }
ASTNS::Decls::Decls(std::unique_ptr<_DECLBASE> decls, std::unique_ptr<_DECLBASE> decl): decls(std::move(decls)), decl(std::move(decl)), form(ASTNS::Decls::Form::AA) {}
void ASTNS::Decls::accept(_DECLBASEVisitor *v) { v->visitDecls(this); }
ASTNS::EmptyStmt::EmptyStmt(Token semi): semi(semi), form(ASTNS::EmptyStmt::Form::T) {}
void ASTNS::EmptyStmt::accept(_STMTBASEVisitor *v) { v->visitEmptyStmt(this); }
ASTNS::ExprStmt::ExprStmt(std::unique_ptr<Expr> expr, Token semi): expr(std::move(expr)), semi(semi), form(ASTNS::ExprStmt::Form::AT) {}
void ASTNS::ExprStmt::accept(_STMTBASEVisitor *v) { v->visitExprStmt(this); }
void ASTNS::Expression::accept(ExprVisitor *v) { v->visitExpression(this); }
ASTNS::Function::Function(Token fun, std::unique_ptr<_TYPEBASE> retty, Token name, Token oparn, Token cparn, std::unique_ptr<_STMTBASE> body): fun(fun), retty(std::move(retty)), name(name), oparn(oparn), cparn(cparn), body(std::move(body)), form(ASTNS::Function::Form::TATTTA) {}
ASTNS::Function::Function(Token fun, std::unique_ptr<_TYPEBASE> retty, Token name, Token oparn, std::unique_ptr<_PLISTBASE> paramlist, Token cparn, std::unique_ptr<_STMTBASE> body): fun(fun), retty(std::move(retty)), name(name), oparn(oparn), paramlist(std::move(paramlist)), cparn(cparn), body(std::move(body)), form(ASTNS::Function::Form::TATTATA) {}
void ASTNS::Function::accept(_DECLBASEVisitor *v) { v->visitFunction(this); }
ASTNS::MultExpr::MultExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)), form(ASTNS::MultExpr::Form::ATA) {}
void ASTNS::MultExpr::accept(ExprVisitor *v) { v->visitMultExpr(this); }
ASTNS::ParamList::ParamList(std::unique_ptr<_PLISTBASE> plist, Token comma, std::unique_ptr<_TYPEBASE> type, Token name): plist(std::move(plist)), comma(comma), type(std::move(type)), name(name), form(ASTNS::ParamList::Form::ATAT) {}
ASTNS::ParamList::ParamList(std::unique_ptr<_TYPEBASE> type, Token name): type(std::move(type)), name(name), form(ASTNS::ParamList::Form::AT) {}
void ASTNS::ParamList::accept(_PLISTBASEVisitor *v) { v->visitParamList(this); }
ASTNS::PrimaryExpr::PrimaryExpr(Token value): value(value), form(ASTNS::PrimaryExpr::Form::T) {}
ASTNS::PrimaryExpr::PrimaryExpr(Token oparn, std::unique_ptr<Expr> expr, Token cparn): oparn(oparn), expr(std::move(expr)), cparn(cparn), form(ASTNS::PrimaryExpr::Form::TAT) {}
void ASTNS::PrimaryExpr::accept(ExprVisitor *v) { v->visitPrimaryExpr(this); }
ASTNS::RetStmt::RetStmt(Token ret, std::unique_ptr<Expr> expr, Token semi): ret(ret), expr(std::move(expr)), semi(semi), form(ASTNS::RetStmt::Form::TAT) {}
void ASTNS::RetStmt::accept(_STMTBASEVisitor *v) { v->visitRetStmt(this); }
void ASTNS::Stmt::accept(_STMTBASEVisitor *v) { v->visitStmt(this); }
ASTNS::Stmts::Stmts(std::unique_ptr<_STMTBASE> stmts, std::unique_ptr<_STMTBASE> stmt): stmts(std::move(stmts)), stmt(std::move(stmt)), form(ASTNS::Stmts::Form::AA) {}
void ASTNS::Stmts::accept(_STMTBASEVisitor *v) { v->visitStmts(this); }
ASTNS::TernaryExpr::TernaryExpr(std::unique_ptr<Expr> cond, Token quest, std::unique_ptr<Expr> trues, Token colon, std::unique_ptr<Expr> falses): cond(std::move(cond)), quest(quest), trues(std::move(trues)), colon(colon), falses(std::move(falses)), form(ASTNS::TernaryExpr::Form::ATATA) {}
void ASTNS::TernaryExpr::accept(ExprVisitor *v) { v->visitTernaryExpr(this); }
ASTNS::Type::Type(Token type): type(type), form(ASTNS::Type::Form::T) {}
void ASTNS::Type::accept(_TYPEBASEVisitor *v) { v->visitType(this); }
ASTNS::UnaryExpr::UnaryExpr(Token op, std::unique_ptr<Expr> operand): op(op), operand(std::move(operand)), form(ASTNS::UnaryExpr::Form::TA) {}
void ASTNS::UnaryExpr::accept(ExprVisitor *v) { v->visitUnaryExpr(this); }
ASTNS::VarStmt::VarStmt(Token var, std::unique_ptr<_TYPEBASE> type, std::unique_ptr<_VSTMTIS> assignments, Token semi): var(var), type(std::move(type)), assignments(std::move(assignments)), semi(semi), form(ASTNS::VarStmt::Form::TAAT) {}
void ASTNS::VarStmt::accept(_STMTBASEVisitor *v) { v->visitVarStmt(this); }
ASTNS::VarStmtItem::VarStmtItem(Token name, Token equal, std::unique_ptr<Expr> expr): name(name), equal(equal), expr(std::move(expr)), form(ASTNS::VarStmtItem::Form::TTA) {}
ASTNS::VarStmtItem::VarStmtItem(Token name): name(name), form(ASTNS::VarStmtItem::Form::T) {}
void ASTNS::VarStmtItem::accept(_VSTMTIVisitor *v) { v->visitVarStmtItem(this); }
ASTNS::VarStmtItems::VarStmtItems(std::unique_ptr<_VSTMTIS> items, Token comma, std::unique_ptr<_VSTMTI> item): items(std::move(items)), comma(comma), item(std::move(item)), form(ASTNS::VarStmtItems::Form::ATA) {}
ASTNS::VarStmtItems::VarStmtItems(std::unique_ptr<_VSTMTI> _): _(std::move(_)), form(ASTNS::VarStmtItems::Form::A) {}
void ASTNS::VarStmtItems::accept(_VSTMTISVisitor *v) { v->visitVarStmtItems(this); }
// This code was autogenerated - see the utils/ directory

// ASTCPP END
