#pragma once

#include "visit/visitor.h"
#include "parse/ast.h"
#include <string>

class DotVisitor : 
    public Visitors::DeclBVisitor,
    public Visitors::ArgBVisitor,
    public Visitors::StmtBVisitor,
    public Visitors::ExprBVisitor,
    public Visitors::VStmtIBVisitor,
    public Visitors::PListBVisitor,
    public Visitors::TypeBVisitor
{
public:
    DotVisitor(std::ostream &ostream);
    // DOTVISIT METHODS START

// The following code was autogenerated - see the utils/ directory
void visitAdditionExpr(ASTNS::AdditionExpr *ast) override;
void visitArg(ASTNS::Arg *ast) override;
void visitArgList(ASTNS::ArgList *ast) override;
void visitAssignmentExpr(ASTNS::AssignmentExpr *ast) override;
void visitBinandExpr(ASTNS::BinandExpr *ast) override;
void visitBinnotExpr(ASTNS::BinnotExpr *ast) override;
void visitBinorExpr(ASTNS::BinorExpr *ast) override;
void visitBitandExpr(ASTNS::BitandExpr *ast) override;
void visitBitorExpr(ASTNS::BitorExpr *ast) override;
void visitBitshiftExpr(ASTNS::BitshiftExpr *ast) override;
void visitBitxorExpr(ASTNS::BitxorExpr *ast) override;
void visitBlock(ASTNS::Block *ast) override;
void visitBuiltinTypeNoVoid(ASTNS::BuiltinTypeNoVoid *ast) override;
void visitBuiltinTypeVoid(ASTNS::BuiltinTypeVoid *ast) override;
void visitCallExpr(ASTNS::CallExpr *ast) override;
void visitCompeqExpr(ASTNS::CompeqExpr *ast) override;
void visitComplgtExpr(ASTNS::ComplgtExpr *ast) override;
void visitDeclList(ASTNS::DeclList *ast) override;
void visitEmptyStmt(ASTNS::EmptyStmt *ast) override;
void visitExprStmt(ASTNS::ExprStmt *ast) override;
void visitFunction(ASTNS::Function *ast) override;
void visitMultExpr(ASTNS::MultExpr *ast) override;
void visitParam(ASTNS::Param *ast) override;
void visitParamList(ASTNS::ParamList *ast) override;
void visitPrimaryExpr(ASTNS::PrimaryExpr *ast) override;
void visitRetStmt(ASTNS::RetStmt *ast) override;
void visitStmtList(ASTNS::StmtList *ast) override;
void visitTernaryExpr(ASTNS::TernaryExpr *ast) override;
void visitUnaryExpr(ASTNS::UnaryExpr *ast) override;
void visitVarStmt(ASTNS::VarStmt *ast) override;
void visitVarStmtItem(ASTNS::VarStmtItem *ast) override;
void visitVarStmtItemList(ASTNS::VarStmtItemList *ast) override;
// This code was autogenerated - see the utils/ directory

    // DOTVISIT METHODS END

    void dotVisit(ASTNS::DeclB *ast);
private:
    int _curid = 0;
    std::string curid();
    std::string makeTextNode(std::string type, std::string text);
    void connect(std::string startid, std::string fieldname, std::string connectto);
    std::string lastid;

    std::ostream &ostream;
};
