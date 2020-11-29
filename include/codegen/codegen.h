#pragma once

#include "llvm/Support/raw_ostream.h"

#include "ast/visitor.h"
#include "ast/ast.h"

#include "ir/value.h"
#include "ir/type.h"
#include "ir/unit.h"
#include "ir/instruction.h"

namespace CodeGenNS
{
    class CodeGen;
    class TypeResolve : public ASTNS::TypeBVisitor
    {
    public:
        TypeResolve(CodeGen &cg);

        IR::Type* type(ASTNS::TypeB *ast);

    private:
        // TYPEVISITOR METHODS START

// The following code was autogenerated - see the utils/ directory
void visitBuiltinTypeNoVoid(ASTNS::BuiltinTypeNoVoid *ast) override;
void visitBuiltinTypeVoid(ASTNS::BuiltinTypeVoid *ast) override;
// This code was autogenerated - see the utils/ directory

        // TYPEVISITOR METHODS END

        IR::Type *ret;

        CodeGen &cg;
    };

    class Declarator : public ASTNS::DeclBVisitor, public ASTNS::CUBVisitor
    {
    public:
        Declarator(CodeGen &cg);

    private:
        // DECLARATOR METHODS START

// The following code was autogenerated - see the utils/ directory
void visitCU(ASTNS::CU *ast) override;
void visitDeclList(ASTNS::DeclList *ast) override;
void visitFunction(ASTNS::Function *ast) override;
// This code was autogenerated - see the utils/ directory

        // DECLARATOR METHODS END

        CodeGen &cg;
    };

    class ParamVisitor : public ASTNS::PListBVisitor
    {
    public:
        struct Param
        {
            IR::Type *ty;
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

    class ArgsVisitor : public ASTNS::ArgBVisitor
    {
    public:
        ArgsVisitor(CodeGen &cg);

        std::vector<IR::ASTValue> args(ASTNS::ArgB *pl);

    private:
        // ARGSVISITOR METHODS START

// The following code was autogenerated - see the utils/ directory
void visitArg(ASTNS::Arg *ast) override;
void visitArgList(ASTNS::ArgList *ast) override;
// This code was autogenerated - see the utils/ directory

        // ARGSVISITOR METHODS END

        std::vector<IR::ASTValue> ret;
        CodeGen &cg;
    };

    class DeclCodeGen : public ASTNS::DeclBVisitor, public ASTNS::CUBVisitor
    {
    public:
        DeclCodeGen(CodeGen &cg);

    private:
        // DECLCG METHODS START

// The following code was autogenerated - see the utils/ directory
void visitCU(ASTNS::CU *ast) override;
void visitDeclList(ASTNS::DeclList *ast) override;
void visitFunction(ASTNS::Function *ast) override;
// This code was autogenerated - see the utils/ directory

        // DECLCG METHODS END

        CodeGen &cg;
    };

    class StmtCodeGen : public ASTNS::StmtBVisitor, public ASTNS::VStmtIBVisitor
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
void visitStmtList(ASTNS::StmtList *ast) override;
void visitVarStmt(ASTNS::VarStmt *ast) override;
void visitVarStmtItem(ASTNS::VarStmtItem *ast) override;
void visitVarStmtItemList(ASTNS::VarStmtItemList *ast) override;
// This code was autogenerated - see the utils/ directory

        // STMTCG METHODS END

        CodeGen &cg;
        IR::Type *varty;
    };

    class ExprCodeGen : public ASTNS::ExprBVisitor
    {
    public:
        ExprCodeGen(CodeGen &cg);

        IR::ASTValue expr(ASTNS::ExprB *ast);

    private:
        // EXPRCG METHODS START

// The following code was autogenerated - see the utils/ directory
void visitAdditionExpr(ASTNS::AdditionExpr *ast) override;
void visitAssignmentExpr(ASTNS::AssignmentExpr *ast) override;
void visitBinandExpr(ASTNS::BinandExpr *ast) override;
void visitBinorExpr(ASTNS::BinorExpr *ast) override;
void visitBitandExpr(ASTNS::BitandExpr *ast) override;
void visitBitorExpr(ASTNS::BitorExpr *ast) override;
void visitBitshiftExpr(ASTNS::BitshiftExpr *ast) override;
void visitBitxorExpr(ASTNS::BitxorExpr *ast) override;
void visitCallExpr(ASTNS::CallExpr *ast) override;
void visitCompeqExpr(ASTNS::CompeqExpr *ast) override;
void visitComplgtExpr(ASTNS::ComplgtExpr *ast) override;
void visitMultExpr(ASTNS::MultExpr *ast) override;
void visitPrimaryExpr(ASTNS::PrimaryExpr *ast) override;
void visitTernaryExpr(ASTNS::TernaryExpr *ast) override;
void visitUnaryExpr(ASTNS::UnaryExpr *ast) override;
// This code was autogenerated - see the utils/ directory

        // EXPRCG METHODS END

        IR::ASTValue ret;
        CodeGen &cg;
    };

    class Context
    {
    public:
        struct Local
        {
            size_t scopenum;
            IR::Register *v;
            std::string name;
        };

        Context(File const &file);

        IR::Unit unit;
        std::map<std::string, IR::Value*> globalSymbolTable;

        std::vector<Local> locals;
        size_t curScope = 1;

        IR::BuiltinType* getBuiltinType(IR::BuiltinType::Builtins ty);
        IR::FunctionType* getFunctionType(IR::Type *ret, std::vector<IR::Type*> paramtys);
        IR::VoidType* getVoidType();

        void addLocal(std::string const &name, IR::Register *val);
        Local* findLocal(std::string const &name);
        IR::Value* findValue(std::string const &name);
        IR::Value* findGlobal(std::string const &name);

        void incScope();
        void decScope();

        IR::Function *curFunc;
        IR::Block *curBlock;
        IR::Block *exitBlock;
        IR::Register *retReg;
        std::unique_ptr<IR::Block> blackHoleBlock;

        std::vector<std::unique_ptr<IR::ConstInt>> constants;
        IR::ConstInt* getConstInt(IR::BuiltinType *ty, int val);

    private:
        std::vector<std::unique_ptr<IR::Type>> types;
    };

    class CodeGen
    {
    public:
        CodeGen(File const &file);

        void declarate(ASTNS::CUB *decls);
        void codegen(ASTNS::CUB *decls);

        void printUnit(llvm::raw_ostream &ostream);

        Context context;

        Declarator declarator;
        TypeResolve typeResolver;
        ParamVisitor paramVisitor;
        ArgsVisitor argsVisitor;

        DeclCodeGen declCodeGen;
        StmtCodeGen stmtCodeGen;
        ExprCodeGen exprCodeGen;

        bool errored;
    };
}
