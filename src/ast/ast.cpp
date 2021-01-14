#include "ast/ast.h"
// ASTCPP START
// The following code was autogenerated - see the utils/ directory
ASTNS::AST::AST(File const &file): file(file) {}
ASTNS::CUB::CUB(File const &file): AST(file) {}
ASTNS::Decl::Decl(File const &file): AST(file) {}
ASTNS::ImplMember::ImplMember(File const &file): AST(file) {}
ASTNS::Stmt::Stmt(File const &file): AST(file) {}
ASTNS::Expr::Expr(File const &file): AST(file) {}
ASTNS::Type::Type(File const &file): AST(file) {}
ASTNS::ArgB::ArgB(File const &file): AST(file) {}
ASTNS::ParamB::ParamB(File const &file): AST(file) {}
ASTNS::VStmtIB::VStmtIB(File const &file): AST(file) {}
ASTNS::PathB::PathB(File const &file): AST(file) {}
ASTNS::ListB::ListB(File const &file): AST(file) {}
ASTNS::DeclList::DeclList(File const &file, Location start, Location end, std::vector<std::unique_ptr<Decl>> decls): ListB(file), _start(start), _end(end), decls(std::move(decls)) {}
void ASTNS::DeclList::accept(ASTNS::ListB::Visitor *v) { v->visitDeclList(this); }
Location const & ASTNS::DeclList::start() { return _start; }
Location const & ASTNS::DeclList::end() { return _end; }
ASTNS::StmtList::StmtList(File const &file, Location start, Location end, std::vector<std::unique_ptr<Stmt>> stmts): ListB(file), _start(start), _end(end), stmts(std::move(stmts)) {}
void ASTNS::StmtList::accept(ASTNS::ListB::Visitor *v) { v->visitStmtList(this); }
Location const & ASTNS::StmtList::start() { return _start; }
Location const & ASTNS::StmtList::end() { return _end; }
ASTNS::ParamList::ParamList(File const &file, Location start, Location end, std::vector<std::unique_ptr<ParamB>> params): ListB(file), _start(start), _end(end), params(std::move(params)) {}
void ASTNS::ParamList::accept(ASTNS::ListB::Visitor *v) { v->visitParamList(this); }
Location const & ASTNS::ParamList::start() { return _start; }
Location const & ASTNS::ParamList::end() { return _end; }
ASTNS::ArgList::ArgList(File const &file, Location start, Location end, std::vector<std::unique_ptr<Arg>> args): ListB(file), _start(start), _end(end), args(std::move(args)) {}
void ASTNS::ArgList::accept(ASTNS::ListB::Visitor *v) { v->visitArgList(this); }
Location const & ASTNS::ArgList::start() { return _start; }
Location const & ASTNS::ArgList::end() { return _end; }
ASTNS::VarStmtItemList::VarStmtItemList(File const &file, Location start, Location end, std::vector<std::unique_ptr<VarStmtItem>> items): ListB(file), _start(start), _end(end), items(std::move(items)) {}
void ASTNS::VarStmtItemList::accept(ASTNS::ListB::Visitor *v) { v->visitVarStmtItemList(this); }
Location const & ASTNS::VarStmtItemList::start() { return _start; }
Location const & ASTNS::VarStmtItemList::end() { return _end; }
ASTNS::ImplMemberList::ImplMemberList(File const &file, Location start, Location end, std::vector<std::unique_ptr<ImplMember>> members): ListB(file), _start(start), _end(end), members(std::move(members)) {}
void ASTNS::ImplMemberList::accept(ASTNS::ListB::Visitor *v) { v->visitImplMemberList(this); }
Location const & ASTNS::ImplMemberList::start() { return _start; }
Location const & ASTNS::ImplMemberList::end() { return _end; }
ASTNS::PureLocationB::PureLocationB(File const &file): AST(file) {}
ASTNS::PureLocation::PureLocation(File const &file, Location start, Location end, int dummy): PureLocationB(file), _start(start), _end(end), dummy(std::move(dummy)) {}
void ASTNS::PureLocation::accept(ASTNS::PureLocationB::Visitor *v) { v->visitPureLocation(this); }
Location const & ASTNS::PureLocation::start() { return _start; }
Location const & ASTNS::PureLocation::end() { return _end; }
ASTNS::ImplicitDecl::ImplicitDecl(File const &file, Location start, Location end, int dummy): Decl(file), _start(start), _end(end), dummy(std::move(dummy)) {}
void ASTNS::ImplicitDecl::accept(ASTNS::Decl::Visitor *v) { v->visitImplicitDecl(this); }
Location const & ASTNS::ImplicitDecl::start() { return _start; }
Location const & ASTNS::ImplicitDecl::end() { return _end; }
ASTNS::CU::CU(File const &file, Location start, Location end, std::vector<std::unique_ptr<Decl>> decls): CUB(file), _start(start), _end(end), decls(std::move(decls)) {}
void ASTNS::CU::accept(ASTNS::CUB::Visitor *v) { v->visitCU(this); }
Location const & ASTNS::CU::start() { return _start; }
Location const & ASTNS::CU::end() { return _end; }
ASTNS::ImplDecl::ImplDecl(File const &file, Location start, Location end, std::unique_ptr<Type> implFor, std::vector<std::unique_ptr<ImplMember>> members): Decl(file), _start(start), _end(end), implFor(std::move(implFor)), members(std::move(members)) {}
void ASTNS::ImplDecl::accept(ASTNS::Decl::Visitor *v) { v->visitImplDecl(this); }
Location const & ASTNS::ImplDecl::start() { return _start; }
Location const & ASTNS::ImplDecl::end() { return _end; }
ASTNS::FunctionDecl::FunctionDecl(File const &file, Location start, Location end, std::unique_ptr<Type> retty, Token name, std::vector<std::unique_ptr<ParamB>> params, std::unique_ptr<Block> body): Decl(file), _start(start), _end(end), retty(std::move(retty)), name(std::move(name)), params(std::move(params)), body(std::move(body)) {}
void ASTNS::FunctionDecl::accept(ASTNS::Decl::Visitor *v) { v->visitFunctionDecl(this); }
Location const & ASTNS::FunctionDecl::start() { return _start; }
Location const & ASTNS::FunctionDecl::end() { return _end; }
ASTNS::FunctionImplMember::FunctionImplMember(File const &file, Location start, Location end, std::unique_ptr<FunctionDecl> fun): ImplMember(file), _start(start), _end(end), fun(std::move(fun)) {}
void ASTNS::FunctionImplMember::accept(ASTNS::ImplMember::Visitor *v) { v->visitFunctionImplMember(this); }
Location const & ASTNS::FunctionImplMember::start() { return _start; }
Location const & ASTNS::FunctionImplMember::end() { return _end; }
ASTNS::VarStmt::VarStmt(File const &file, Location start, Location end, std::vector<std::unique_ptr<VarStmtItem>> items): Stmt(file), _start(start), _end(end), items(std::move(items)) {}
void ASTNS::VarStmt::accept(ASTNS::Stmt::Visitor *v) { v->visitVarStmt(this); }
Location const & ASTNS::VarStmt::start() { return _start; }
Location const & ASTNS::VarStmt::end() { return _end; }
ASTNS::VarStmtItem::VarStmtItem(File const &file, Location start, Location end, std::unique_ptr<Type> type, bool mut, Token name, Token equal, std::unique_ptr<Expr> expr): VStmtIB(file), _start(start), _end(end), type(std::move(type)), mut(std::move(mut)), name(std::move(name)), equal(std::move(equal)), expr(std::move(expr)) {}
void ASTNS::VarStmtItem::accept(ASTNS::VStmtIB::Visitor *v) { v->visitVarStmtItem(this); }
Location const & ASTNS::VarStmtItem::start() { return _start; }
Location const & ASTNS::VarStmtItem::end() { return _end; }
ASTNS::ExprStmt::ExprStmt(File const &file, Location start, Location end, std::unique_ptr<Expr> expr, bool suppress, Location dot): Stmt(file), _start(start), _end(end), expr(std::move(expr)), suppress(std::move(suppress)), dot(std::move(dot)) {}
void ASTNS::ExprStmt::accept(ASTNS::Stmt::Visitor *v) { v->visitExprStmt(this); }
Location const & ASTNS::ExprStmt::start() { return _start; }
Location const & ASTNS::ExprStmt::end() { return _end; }
ASTNS::RetStmt::RetStmt(File const &file, Location start, Location end, std::unique_ptr<Expr> expr): Stmt(file), _start(start), _end(end), expr(std::move(expr)) {}
void ASTNS::RetStmt::accept(ASTNS::Stmt::Visitor *v) { v->visitRetStmt(this); }
Location const & ASTNS::RetStmt::start() { return _start; }
Location const & ASTNS::RetStmt::end() { return _end; }
ASTNS::PathType::PathType(File const &file, Location start, Location end, std::unique_ptr<Path> path): Type(file), _start(start), _end(end), path(std::move(path)) {}
void ASTNS::PathType::accept(ASTNS::Type::Visitor *v) { v->visitPathType(this); }
Location const & ASTNS::PathType::start() { return _start; }
Location const & ASTNS::PathType::end() { return _end; }
ASTNS::PointerType::PointerType(File const &file, Location start, Location end, bool mut, std::unique_ptr<Type> type): Type(file), _start(start), _end(end), mut(std::move(mut)), type(std::move(type)) {}
void ASTNS::PointerType::accept(ASTNS::Type::Visitor *v) { v->visitPointerType(this); }
Location const & ASTNS::PointerType::start() { return _start; }
Location const & ASTNS::PointerType::end() { return _end; }
ASTNS::ThisType::ThisType(File const &file, Location start, Location end, Token th): Type(file), _start(start), _end(end), th(std::move(th)) {}
void ASTNS::ThisType::accept(ASTNS::Type::Visitor *v) { v->visitThisType(this); }
Location const & ASTNS::ThisType::start() { return _start; }
Location const & ASTNS::ThisType::end() { return _end; }
ASTNS::Arg::Arg(File const &file, Location start, Location end, std::unique_ptr<Expr> expr): ArgB(file), _start(start), _end(end), expr(std::move(expr)) {}
void ASTNS::Arg::accept(ASTNS::ArgB::Visitor *v) { v->visitArg(this); }
Location const & ASTNS::Arg::start() { return _start; }
Location const & ASTNS::Arg::end() { return _end; }
ASTNS::Param::Param(File const &file, Location start, Location end, std::unique_ptr<Type> type, Token name, bool mut): ParamB(file), _start(start), _end(end), type(std::move(type)), name(std::move(name)), mut(std::move(mut)) {}
void ASTNS::Param::accept(ASTNS::ParamB::Visitor *v) { v->visitParam(this); }
Location const & ASTNS::Param::start() { return _start; }
Location const & ASTNS::Param::end() { return _end; }
ASTNS::ThisParam::ThisParam(File const &file, Location start, Location end, bool ptr, bool mut): ParamB(file), _start(start), _end(end), ptr(std::move(ptr)), mut(std::move(mut)) {}
void ASTNS::ThisParam::accept(ASTNS::ParamB::Visitor *v) { v->visitThisParam(this); }
Location const & ASTNS::ThisParam::start() { return _start; }
Location const & ASTNS::ThisParam::end() { return _end; }
ASTNS::Block::Block(File const &file, Location start, Location end, std::vector<std::unique_ptr<Stmt>> stmts): Expr(file), _start(start), _end(end), stmts(std::move(stmts)) {}
void ASTNS::Block::accept(ASTNS::Expr::Visitor *v) { v->visitBlock(this); }
Location const & ASTNS::Block::start() { return _start; }
Location const & ASTNS::Block::end() { return _end; }
ASTNS::IfExpr::IfExpr(File const &file, Location start, Location end, Token iftok, Token elsetok, std::unique_ptr<Expr> cond, std::unique_ptr<Expr> trues, std::unique_ptr<Expr> falses): Expr(file), _start(start), _end(end), iftok(std::move(iftok)), elsetok(std::move(elsetok)), cond(std::move(cond)), trues(std::move(trues)), falses(std::move(falses)) {}
void ASTNS::IfExpr::accept(ASTNS::Expr::Visitor *v) { v->visitIfExpr(this); }
Location const & ASTNS::IfExpr::start() { return _start; }
Location const & ASTNS::IfExpr::end() { return _end; }
ASTNS::WhileExpr::WhileExpr(File const &file, Location start, Location end, std::unique_ptr<Expr> cond, std::unique_ptr<Expr> body): Expr(file), _start(start), _end(end), cond(std::move(cond)), body(std::move(body)) {}
void ASTNS::WhileExpr::accept(ASTNS::Expr::Visitor *v) { v->visitWhileExpr(this); }
Location const & ASTNS::WhileExpr::start() { return _start; }
Location const & ASTNS::WhileExpr::end() { return _end; }
ASTNS::AssignmentExpr::AssignmentExpr(File const &file, Location start, Location end, std::unique_ptr<Expr> target, Token equal, std::unique_ptr<Expr> expr): Expr(file), _start(start), _end(end), target(std::move(target)), equal(std::move(equal)), expr(std::move(expr)) {}
void ASTNS::AssignmentExpr::accept(ASTNS::Expr::Visitor *v) { v->visitAssignmentExpr(this); }
Location const & ASTNS::AssignmentExpr::start() { return _start; }
Location const & ASTNS::AssignmentExpr::end() { return _end; }
ASTNS::ShortCircuitExpr::ShortCircuitExpr(File const &file, Location start, Location end, std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs): Expr(file), _start(start), _end(end), lhs(std::move(lhs)), op(std::move(op)), rhs(std::move(rhs)) {}
void ASTNS::ShortCircuitExpr::accept(ASTNS::Expr::Visitor *v) { v->visitShortCircuitExpr(this); }
Location const & ASTNS::ShortCircuitExpr::start() { return _start; }
Location const & ASTNS::ShortCircuitExpr::end() { return _end; }
ASTNS::BinaryExpr::BinaryExpr(File const &file, Location start, Location end, std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs): Expr(file), _start(start), _end(end), lhs(std::move(lhs)), op(std::move(op)), rhs(std::move(rhs)) {}
void ASTNS::BinaryExpr::accept(ASTNS::Expr::Visitor *v) { v->visitBinaryExpr(this); }
Location const & ASTNS::BinaryExpr::start() { return _start; }
Location const & ASTNS::BinaryExpr::end() { return _end; }
ASTNS::CastExpr::CastExpr(File const &file, Location start, Location end, std::unique_ptr<Type> type, std::unique_ptr<Expr> expr): Expr(file), _start(start), _end(end), type(std::move(type)), expr(std::move(expr)) {}
void ASTNS::CastExpr::accept(ASTNS::Expr::Visitor *v) { v->visitCastExpr(this); }
Location const & ASTNS::CastExpr::start() { return _start; }
Location const & ASTNS::CastExpr::end() { return _end; }
ASTNS::UnaryExpr::UnaryExpr(File const &file, Location start, Location end, Token op, std::unique_ptr<Expr> expr): Expr(file), _start(start), _end(end), op(std::move(op)), expr(std::move(expr)) {}
void ASTNS::UnaryExpr::accept(ASTNS::Expr::Visitor *v) { v->visitUnaryExpr(this); }
Location const & ASTNS::UnaryExpr::start() { return _start; }
Location const & ASTNS::UnaryExpr::end() { return _end; }
ASTNS::AddrofExpr::AddrofExpr(File const &file, Location start, Location end, Token op, std::unique_ptr<Expr> expr, bool mut): Expr(file), _start(start), _end(end), op(std::move(op)), expr(std::move(expr)), mut(std::move(mut)) {}
void ASTNS::AddrofExpr::accept(ASTNS::Expr::Visitor *v) { v->visitAddrofExpr(this); }
Location const & ASTNS::AddrofExpr::start() { return _start; }
Location const & ASTNS::AddrofExpr::end() { return _end; }
ASTNS::DerefExpr::DerefExpr(File const &file, Location start, Location end, Token op, std::unique_ptr<Expr> expr): Expr(file), _start(start), _end(end), op(std::move(op)), expr(std::move(expr)) {}
void ASTNS::DerefExpr::accept(ASTNS::Expr::Visitor *v) { v->visitDerefExpr(this); }
Location const & ASTNS::DerefExpr::start() { return _start; }
Location const & ASTNS::DerefExpr::end() { return _end; }
ASTNS::CallExpr::CallExpr(File const &file, Location start, Location end, std::unique_ptr<Expr> callee, Token oparn, std::vector<std::unique_ptr<Arg>> args): Expr(file), _start(start), _end(end), callee(std::move(callee)), oparn(std::move(oparn)), args(std::move(args)) {}
void ASTNS::CallExpr::accept(ASTNS::Expr::Visitor *v) { v->visitCallExpr(this); }
Location const & ASTNS::CallExpr::start() { return _start; }
Location const & ASTNS::CallExpr::end() { return _end; }
ASTNS::FieldAccessExpr::FieldAccessExpr(File const &file, Location start, Location end, std::unique_ptr<Expr> operand, Token dot, Token field): Expr(file), _start(start), _end(end), operand(std::move(operand)), dot(std::move(dot)), field(std::move(field)) {}
void ASTNS::FieldAccessExpr::accept(ASTNS::Expr::Visitor *v) { v->visitFieldAccessExpr(this); }
Location const & ASTNS::FieldAccessExpr::start() { return _start; }
Location const & ASTNS::FieldAccessExpr::end() { return _end; }
ASTNS::MethodCallExpr::MethodCallExpr(File const &file, Location start, Location end, std::unique_ptr<Expr> operand, Token dot, Token method, Token oparn, std::vector<std::unique_ptr<Arg>> args): Expr(file), _start(start), _end(end), operand(std::move(operand)), dot(std::move(dot)), method(std::move(method)), oparn(std::move(oparn)), args(std::move(args)) {}
void ASTNS::MethodCallExpr::accept(ASTNS::Expr::Visitor *v) { v->visitMethodCallExpr(this); }
Location const & ASTNS::MethodCallExpr::start() { return _start; }
Location const & ASTNS::MethodCallExpr::end() { return _end; }
ASTNS::PrimaryExpr::PrimaryExpr(File const &file, Location start, Location end, Token value): Expr(file), _start(start), _end(end), value(std::move(value)) {}
void ASTNS::PrimaryExpr::accept(ASTNS::Expr::Visitor *v) { v->visitPrimaryExpr(this); }
Location const & ASTNS::PrimaryExpr::start() { return _start; }
Location const & ASTNS::PrimaryExpr::end() { return _end; }
ASTNS::PathExpr::PathExpr(File const &file, Location start, Location end, std::unique_ptr<Path> path): Expr(file), _start(start), _end(end), path(std::move(path)) {}
void ASTNS::PathExpr::accept(ASTNS::Expr::Visitor *v) { v->visitPathExpr(this); }
Location const & ASTNS::PathExpr::start() { return _start; }
Location const & ASTNS::PathExpr::end() { return _end; }
ASTNS::Path::Path(File const &file, Location start, Location end, std::vector<Token> segments): PathB(file), _start(start), _end(end), segments(std::move(segments)) {}
void ASTNS::Path::accept(ASTNS::PathB::Visitor *v) { v->visitPath(this); }
Location const & ASTNS::Path::start() { return _start; }
Location const & ASTNS::Path::end() { return _end; }
// This code was autogenerated - see the utils/ directory
// ASTCPP END
