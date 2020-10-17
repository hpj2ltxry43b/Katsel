#pragma once

#include "visit/visitor.h"
#include "parse/ast.h"

#include "codegen/context.h"
#include "value/value.h"
#include "typing/type.h"

#include "llvm/IR/Type.h"

class CodeGen :
    public ExprVisitor,
    public DeclVisitor,
    public StmtVisitor,
    public TypeVisitor,
    public ProgramVisitor
{
public:
    CodeGen(CodeGenContext &context);

    virtual void visitBinaryExpr(ASTNS::BinaryExpr *a) override;
    virtual void visitTernaryExpr(ASTNS::TernaryExpr *a) override;
    virtual void visitUnaryExpr(ASTNS::UnaryExpr *a) override;
    virtual void visitPrimaryExpr(ASTNS::PrimaryExpr *a) override;
    virtual void visitCallExpr(ASTNS::CallExpr *a) override;

    virtual void visitFunctionDecl(ASTNS::FunctionDecl *a) override;
    virtual void visitGlobalVarDecl(ASTNS::GlobalVarDecl *a) override;

    virtual void visitBaseType(ASTNS::BaseType *a) override;

    virtual void visitBlockStmt(ASTNS::BlockStmt *a) override;
    virtual void visitExprStmt(ASTNS::ExprStmt *a) override;
    virtual void visitReturnStmt(ASTNS::ReturnStmt *a) override;
    virtual void visitVarStmt(ASTNS::VarStmt *a) override;

    virtual void visitProgram(ASTNS::Program *a) override;

    Value evalExpr(ASTNS::Expr *a);
    Type* evalType(ASTNS::Type *a);

private:
    CodeGenContext &context;

    Value exprRetVal;
    Type *typeRetVal;
};

inline std::string tokenToStr(Token t)
{
    return std::string(t.start, t.end);
}