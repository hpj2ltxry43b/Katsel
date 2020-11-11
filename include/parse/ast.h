#pragma once

#include <memory>
#include <vector>
#include "lex/token.h"
#include "visit/visitor.h"

namespace ASTNS
{
// ASTHEADER START

// The following code was autogenerated - see the utils/ directory
    class AST;
    class Add;
    class Mult;
    class New_expr;
    class New_stmt;
    class Primary;
    class Unary;
    class NewBaseAST
    {
    public:
        virtual ~NewBaseAST() {}
        virtual void accept(ASTVisitor *v) = 0;
    };
    class Add : public NewBaseAST
    {
    public:
        Add(std::unique_ptr<NewBaseAST> lhs, Token op, std::unique_ptr<NewBaseAST> rhs);
        enum class Form
        {
            ATA,
        };
        std::unique_ptr<NewBaseAST> lhs;
        Token op;
        std::unique_ptr<NewBaseAST> rhs;
        Form form;
        virtual void accept(ASTVisitor *v);
    };
    class Mult : public NewBaseAST
    {
    public:
        Mult(std::unique_ptr<NewBaseAST> lhs, Token op, std::unique_ptr<NewBaseAST> rhs);
        enum class Form
        {
            ATA,
        };
        std::unique_ptr<NewBaseAST> lhs;
        Token op;
        std::unique_ptr<NewBaseAST> rhs;
        Form form;
        virtual void accept(ASTVisitor *v);
    };
    class New_expr : public NewBaseAST
    {
    public:
        New_expr(std::unique_ptr<NewBaseAST> expr);
        enum class Form
        {
            A,
        };
        std::unique_ptr<NewBaseAST> expr;
        Form form;
        virtual void accept(ASTVisitor *v);
    };
    class New_stmt : public NewBaseAST
    {
    public:
        New_stmt(std::unique_ptr<NewBaseAST> expr);
        enum class Form
        {
            A,
        };
        std::unique_ptr<NewBaseAST> expr;
        Form form;
        virtual void accept(ASTVisitor *v);
    };
    class Primary : public NewBaseAST
    {
    public:
        Primary(Token value);
        Primary(Token oparn, std::unique_ptr<NewBaseAST> expr, Token cparn);
        enum class Form
        {
            T,
            TAT,
        };
        Token value;
        Token oparn;
        std::unique_ptr<NewBaseAST> expr;
        Token cparn;
        Form form;
        virtual void accept(ASTVisitor *v);
    };
    class Unary : public NewBaseAST
    {
    public:
        Unary(Token op, std::unique_ptr<NewBaseAST> operand);
        enum class Form
        {
            TA,
        };
        Token op;
        std::unique_ptr<NewBaseAST> operand;
        Form form;
        virtual void accept(ASTVisitor *v);
    };
// This code was autogenerated - see the utils/ directory

// ASTHEADER END
    // old things {{{
    class AST // TODO: remove this: this is just to silence the errors coming from the missing AST classes
    {
    public:
        virtual ~AST() {}
    };
    class Expr;
    class Decl;
    class Type;
    class Stmt;
    class Program;
    class BinaryExpr;
    class TernaryExpr;
    class UnaryExpr;
    class PrimaryExpr;
    class CallExpr;
    class BlockStmt;
    class ExprStmt;
    class ReturnStmt;
    class VarStmt;
    class BaseType;
    class FunctionDecl;
    class GlobalVarDecl;
    class Param;
    class Arg;
    class Expr : public AST
    {
    public:
        virtual ~Expr() {}
        virtual void accept(ExprVisitor *v) = 0;
    };
    class Decl : public AST
    {
    public:
        virtual ~Decl() {}
        virtual void accept(DeclVisitor *v) = 0;
    };
    class Type : public AST
    {
    public:
        virtual ~Type() {}
        virtual void accept(TypeVisitor *v) = 0;
    };
    class Stmt : public AST
    {
    public:
        virtual ~Stmt() {}
        virtual void accept(StmtVisitor *v) = 0;
    };
    class Program : public AST
    {
    public:
        Program(std::vector<std::unique_ptr<Decl>> &decls);
        std::vector<std::unique_ptr<Decl>> decls;
        virtual void accept(ProgramVisitor *v);
        virtual ~Program() {}
    };
    class BinaryExpr : public Expr
    {
    public:
        BinaryExpr(std::unique_ptr<Expr> lhs, std::unique_ptr<Expr> rhs, Token op);
        std::unique_ptr<Expr> lhs;
        std::unique_ptr<Expr> rhs;
        Token op;
        virtual void accept(ExprVisitor *v);
    };
    class TernaryExpr : public Expr
    {
    public:
        TernaryExpr(std::unique_ptr<Expr> condition, std::unique_ptr<Expr> trues, std::unique_ptr<Expr> falses);
        std::unique_ptr<Expr> condition;
        std::unique_ptr<Expr> trues;
        std::unique_ptr<Expr> falses;
        virtual void accept(ExprVisitor *v);
    };
    class UnaryExpr : public Expr
    {
    public:
        UnaryExpr(std::unique_ptr<Expr> operand, Token op);
        std::unique_ptr<Expr> operand;
        Token op;
        virtual void accept(ExprVisitor *v);
    };
    class PrimaryExpr : public Expr
    {
    public:
        PrimaryExpr(Token value);
        Token value;
        virtual void accept(ExprVisitor *v);
    };
    class CallExpr : public Expr
    {
    public:
        CallExpr(std::unique_ptr<Expr> func, std::unique_ptr<Arg> args);
        std::unique_ptr<Expr> func;
        std::unique_ptr<Arg> args;
        virtual void accept(ExprVisitor *v);
    };
    class BlockStmt : public Stmt
    {
    public:
        BlockStmt(std::vector<std::unique_ptr<Stmt>> &stmts);
        std::vector<std::unique_ptr<Stmt>> stmts;
        virtual void accept(StmtVisitor *v);
    };
    class ExprStmt : public Stmt
    {
    public:
        ExprStmt(std::unique_ptr<Expr> expr);
        std::unique_ptr<Expr> expr;
        virtual void accept(StmtVisitor *v);
    };
    class ReturnStmt : public Stmt
    {
    public:
        ReturnStmt(std::unique_ptr<Expr> val);
        std::unique_ptr<Expr> val;
        virtual void accept(StmtVisitor *v);
    };
    class VarStmt : public Stmt
    {
    public:
        VarStmt(std::unique_ptr<Type> type, std::vector<std::unique_ptr<Expr>> &assignments);
        std::unique_ptr<Type> type;
        std::vector<std::unique_ptr<Expr>> assignments;
        virtual void accept(StmtVisitor *v);
    };
    class BaseType : public Type
    {
    public:
        BaseType(Token type);
        Token type;
        virtual void accept(TypeVisitor *v);
    };
    class FunctionDecl : public Decl
    {
    public:
        FunctionDecl(std::unique_ptr<Type> rettype, Token name, std::unique_ptr<Param> params, std::unique_ptr<BlockStmt> block);
        std::unique_ptr<Type> rettype;
        Token name;
        std::unique_ptr<Param> params;
        std::unique_ptr<BlockStmt> block;
        virtual void accept(DeclVisitor *v);
    };
    class GlobalVarDecl : public Decl
    {
    public:
        GlobalVarDecl(std::unique_ptr<Type> type, std::vector<std::unique_ptr<Expr>> &assignments);
        std::unique_ptr<Type> type;
        std::vector<std::unique_ptr<Expr>> assignments;
        virtual void accept(DeclVisitor *v);
    };
    class Param : public AST
    {
    public:
        Param(std::unique_ptr<Type> type, Token name, std::unique_ptr<Param> next);
        std::unique_ptr<Type> type;
        Token name;
        std::unique_ptr<Param> next;
        virtual void accept(ParamVisitor *v);
        virtual ~Param() {}
    };
    class Arg : public AST
    {
    public:
        Arg(std::unique_ptr<Expr> value, std::unique_ptr<Arg> next);
        std::unique_ptr<Expr> value;
        std::unique_ptr<Arg> next;
        virtual void accept(ArgVisitor *v);
        virtual ~Arg() {}
    };
    // }}}
}
