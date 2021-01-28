#include "ast/ast.h"
// ASTCPP START
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
ASTNS::DeclList::DeclList(File const &file, Maybe<Span const> const &span, std::vector<std::unique_ptr<Decl>> decls): ListB(file), _span(span), decls(std::move(decls)) {}
void ASTNS::DeclList::accept(ASTNS::ListBVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::DeclList::span() const { return _span; }
ASTNS::StmtList::StmtList(File const &file, Maybe<Span const> const &span, std::vector<std::unique_ptr<Stmt>> stmts): ListB(file), _span(span), stmts(std::move(stmts)) {}
void ASTNS::StmtList::accept(ASTNS::ListBVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::StmtList::span() const { return _span; }
ASTNS::ParamList::ParamList(File const &file, Maybe<Span const> const &span, std::vector<std::unique_ptr<ParamB>> params): ListB(file), _span(span), params(std::move(params)) {}
void ASTNS::ParamList::accept(ASTNS::ListBVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::ParamList::span() const { return _span; }
ASTNS::ArgList::ArgList(File const &file, Maybe<Span const> const &span, std::vector<std::unique_ptr<Arg>> args): ListB(file), _span(span), args(std::move(args)) {}
void ASTNS::ArgList::accept(ASTNS::ListBVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::ArgList::span() const { return _span; }
ASTNS::VarStmtItemList::VarStmtItemList(File const &file, Maybe<Span const> const &span, std::vector<std::unique_ptr<VarStmtItem>> items): ListB(file), _span(span), items(std::move(items)) {}
void ASTNS::VarStmtItemList::accept(ASTNS::ListBVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::VarStmtItemList::span() const { return _span; }
ASTNS::ImplMemberList::ImplMemberList(File const &file, Maybe<Span const> const &span, std::vector<std::unique_ptr<ImplMember>> members): ListB(file), _span(span), members(std::move(members)) {}
void ASTNS::ImplMemberList::accept(ASTNS::ListBVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::ImplMemberList::span() const { return _span; }
ASTNS::PureLocationB::PureLocationB(File const &file): AST(file) {}
ASTNS::PureLocation::PureLocation(File const &file, Maybe<Span const> const &span, int dummy): PureLocationB(file), _span(span), dummy(std::move(dummy)) {}
void ASTNS::PureLocation::accept(ASTNS::PureLocationBVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::PureLocation::span() const { return _span; }
ASTNS::ImplicitDecl::ImplicitDecl(File const &file, Maybe<Span const> const &span, int dummy): Decl(file), _span(span), dummy(std::move(dummy)) {}
void ASTNS::ImplicitDecl::accept(ASTNS::DeclVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::ImplicitDecl::span() const { return _span; }
ASTNS::CU::CU(File const &file, Maybe<Span const> const &span, std::vector<std::unique_ptr<Decl>> decls): CUB(file), _span(span), decls(std::move(decls)) {}
void ASTNS::CU::accept(ASTNS::CUBVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::CU::span() const { return _span; }
ASTNS::ImplDecl::ImplDecl(File const &file, Maybe<Span const> const &span, std::unique_ptr<Type> impl_for, std::vector<std::unique_ptr<ImplMember>> members): Decl(file), _span(span), impl_for(std::move(impl_for)), members(std::move(members)) {}
void ASTNS::ImplDecl::accept(ASTNS::DeclVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::ImplDecl::span() const { return _span; }
ASTNS::FunctionDecl::FunctionDecl(File const &file, Maybe<Span const> const &span, std::unique_ptr<Type> retty, Located<Tokens::Identifier> name, std::vector<std::unique_ptr<ParamB>> params, std::unique_ptr<Block> body): Decl(file), _span(span), retty(std::move(retty)), name(std::move(name)), params(std::move(params)), body(std::move(body)) {}
void ASTNS::FunctionDecl::accept(ASTNS::DeclVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::FunctionDecl::span() const { return _span; }
ASTNS::FunctionImplMember::FunctionImplMember(File const &file, Maybe<Span const> const &span, std::unique_ptr<FunctionDecl> fun): ImplMember(file), _span(span), fun(std::move(fun)) {}
void ASTNS::FunctionImplMember::accept(ASTNS::ImplMemberVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::FunctionImplMember::span() const { return _span; }
ASTNS::VarStmt::VarStmt(File const &file, Maybe<Span const> const &span, std::vector<std::unique_ptr<VarStmtItem>> items): Stmt(file), _span(span), items(std::move(items)) {}
void ASTNS::VarStmt::accept(ASTNS::StmtVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::VarStmt::span() const { return _span; }
ASTNS::VarStmtItem::VarStmtItem(File const &file, Maybe<Span const> const &span, std::unique_ptr<Type> type, bool mut, Located<Tokens::Identifier> name, Maybe<Located<Tokens::Equal>> equal, std::unique_ptr<Expr> expr): VStmtIB(file), _span(span), type(std::move(type)), mut(std::move(mut)), name(std::move(name)), equal(std::move(equal)), expr(std::move(expr)) {}
void ASTNS::VarStmtItem::accept(ASTNS::VStmtIBVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::VarStmtItem::span() const { return _span; }
ASTNS::ExprStmt::ExprStmt(File const &file, Maybe<Span const> const &span, std::unique_ptr<Expr> expr, bool suppress, Maybe<Span const> dot): Stmt(file), _span(span), expr(std::move(expr)), suppress(std::move(suppress)), dot(std::move(dot)) {}
void ASTNS::ExprStmt::accept(ASTNS::StmtVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::ExprStmt::span() const { return _span; }
ASTNS::RetStmt::RetStmt(File const &file, Maybe<Span const> const &span, std::unique_ptr<Expr> expr): Stmt(file), _span(span), expr(std::move(expr)) {}
void ASTNS::RetStmt::accept(ASTNS::StmtVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::RetStmt::span() const { return _span; }
ASTNS::PathType::PathType(File const &file, Maybe<Span const> const &span, std::unique_ptr<Path> path): Type(file), _span(span), path(std::move(path)) {}
void ASTNS::PathType::accept(ASTNS::TypeVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::PathType::span() const { return _span; }
ASTNS::PointerType::PointerType(File const &file, Maybe<Span const> const &span, bool mut, std::unique_ptr<Type> type): Type(file), _span(span), mut(std::move(mut)), type(std::move(type)) {}
void ASTNS::PointerType::accept(ASTNS::TypeVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::PointerType::span() const { return _span; }
ASTNS::ThisType::ThisType(File const &file, Maybe<Span const> const &span, Located<Tokens::This> th): Type(file), _span(span), th(std::move(th)) {}
void ASTNS::ThisType::accept(ASTNS::TypeVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::ThisType::span() const { return _span; }
ASTNS::Arg::Arg(File const &file, Maybe<Span const> const &span, std::unique_ptr<Expr> expr): ArgB(file), _span(span), expr(std::move(expr)) {}
void ASTNS::Arg::accept(ASTNS::ArgBVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::Arg::span() const { return _span; }
ASTNS::Param::Param(File const &file, Maybe<Span const> const &span, std::unique_ptr<Type> type, Located<Tokens::Identifier> name, bool mut): ParamB(file), _span(span), type(std::move(type)), name(std::move(name)), mut(std::move(mut)) {}
void ASTNS::Param::accept(ASTNS::ParamBVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::Param::span() const { return _span; }
ASTNS::ThisParam::ThisParam(File const &file, Maybe<Span const> const &span, bool ptr, bool mut): ParamB(file), _span(span), ptr(std::move(ptr)), mut(std::move(mut)) {}
void ASTNS::ThisParam::accept(ASTNS::ParamBVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::ThisParam::span() const { return _span; }
ASTNS::Block::Block(File const &file, Maybe<Span const> const &span, std::vector<std::unique_ptr<Stmt>> stmts): Expr(file), _span(span), stmts(std::move(stmts)) {}
void ASTNS::Block::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::Block::span() const { return _span; }
ASTNS::IfExpr::IfExpr(File const &file, Maybe<Span const> const &span, Located<Tokens::If> iftok, Maybe<Located<Tokens::Else>> elsetok, std::unique_ptr<Expr> cond, std::unique_ptr<Expr> trues, std::unique_ptr<Expr> falses): Expr(file), _span(span), iftok(std::move(iftok)), elsetok(std::move(elsetok)), cond(std::move(cond)), trues(std::move(trues)), falses(std::move(falses)) {}
void ASTNS::IfExpr::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::IfExpr::span() const { return _span; }
ASTNS::WhileExpr::WhileExpr(File const &file, Maybe<Span const> const &span, std::unique_ptr<Expr> cond, std::unique_ptr<Expr> body): Expr(file), _span(span), cond(std::move(cond)), body(std::move(body)) {}
void ASTNS::WhileExpr::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::WhileExpr::span() const { return _span; }
ASTNS::AssignmentExpr::AssignmentExpr(File const &file, Maybe<Span const> const &span, std::unique_ptr<Expr> target, Located<AssignOperator> equal, std::unique_ptr<Expr> expr): Expr(file), _span(span), target(std::move(target)), equal(std::move(equal)), expr(std::move(expr)) {}
void ASTNS::AssignmentExpr::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::AssignmentExpr::span() const { return _span; }
ASTNS::ShortCircuitExpr::ShortCircuitExpr(File const &file, Maybe<Span const> const &span, std::unique_ptr<Expr> lhs, Located<ShortCircuitOperator> op, std::unique_ptr<Expr> rhs): Expr(file), _span(span), lhs(std::move(lhs)), op(std::move(op)), rhs(std::move(rhs)) {}
void ASTNS::ShortCircuitExpr::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::ShortCircuitExpr::span() const { return _span; }
ASTNS::BinaryExpr::BinaryExpr(File const &file, Maybe<Span const> const &span, std::unique_ptr<Expr> lhs, Located<BinaryOperator> op, std::unique_ptr<Expr> rhs): Expr(file), _span(span), lhs(std::move(lhs)), op(std::move(op)), rhs(std::move(rhs)) {}
void ASTNS::BinaryExpr::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::BinaryExpr::span() const { return _span; }
ASTNS::CastExpr::CastExpr(File const &file, Maybe<Span const> const &span, std::unique_ptr<Type> type, std::unique_ptr<Expr> expr): Expr(file), _span(span), type(std::move(type)), expr(std::move(expr)) {}
void ASTNS::CastExpr::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::CastExpr::span() const { return _span; }
ASTNS::UnaryExpr::UnaryExpr(File const &file, Maybe<Span const> const &span, Located<UnaryOperator> op, std::unique_ptr<Expr> expr): Expr(file), _span(span), op(std::move(op)), expr(std::move(expr)) {}
void ASTNS::UnaryExpr::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::UnaryExpr::span() const { return _span; }
ASTNS::AddrofExpr::AddrofExpr(File const &file, Maybe<Span const> const &span, Located<Tokens::Amper> op, std::unique_ptr<Expr> expr, bool mut): Expr(file), _span(span), op(std::move(op)), expr(std::move(expr)), mut(std::move(mut)) {}
void ASTNS::AddrofExpr::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::AddrofExpr::span() const { return _span; }
ASTNS::DerefExpr::DerefExpr(File const &file, Maybe<Span const> const &span, Located<Tokens::Star> op, std::unique_ptr<Expr> expr): Expr(file), _span(span), op(std::move(op)), expr(std::move(expr)) {}
void ASTNS::DerefExpr::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::DerefExpr::span() const { return _span; }
ASTNS::CallExpr::CallExpr(File const &file, Maybe<Span const> const &span, std::unique_ptr<Expr> callee, Located<Tokens::OParen> oparn, std::vector<std::unique_ptr<Arg>> args): Expr(file), _span(span), callee(std::move(callee)), oparn(std::move(oparn)), args(std::move(args)) {}
void ASTNS::CallExpr::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::CallExpr::span() const { return _span; }
ASTNS::FieldAccessExpr::FieldAccessExpr(File const &file, Maybe<Span const> const &span, std::unique_ptr<Expr> operand, Located<Tokens::Period> dot, Located<Tokens::Identifier> field): Expr(file), _span(span), operand(std::move(operand)), dot(std::move(dot)), field(std::move(field)) {}
void ASTNS::FieldAccessExpr::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::FieldAccessExpr::span() const { return _span; }
ASTNS::MethodCallExpr::MethodCallExpr(File const &file, Maybe<Span const> const &span, std::unique_ptr<Expr> operand, Located<Tokens::Period> dot, Located<Tokens::Identifier> method, Located<Tokens::OParen> oparn, std::vector<std::unique_ptr<Arg>> args): Expr(file), _span(span), operand(std::move(operand)), dot(std::move(dot)), method(std::move(method)), oparn(std::move(oparn)), args(std::move(args)) {}
void ASTNS::MethodCallExpr::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::MethodCallExpr::span() const { return _span; }
ASTNS::BoolLit::BoolLit(File const &file, Maybe<Span const> const &span, Located<Tokens::BoolLit> val): Expr(file), _span(span), val(std::move(val)) {}
void ASTNS::BoolLit::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::BoolLit::span() const { return _span; }
ASTNS::FloatLit::FloatLit(File const &file, Maybe<Span const> const &span, Located<Tokens::FloatLit> val): Expr(file), _span(span), val(std::move(val)) {}
void ASTNS::FloatLit::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::FloatLit::span() const { return _span; }
ASTNS::IntLit::IntLit(File const &file, Maybe<Span const> const &span, Located<Tokens::IntLit> val): Expr(file), _span(span), val(std::move(val)) {}
void ASTNS::IntLit::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::IntLit::span() const { return _span; }
ASTNS::CharLit::CharLit(File const &file, Maybe<Span const> const &span, Located<Tokens::CharLit> val): Expr(file), _span(span), val(std::move(val)) {}
void ASTNS::CharLit::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::CharLit::span() const { return _span; }
ASTNS::StringLit::StringLit(File const &file, Maybe<Span const> const &span, Located<Tokens::StringLit> val): Expr(file), _span(span), val(std::move(val)) {}
void ASTNS::StringLit::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::StringLit::span() const { return _span; }
ASTNS::ThisExpr::ThisExpr(File const &file, Maybe<Span const> const &span, Located<Tokens::This> tok): Expr(file), _span(span), tok(std::move(tok)) {}
void ASTNS::ThisExpr::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::ThisExpr::span() const { return _span; }
ASTNS::PathExpr::PathExpr(File const &file, Maybe<Span const> const &span, std::unique_ptr<Path> path): Expr(file), _span(span), path(std::move(path)) {}
void ASTNS::PathExpr::accept(ASTNS::ExprVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::PathExpr::span() const { return _span; }
ASTNS::Path::Path(File const &file, Maybe<Span const> const &span, std::vector<Located<Tokens::Identifier>> segments): PathB(file), _span(span), segments(std::move(segments)) {}
void ASTNS::Path::accept(ASTNS::PathBVisitor &v) { v.visit(*this); }
Maybe<Span const> const &ASTNS::Path::span() const { return _span; }
// ASTCPP END
