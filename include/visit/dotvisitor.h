#pragma once

#include "visit/visitor.h"
#include "parse/ast.h"
#include <string>

class DotVisitor : public ASTVisitor
{
public:
    // DOTVISITOR METHODS START

// The following code was autogenerated - see the utils/ directory
void visitAdditionexpr(ASTNS::Additionexpr *ast) override;
void visitArgs(ASTNS::Args *ast) override;
void visitAssignmentexpr(ASTNS::Assignmentexpr *ast) override;
void visitBinandexpr(ASTNS::Binandexpr *ast) override;
void visitBinnotexpr(ASTNS::Binnotexpr *ast) override;
void visitBinorexpr(ASTNS::Binorexpr *ast) override;
void visitBitandexpr(ASTNS::Bitandexpr *ast) override;
void visitBitorexpr(ASTNS::Bitorexpr *ast) override;
void visitBitshiftexpr(ASTNS::Bitshiftexpr *ast) override;
void visitBitxorexpr(ASTNS::Bitxorexpr *ast) override;
void visitBlock(ASTNS::Block *ast) override;
void visitCall(ASTNS::Call *ast) override;
void visitCompeqexpr(ASTNS::Compeqexpr *ast) override;
void visitComplgtexpr(ASTNS::Complgtexpr *ast) override;
void visitDecl(ASTNS::Decl *ast) override;
void visitDeclarations(ASTNS::Declarations *ast) override;
void visitExpression(ASTNS::Expression *ast) override;
void visitExprstmt(ASTNS::Exprstmt *ast) override;
void visitFunction(ASTNS::Function *ast) override;
void visitMultexpr(ASTNS::Multexpr *ast) override;
void visitParamlist(ASTNS::Paramlist *ast) override;
void visitPrimary(ASTNS::Primary *ast) override;
void visitRetstmt(ASTNS::Retstmt *ast) override;
void visitStmt(ASTNS::Stmt *ast) override;
void visitStmts(ASTNS::Stmts *ast) override;
void visitTernaryexpr(ASTNS::Ternaryexpr *ast) override;
void visitType(ASTNS::Type *ast) override;
void visitUnary(ASTNS::Unary *ast) override;
void visitVarstmt(ASTNS::Varstmt *ast) override;
void visitVarstmtfinisher(ASTNS::Varstmtfinisher *ast) override;
// This code was autogenerated - see the utils/ directory

    // DOTVISITOR METHODS END

    void dotVisit(ASTNS::AST *ast);
private:
    int _curid = 0;
    std::string curid();
    std::string makeTextNode(std::string type, std::string text);
    void connect(std::string startid, std::string fieldname, std::string connectto);
    std::string lastid;
};
