#include "ast/printvisitor.h"

#include <iostream>
#include <string>


template <typename T>
static void printField(ASTNS::PrintVisitor &p, std::unique_ptr<T> &ast) {
    if (ast)
        ast->accept(&p);
    else
        p.pai("nullptr\n");
}
template <typename T>
static void printField(ASTNS::PrintVisitor &p, std::vector<std::unique_ptr<T>> &v) {
    p.pai("[\n");
    ++p.indent;
    for (std::unique_ptr<T> &a : v)
        a->accept(&p);
    --p.indent;
    p.pai("]\n");
}
static void printField(ASTNS::PrintVisitor &p, Token const &t) {
    p.pai("\"");
    p.pai(t.stringify());
    p.pai("\"\n");
}
static void printField(ASTNS::PrintVisitor &p, int i) {
    p.ostream << i << '\n';
}
static void printField(ASTNS::PrintVisitor &p, std::vector<Token> &v) {
    p.pai("[");
    bool first = true;
    for (Token const &t : v) {
        if (!first)
            p.pai(", ");
        p.pai("\"");
        p.pai(t.stringify());
        p.pai("\"");

        first = false;
    }
    p.pai("]\n");
}
static void printField(ASTNS::PrintVisitor &p, Location const &l) {
    p.pai("<location>");
}

