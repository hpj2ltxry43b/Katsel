#pragma once

#include <ostream>

#include "visit/visitor.h"
#include "parse/ast.h"

#include "ir/value/value.h"
#include "ir/typing/type.h"

namespace CodeGenNS
{
    class CodeGen;
    class TypeResolve : public TypeBVisitor
    {
    public:
        TypeResolve(CodeGen &cg);

        Type* type(ASTNS::TypeB *ast);

    private:
        // TYPEVISITOR METHODS START

// The following code was autogenerated - see the utils/ directory
void visitBuiltinTypeNoVoid(ASTNS::BuiltinTypeNoVoid *ast) override;
void visitBuiltinTypeVoid(ASTNS::BuiltinTypeVoid *ast) override;
void visitTypeNV(ASTNS::TypeNV *ast) override;
void visitTypeV(ASTNS::TypeV *ast) override;
// This code was autogenerated - see the utils/ directory

        // TYPEVISITOR METHODS END

        Type *ret;

        CodeGen &cg;
    };

    class Declarator : public DeclBVisitor
    {
    public:
        Declarator(CodeGen &cg);

    private:
        // DECLARATOR METHODS START

// The following code was autogenerated - see the utils/ directory
void visitDecl(ASTNS::Decl *ast) override;
void visitDeclList(ASTNS::DeclList *ast) override;
void visitFunction(ASTNS::Function *ast) override;
// This code was autogenerated - see the utils/ directory

        // DECLARATOR METHODS END

        CodeGen &cg;
    };

    class ParamVisitor : public PListBVisitor
    {
    public:
        struct Param
        {
            Type *ty;
            std::string name;
            ASTNS::Param *ast;
        };
        ParamVisitor(CodeGen &cg);

        std::vector<Param> params(ASTNS::PListB *pl);

    private:
        // PARAMVISITOR METHODS START

// The following code was autogenerated - see the utils/ directory
void visitParam(ASTNS::Param *ast) override;
void visitParamList(ASTNS::ParamList *ast) override;
// This code was autogenerated - see the utils/ directory

        // PARAMVISITOR METHODS END

        std::vector<Param> ret;
        CodeGen &cg;

    };

    class ArgsVisitor : public ArgBVisitor
    {
    public:
        ArgsVisitor(CodeGen &cg);

        std::vector<Value> args(ASTNS::ArgB *pl);

    private:
        // ARGSVISITOR METHODS START

// The following code was autogenerated - see the utils/ directory
void visitArg(ASTNS::Arg *ast) override;
void visitArgList(ASTNS::ArgList *ast) override;
// This code was autogenerated - see the utils/ directory

        // ARGSVISITOR METHODS END

        std::vector<Value> ret;
        CodeGen &cg;
    };

    class DeclCodeGen : public DeclBVisitor
    {
    public:
        DeclCodeGen(CodeGen &cg);

    private:
        // DECLCG METHODS START

// The following code was autogenerated - see the utils/ directory
void visitDecl(ASTNS::Decl *ast) override;
void visitDeclList(ASTNS::DeclList *ast) override;
void visitFunction(ASTNS::Function *ast) override;
// This code was autogenerated - see the utils/ directory

        // DECLCG METHODS END

        CodeGen &cg;
    };

    class StmtCodeGen : public StmtBVisitor, public VStmtIBVisitor
    {
    public:
        StmtCodeGen(CodeGen &cg);

        void stmt(ASTNS::StmtB *ast);

    private:
        // STMTCG METHODS START

// The following code was autogenerated - see the utils/ directory
void visitBlock(ASTNS::Block *ast) override;
void visitEmptyStmt(ASTNS::EmptyStmt *ast) override;
void visitExprStmt(ASTNS::ExprStmt *ast) override;
void visitRetStmt(ASTNS::RetStmt *ast) override;
void visitStmt(ASTNS::Stmt *ast) override;
void visitStmtList(ASTNS::StmtList *ast) override;
void visitVarStmt(ASTNS::VarStmt *ast) override;
void visitVarStmtItem(ASTNS::VarStmtItem *ast) override;
void visitVarStmtItemList(ASTNS::VarStmtItemList *ast) override;
// This code was autogenerated - see the utils/ directory

        // STMTCG METHODS END

        CodeGen &cg;
        Type *varty;
    };

    class ExprCodeGen : public ExprBVisitor
    {
    public:
        ExprCodeGen(CodeGen &cg);

        Value expr(ASTNS::ExprB *ast);

    private:
        // EXPRCG METHODS START

// The following code was autogenerated - see the utils/ directory
void visitAdditionExpr(ASTNS::AdditionExpr *ast) override;
void visitAssignmentExpr(ASTNS::AssignmentExpr *ast) override;
void visitBinandExpr(ASTNS::BinandExpr *ast) override;
void visitBinnotExpr(ASTNS::BinnotExpr *ast) override;
void visitBinorExpr(ASTNS::BinorExpr *ast) override;
void visitBitandExpr(ASTNS::BitandExpr *ast) override;
void visitBitorExpr(ASTNS::BitorExpr *ast) override;
void visitBitshiftExpr(ASTNS::BitshiftExpr *ast) override;
void visitBitxorExpr(ASTNS::BitxorExpr *ast) override;
void visitCallExpr(ASTNS::CallExpr *ast) override;
void visitCompeqExpr(ASTNS::CompeqExpr *ast) override;
void visitComplgtExpr(ASTNS::ComplgtExpr *ast) override;
void visitExpr(ASTNS::Expr *ast) override;
void visitMultExpr(ASTNS::MultExpr *ast) override;
void visitPrimaryExpr(ASTNS::PrimaryExpr *ast) override;
void visitTernaryExpr(ASTNS::TernaryExpr *ast) override;
void visitUnaryExpr(ASTNS::UnaryExpr *ast) override;
// This code was autogenerated - see the utils/ directory

        // EXPRCG METHODS END

        Value ret;
        CodeGen &cg;
    };

    class Context
    {
    public:
        Context(std::string const &name);

        std::map<std::string, Value> globalSymbolTable;

        std::vector<Local> locals;
        size_t curScope = 1;

        Type* getBuiltinType(BuiltinType::Builtins ty);
        Type* getFunctionType(Type *ret, std::vector<Type*> paramtys);
        Type* getVoidType();

        // void addLocalSymbol(std::string const &name, Type *type, llvm::AllocaInst *alloca, ASTNS::AST *ast);
        Local* findLocal(std::string const &name);
        Value findValue(std::string const &name);
        Value findGlobal(std::string const &name);

        void incScope();
        void decScope();

        Value curFunc;

    private:
        std::vector<std::unique_ptr<Type>> types;
    };

    class CodeGen
    {
    public:
        CodeGen(std::string const &name);

        void declarate(ASTNS::DeclB *decls);
        void codegen(ASTNS::DeclB *decls);

        void printMod(std::ostream &ostream);

        Context context;

        Declarator declarator;
        TypeResolve typeResolver;
        ParamVisitor paramVisitor;
        ArgsVisitor argsVisitor;

        DeclCodeGen declCodeGen;
        StmtCodeGen stmtCodeGen;
        ExprCodeGen exprCodeGen;
    };
}
