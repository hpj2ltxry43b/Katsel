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
    class Expr;
    class _ARGSBASE;
    class _DECLBASE;
    class _PLISTBASE;
    class _STMTBASE;
    class _TYPEBASE;
    class _VSTMTI;
    class _VSTMTIS;
    class AdditionExpr;
    class Args;
    class AssignmentExpr;
    class BinandExpr;
    class BinnotExpr;
    class BinorExpr;
    class BitandExpr;
    class BitorExpr;
    class BitshiftExpr;
    class BitxorExpr;
    class Block;
    class CallExpr;
    class CompeqExpr;
    class ComplgtExpr;
    class Decl;
    class Decls;
    class EmptyStmt;
    class ExprStmt;
    class Expression;
    class Function;
    class MultExpr;
    class ParamList;
    class PrimaryExpr;
    class RetStmt;
    class Stmt;
    class Stmts;
    class TernaryExpr;
    class Type;
    class UnaryExpr;
    class VarStmt;
    class VarStmtItem;
    class VarStmtItems;
    class AST
    {
    public:
        virtual ~AST() {}
    };
    class Expr : public AST
    {
    public:
        virtual ~Expr() {}
        virtual void accept(ExprVisitor *v) = 0;
    };
    class _ARGSBASE : public AST
    {
    public:
        virtual ~_ARGSBASE() {}
        virtual void accept(_ARGSBASEVisitor *v) = 0;
    };
    class _DECLBASE : public AST
    {
    public:
        virtual ~_DECLBASE() {}
        virtual void accept(_DECLBASEVisitor *v) = 0;
    };
    class _PLISTBASE : public AST
    {
    public:
        virtual ~_PLISTBASE() {}
        virtual void accept(_PLISTBASEVisitor *v) = 0;
    };
    class _STMTBASE : public AST
    {
    public:
        virtual ~_STMTBASE() {}
        virtual void accept(_STMTBASEVisitor *v) = 0;
    };
    class _TYPEBASE : public AST
    {
    public:
        virtual ~_TYPEBASE() {}
        virtual void accept(_TYPEBASEVisitor *v) = 0;
    };
    class _VSTMTI : public AST
    {
    public:
        virtual ~_VSTMTI() {}
        virtual void accept(_VSTMTIVisitor *v) = 0;
    };
    class _VSTMTIS : public AST
    {
    public:
        virtual ~_VSTMTIS() {}
        virtual void accept(_VSTMTISVisitor *v) = 0;
    };
    class AdditionExpr : public AST
    {
    public:
        AdditionExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs);
        enum class Form
        {
            ATA,
        };
        std::unique_ptr<Expr> lhs;
        Token op;
        std::unique_ptr<Expr> rhs;
        Form form;
        virtual void accept(ExprVisitor *v);
    };
    class Args : public AST
    {
    public:
        Args(std::unique_ptr<_ARGSBASE> args, Token comma, std::unique_ptr<Expr> expr);
        Args(std::unique_ptr<Expr> expr);
        enum class Form
        {
            ATA,
            A,
        };
        std::unique_ptr<_ARGSBASE> args;
        Token comma;
        std::unique_ptr<Expr> expr;
        Form form;
        virtual void accept(_ARGSBASEVisitor *v);
    };
    class AssignmentExpr : public AST
    {
    public:
        AssignmentExpr(std::unique_ptr<Expr> target, Token equal, std::unique_ptr<Expr> value);
        enum class Form
        {
            ATA,
        };
        std::unique_ptr<Expr> target;
        Token equal;
        std::unique_ptr<Expr> value;
        Form form;
        virtual void accept(ExprVisitor *v);
    };
    class BinandExpr : public AST
    {
    public:
        BinandExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs);
        enum class Form
        {
            ATA,
        };
        std::unique_ptr<Expr> lhs;
        Token op;
        std::unique_ptr<Expr> rhs;
        Form form;
        virtual void accept(ExprVisitor *v);
    };
    class BinnotExpr : public AST
    {
    public:
        BinnotExpr(Token op, std::unique_ptr<Expr> operand);
        enum class Form
        {
            TA,
        };
        Token op;
        std::unique_ptr<Expr> operand;
        Form form;
        virtual void accept(ExprVisitor *v);
    };
    class BinorExpr : public AST
    {
    public:
        BinorExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs);
        enum class Form
        {
            ATA,
        };
        std::unique_ptr<Expr> lhs;
        Token op;
        std::unique_ptr<Expr> rhs;
        Form form;
        virtual void accept(ExprVisitor *v);
    };
    class BitandExpr : public AST
    {
    public:
        BitandExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs);
        enum class Form
        {
            ATA,
        };
        std::unique_ptr<Expr> lhs;
        Token op;
        std::unique_ptr<Expr> rhs;
        Form form;
        virtual void accept(ExprVisitor *v);
    };
    class BitorExpr : public AST
    {
    public:
        BitorExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs);
        enum class Form
        {
            ATA,
        };
        std::unique_ptr<Expr> lhs;
        Token op;
        std::unique_ptr<Expr> rhs;
        Form form;
        virtual void accept(ExprVisitor *v);
    };
    class BitshiftExpr : public AST
    {
    public:
        BitshiftExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs);
        enum class Form
        {
            ATA,
        };
        std::unique_ptr<Expr> lhs;
        Token op;
        std::unique_ptr<Expr> rhs;
        Form form;
        virtual void accept(ExprVisitor *v);
    };
    class BitxorExpr : public AST
    {
    public:
        BitxorExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs);
        enum class Form
        {
            ATA,
        };
        std::unique_ptr<Expr> lhs;
        Token op;
        std::unique_ptr<Expr> rhs;
        Form form;
        virtual void accept(ExprVisitor *v);
    };
    class Block : public AST
    {
    public:
        Block(Token ocurb, std::unique_ptr<_STMTBASE> stmts, Token ccurb);
        Block(Token ocurb, Token ccurb);
        enum class Form
        {
            TAT,
            TT,
        };
        Token ocurb;
        std::unique_ptr<_STMTBASE> stmts;
        Token ccurb;
        Form form;
        virtual void accept(_STMTBASEVisitor *v);
    };
    class CallExpr : public AST
    {
    public:
        CallExpr(std::unique_ptr<Expr> callee, Token oparn, std::unique_ptr<_ARGSBASE> args, Token cparn);
        CallExpr(std::unique_ptr<Expr> callee, Token oparn, Token cparn);
        enum class Form
        {
            ATAT,
            ATT,
        };
        std::unique_ptr<Expr> callee;
        Token oparn;
        std::unique_ptr<_ARGSBASE> args;
        Token cparn;
        Form form;
        virtual void accept(ExprVisitor *v);
    };
    class CompeqExpr : public AST
    {
    public:
        CompeqExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs);
        enum class Form
        {
            ATA,
        };
        std::unique_ptr<Expr> lhs;
        Token op;
        std::unique_ptr<Expr> rhs;
        Form form;
        virtual void accept(ExprVisitor *v);
    };
    class ComplgtExpr : public AST
    {
    public:
        ComplgtExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs);
        enum class Form
        {
            ATA,
        };
        std::unique_ptr<Expr> lhs;
        Token op;
        std::unique_ptr<Expr> rhs;
        Form form;
        virtual void accept(ExprVisitor *v);
    };
    class Decl : public AST
    {
    public:
        enum class Form
        {
        };
        Form form;
        virtual void accept(_DECLBASEVisitor *v);
    };
    class Decls : public AST
    {
    public:
        Decls(std::unique_ptr<_DECLBASE> decls, std::unique_ptr<_DECLBASE> decl);
        enum class Form
        {
            AA,
        };
        std::unique_ptr<_DECLBASE> decls;
        std::unique_ptr<_DECLBASE> decl;
        Form form;
        virtual void accept(_DECLBASEVisitor *v);
    };
    class EmptyStmt : public AST
    {
    public:
        EmptyStmt(Token semi);
        enum class Form
        {
            T,
        };
        Token semi;
        Form form;
        virtual void accept(_STMTBASEVisitor *v);
    };
    class ExprStmt : public AST
    {
    public:
        ExprStmt(std::unique_ptr<Expr> expr, Token semi);
        enum class Form
        {
            AT,
        };
        std::unique_ptr<Expr> expr;
        Token semi;
        Form form;
        virtual void accept(_STMTBASEVisitor *v);
    };
    class Expression : public AST
    {
    public:
        enum class Form
        {
        };
        Form form;
        virtual void accept(ExprVisitor *v);
    };
    class Function : public AST
    {
    public:
        Function(Token fun, std::unique_ptr<_TYPEBASE> retty, Token name, Token oparn, Token cparn, std::unique_ptr<_STMTBASE> body);
        Function(Token fun, std::unique_ptr<_TYPEBASE> retty, Token name, Token oparn, std::unique_ptr<_PLISTBASE> paramlist, Token cparn, std::unique_ptr<_STMTBASE> body);
        enum class Form
        {
            TATTTA,
            TATTATA,
        };
        Token fun;
        std::unique_ptr<_TYPEBASE> retty;
        Token name;
        Token oparn;
        Token cparn;
        std::unique_ptr<_STMTBASE> body;
        std::unique_ptr<_PLISTBASE> paramlist;
        Form form;
        virtual void accept(_DECLBASEVisitor *v);
    };
    class MultExpr : public AST
    {
    public:
        MultExpr(std::unique_ptr<Expr> lhs, Token op, std::unique_ptr<Expr> rhs);
        enum class Form
        {
            ATA,
        };
        std::unique_ptr<Expr> lhs;
        Token op;
        std::unique_ptr<Expr> rhs;
        Form form;
        virtual void accept(ExprVisitor *v);
    };
    class ParamList : public AST
    {
    public:
        ParamList(std::unique_ptr<_PLISTBASE> plist, Token comma, std::unique_ptr<_TYPEBASE> type, Token name);
        ParamList(std::unique_ptr<_TYPEBASE> type, Token name);
        enum class Form
        {
            ATAT,
            AT,
        };
        std::unique_ptr<_PLISTBASE> plist;
        Token comma;
        std::unique_ptr<_TYPEBASE> type;
        Token name;
        Form form;
        virtual void accept(_PLISTBASEVisitor *v);
    };
    class PrimaryExpr : public AST
    {
    public:
        PrimaryExpr(Token value);
        PrimaryExpr(Token oparn, std::unique_ptr<Expr> expr, Token cparn);
        enum class Form
        {
            T,
            TAT,
        };
        Token value;
        Token oparn;
        std::unique_ptr<Expr> expr;
        Token cparn;
        Form form;
        virtual void accept(ExprVisitor *v);
    };
    class RetStmt : public AST
    {
    public:
        RetStmt(Token ret, std::unique_ptr<Expr> expr, Token semi);
        enum class Form
        {
            TAT,
        };
        Token ret;
        std::unique_ptr<Expr> expr;
        Token semi;
        Form form;
        virtual void accept(_STMTBASEVisitor *v);
    };
    class Stmt : public AST
    {
    public:
        enum class Form
        {
        };
        Form form;
        virtual void accept(_STMTBASEVisitor *v);
    };
    class Stmts : public AST
    {
    public:
        Stmts(std::unique_ptr<_STMTBASE> stmts, std::unique_ptr<_STMTBASE> stmt);
        enum class Form
        {
            AA,
        };
        std::unique_ptr<_STMTBASE> stmts;
        std::unique_ptr<_STMTBASE> stmt;
        Form form;
        virtual void accept(_STMTBASEVisitor *v);
    };
    class TernaryExpr : public AST
    {
    public:
        TernaryExpr(std::unique_ptr<Expr> cond, Token quest, std::unique_ptr<Expr> trues, Token colon, std::unique_ptr<Expr> falses);
        enum class Form
        {
            ATATA,
        };
        std::unique_ptr<Expr> cond;
        Token quest;
        std::unique_ptr<Expr> trues;
        Token colon;
        std::unique_ptr<Expr> falses;
        Form form;
        virtual void accept(ExprVisitor *v);
    };
    class Type : public AST
    {
    public:
        Type(Token type);
        enum class Form
        {
            T,
        };
        Token type;
        Form form;
        virtual void accept(_TYPEBASEVisitor *v);
    };
    class UnaryExpr : public AST
    {
    public:
        UnaryExpr(Token op, std::unique_ptr<Expr> operand);
        enum class Form
        {
            TA,
        };
        Token op;
        std::unique_ptr<Expr> operand;
        Form form;
        virtual void accept(ExprVisitor *v);
    };
    class VarStmt : public AST
    {
    public:
        VarStmt(Token var, std::unique_ptr<_TYPEBASE> type, std::unique_ptr<_VSTMTIS> assignments, Token semi);
        enum class Form
        {
            TAAT,
        };
        Token var;
        std::unique_ptr<_TYPEBASE> type;
        std::unique_ptr<_VSTMTIS> assignments;
        Token semi;
        Form form;
        virtual void accept(_STMTBASEVisitor *v);
    };
    class VarStmtItem : public AST
    {
    public:
        VarStmtItem(Token name, Token equal, std::unique_ptr<Expr> expr);
        VarStmtItem(Token name);
        enum class Form
        {
            TTA,
            T,
        };
        Token name;
        Token equal;
        std::unique_ptr<Expr> expr;
        Form form;
        virtual void accept(_VSTMTIVisitor *v);
    };
    class VarStmtItems : public AST
    {
    public:
        VarStmtItems(std::unique_ptr<_VSTMTIS> items, Token comma, std::unique_ptr<_VSTMTI> item);
        VarStmtItems(std::unique_ptr<_VSTMTI> _);
        enum class Form
        {
            ATA,
            A,
        };
        std::unique_ptr<_VSTMTIS> items;
        Token comma;
        std::unique_ptr<_VSTMTI> item;
        std::unique_ptr<_VSTMTI> _;
        Form form;
        virtual void accept(_VSTMTISVisitor *v);
    };
// This code was autogenerated - see the utils/ directory

// ASTHEADER END
}