// PRINTVISITOR START
// The following code was autogenerated - see the utils/ directory
void ASTNS::PrintVisitor::visitDeclList(ASTNS::DeclList *a) {
    pai("DeclList {\n");
    ++indent;
    pai("std::vector<std::unique_ptr<Decl>> decls = ");
    printField(*this, a->decls);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitStmtList(ASTNS::StmtList *a) {
    pai("StmtList {\n");
    ++indent;
    pai("std::vector<std::unique_ptr<Stmt>> stmts = ");
    printField(*this, a->stmts);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitParamList(ASTNS::ParamList *a) {
    pai("ParamList {\n");
    ++indent;
    pai("std::vector<std::unique_ptr<ParamB>> params = ");
    printField(*this, a->params);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitArgList(ASTNS::ArgList *a) {
    pai("ArgList {\n");
    ++indent;
    pai("std::vector<std::unique_ptr<Arg>> args = ");
    printField(*this, a->args);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitVarStmtItemList(ASTNS::VarStmtItemList *a) {
    pai("VarStmtItemList {\n");
    ++indent;
    pai("std::vector<std::unique_ptr<VarStmtItem>> items = ");
    printField(*this, a->items);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitImplMemberList(ASTNS::ImplMemberList *a) {
    pai("ImplMemberList {\n");
    ++indent;
    pai("std::vector<std::unique_ptr<ImplMember>> members = ");
    printField(*this, a->members);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitPureLocation(ASTNS::PureLocation *a) {
    pai("PureLocation {\n");
    ++indent;
    pai("int dummy = ");
    printField(*this, a->dummy);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitImplicitDecl(ASTNS::ImplicitDecl *a) {
    pai("ImplicitDecl {\n");
    ++indent;
    pai("int dummy = ");
    printField(*this, a->dummy);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitCU(ASTNS::CU *a) {
    pai("CU {\n");
    ++indent;
    pai("std::vector<std::unique_ptr<Decl>> decls = ");
    printField(*this, a->decls);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitImplDecl(ASTNS::ImplDecl *a) {
    pai("ImplDecl {\n");
    ++indent;
    pai("std::unique_ptr<Type> implFor = ");
    printField(*this, a->implFor);
    pai("std::vector<std::unique_ptr<ImplMember>> members = ");
    printField(*this, a->members);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitFunctionDecl(ASTNS::FunctionDecl *a) {
    pai("FunctionDecl {\n");
    ++indent;
    pai("std::unique_ptr<Type> retty = ");
    printField(*this, a->retty);
    pai("Token name = ");
    printField(*this, a->name);
    pai("std::vector<std::unique_ptr<ParamB>> params = ");
    printField(*this, a->params);
    pai("std::unique_ptr<Block> body = ");
    printField(*this, a->body);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitFunctionImplMember(ASTNS::FunctionImplMember *a) {
    pai("FunctionImplMember {\n");
    ++indent;
    pai("std::unique_ptr<FunctionDecl> fun = ");
    printField(*this, a->fun);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitVarStmt(ASTNS::VarStmt *a) {
    pai("VarStmt {\n");
    ++indent;
    pai("std::vector<std::unique_ptr<VarStmtItem>> items = ");
    printField(*this, a->items);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitVarStmtItem(ASTNS::VarStmtItem *a) {
    pai("VarStmtItem {\n");
    ++indent;
    pai("std::unique_ptr<Type> type = ");
    printField(*this, a->type);
    pai("bool mut = ");
    printField(*this, a->mut);
    pai("Token name = ");
    printField(*this, a->name);
    pai("Token equal = ");
    printField(*this, a->equal);
    pai("std::unique_ptr<Expr> expr = ");
    printField(*this, a->expr);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitExprStmt(ASTNS::ExprStmt *a) {
    pai("ExprStmt {\n");
    ++indent;
    pai("std::unique_ptr<Expr> expr = ");
    printField(*this, a->expr);
    pai("bool suppress = ");
    printField(*this, a->suppress);
    pai("Location dot = ");
    printField(*this, a->dot);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitRetStmt(ASTNS::RetStmt *a) {
    pai("RetStmt {\n");
    ++indent;
    pai("std::unique_ptr<Expr> expr = ");
    printField(*this, a->expr);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitPathType(ASTNS::PathType *a) {
    pai("PathType {\n");
    ++indent;
    pai("std::unique_ptr<Path> path = ");
    printField(*this, a->path);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitPointerType(ASTNS::PointerType *a) {
    pai("PointerType {\n");
    ++indent;
    pai("bool mut = ");
    printField(*this, a->mut);
    pai("std::unique_ptr<Type> type = ");
    printField(*this, a->type);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitThisType(ASTNS::ThisType *a) {
    pai("ThisType {\n");
    ++indent;
    pai("Token th = ");
    printField(*this, a->th);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitArg(ASTNS::Arg *a) {
    pai("Arg {\n");
    ++indent;
    pai("std::unique_ptr<Expr> expr = ");
    printField(*this, a->expr);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitParam(ASTNS::Param *a) {
    pai("Param {\n");
    ++indent;
    pai("std::unique_ptr<Type> type = ");
    printField(*this, a->type);
    pai("Token name = ");
    printField(*this, a->name);
    pai("bool mut = ");
    printField(*this, a->mut);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitThisParam(ASTNS::ThisParam *a) {
    pai("ThisParam {\n");
    ++indent;
    pai("bool ptr = ");
    printField(*this, a->ptr);
    pai("bool mut = ");
    printField(*this, a->mut);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitBlock(ASTNS::Block *a) {
    pai("Block {\n");
    ++indent;
    pai("std::vector<std::unique_ptr<Stmt>> stmts = ");
    printField(*this, a->stmts);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitIfExpr(ASTNS::IfExpr *a) {
    pai("IfExpr {\n");
    ++indent;
    pai("Token iftok = ");
    printField(*this, a->iftok);
    pai("Token elsetok = ");
    printField(*this, a->elsetok);
    pai("std::unique_ptr<Expr> cond = ");
    printField(*this, a->cond);
    pai("std::unique_ptr<Expr> trues = ");
    printField(*this, a->trues);
    pai("std::unique_ptr<Expr> falses = ");
    printField(*this, a->falses);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitForExpr(ASTNS::ForExpr *a) {
    pai("ForExpr {\n");
    ++indent;
    pai("std::unique_ptr<VarStmt> initial = ");
    printField(*this, a->initial);
    pai("std::unique_ptr<Expr> cond = ");
    printField(*this, a->cond);
    pai("std::unique_ptr<Expr> increment = ");
    printField(*this, a->increment);
    pai("std::unique_ptr<Expr> body = ");
    printField(*this, a->body);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitAssignmentExpr(ASTNS::AssignmentExpr *a) {
    pai("AssignmentExpr {\n");
    ++indent;
    pai("std::unique_ptr<Expr> target = ");
    printField(*this, a->target);
    pai("Token equal = ");
    printField(*this, a->equal);
    pai("std::unique_ptr<Expr> expr = ");
    printField(*this, a->expr);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitShortCircuitExpr(ASTNS::ShortCircuitExpr *a) {
    pai("ShortCircuitExpr {\n");
    ++indent;
    pai("std::unique_ptr<Expr> lhs = ");
    printField(*this, a->lhs);
    pai("Token op = ");
    printField(*this, a->op);
    pai("std::unique_ptr<Expr> rhs = ");
    printField(*this, a->rhs);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitBinaryExpr(ASTNS::BinaryExpr *a) {
    pai("BinaryExpr {\n");
    ++indent;
    pai("std::unique_ptr<Expr> lhs = ");
    printField(*this, a->lhs);
    pai("Token op = ");
    printField(*this, a->op);
    pai("std::unique_ptr<Expr> rhs = ");
    printField(*this, a->rhs);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitCastExpr(ASTNS::CastExpr *a) {
    pai("CastExpr {\n");
    ++indent;
    pai("std::unique_ptr<Type> type = ");
    printField(*this, a->type);
    pai("std::unique_ptr<Expr> expr = ");
    printField(*this, a->expr);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitUnaryExpr(ASTNS::UnaryExpr *a) {
    pai("UnaryExpr {\n");
    ++indent;
    pai("Token op = ");
    printField(*this, a->op);
    pai("std::unique_ptr<Expr> expr = ");
    printField(*this, a->expr);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitAddrofExpr(ASTNS::AddrofExpr *a) {
    pai("AddrofExpr {\n");
    ++indent;
    pai("Token op = ");
    printField(*this, a->op);
    pai("std::unique_ptr<Expr> expr = ");
    printField(*this, a->expr);
    pai("bool mut = ");
    printField(*this, a->mut);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitDerefExpr(ASTNS::DerefExpr *a) {
    pai("DerefExpr {\n");
    ++indent;
    pai("Token op = ");
    printField(*this, a->op);
    pai("std::unique_ptr<Expr> expr = ");
    printField(*this, a->expr);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitCallExpr(ASTNS::CallExpr *a) {
    pai("CallExpr {\n");
    ++indent;
    pai("std::unique_ptr<Expr> callee = ");
    printField(*this, a->callee);
    pai("Token oparn = ");
    printField(*this, a->oparn);
    pai("std::vector<std::unique_ptr<Arg>> args = ");
    printField(*this, a->args);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitPrimaryExpr(ASTNS::PrimaryExpr *a) {
    pai("PrimaryExpr {\n");
    ++indent;
    pai("Token value = ");
    printField(*this, a->value);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitPathExpr(ASTNS::PathExpr *a) {
    pai("PathExpr {\n");
    ++indent;
    pai("std::unique_ptr<Path> path = ");
    printField(*this, a->path);
    --indent;
    pai("}\n");
}
void ASTNS::PrintVisitor::visitPath(ASTNS::Path *a) {
    pai("Path {\n");
    ++indent;
    pai("std::vector<Token> segments = ");
    printField(*this, a->segments);
    --indent;
    pai("}\n");
}
// This code was autogenerated - see the utils/ directory
// PRINTVISITOR END

void ASTNS::PrintVisitor::pai(std::string const &s) {
    for (auto i = s.begin(); i != s.end(); ++i) {
        if (pindent)
            for (int j = 0; j < indent; ++j)
                ostream << "    ";

        pindent = false;
        ostream << *i;

        if (*i == '\n')
            pindent = true;
    }
}

ASTNS::PrintVisitor::PrintVisitor(llvm::raw_ostream &ostream): indent(0), ostream(ostream) {}
