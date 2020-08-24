#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "token.h"
#include "visitor.h"

class AST
{
public:
    virtual ~AST() {}

    virtual void accept(Visitor *v) = 0;
};

class BinaryAST : public AST
{
public:
    BinaryAST(Token op, std::unique_ptr<AST> last, std::unique_ptr<AST> rast);
    void accept(Visitor *v) override;

    Token op;
    std::unique_ptr<AST> last;
    std::unique_ptr<AST> rast;
};

class TernaryOpAST : public AST
{
public:
    TernaryOpAST(std::unique_ptr<AST> conditional, std::unique_ptr<AST> trueast, std::unique_ptr<AST> falseast);
    void accept(Visitor *v) override;

    std::unique_ptr<AST> conditional;
    std::unique_ptr<AST> trueast;
    std::unique_ptr<AST> falseast;
};

class UnaryAST : public AST
{
public:
    UnaryAST(Token op, std::unique_ptr<AST> ast);
    void accept(Visitor *v) override;

    Token op;
    std::unique_ptr<AST> ast;
};

class PrimaryAST : public AST
{
public:
    PrimaryAST(Token value);
    void accept(Visitor *v) override;

    Token value;
};

class ExprStmtAST : public AST
{
public:
    ExprStmtAST(std::unique_ptr<AST> ast);
    void accept(Visitor *v) override;

    std::unique_ptr<AST> ast;
};

class ProgramAST : public AST
{
public:
    ProgramAST(std::vector<std::unique_ptr<AST>> &asts);
    void accept(Visitor *v) override;

    std::vector<std::unique_ptr<AST>> asts;
};

class FunctionAST : public AST
{
public:
    FunctionAST(std::unique_ptr<AST> type, Token name, std::unique_ptr<AST> params, std::unique_ptr<AST> body);
    void accept(Visitor *v) override;

    std::unique_ptr<AST> type;
    Token name;
    std::unique_ptr<AST> params;
    std::unique_ptr<AST> body;
};

class BlockAST : public AST
{
public:
    BlockAST(std::vector<std::unique_ptr<AST>> &stmts);
    void accept(Visitor *v) override;

    std::vector<std::unique_ptr<AST>> stmts;
};

class TypeAST : public AST
{
public:
    TypeAST(Token type);
    void accept(Visitor *v) override;

    Token type;
};

class ParamAST : public AST
{
public:
    ParamAST(std::unique_ptr<AST> type, Token paramname);
    void accept(Visitor *v) override;

    std::unique_ptr<AST> type;
    Token paramname;
};

class ParamsAST : public AST
{
public:
    ParamsAST(std::vector<std::unique_ptr<AST>> &params);
    void accept(Visitor *v) override;

    std::vector<std::unique_ptr<AST>> params;
};

class VarStmtAST : public AST
{
public:
    VarStmtAST(std::unique_ptr<AST> type, Token name, std::unique_ptr<AST> expression);
    void accept(Visitor *v) override;

    std::unique_ptr<AST> type;
    Token name;
    std::unique_ptr<AST> expression;
};

class AssignAST : public AST
{
public:
    AssignAST(std::unique_ptr<AST> lhs, std::unique_ptr<AST> rhs, Token equalSign);
    void accept(Visitor *v) override;

    std::unique_ptr<AST> lhs;
    std::unique_ptr<AST> rhs;
    Token equalSign;
};

class VariableRefAST : public AST
{
public:
    VariableRefAST(Token var);
    void accept(Visitor *v) override;

    Token var;
};

class ReturnStmtAST : public AST
{
public:
    ReturnStmtAST(std::unique_ptr<AST> expr);
    void accept(Visitor *v) override;

    std::unique_ptr<AST> expr;
};

class ArgAST : public AST
{
public:
    ArgAST(std::unique_ptr<AST> expr);
    void accept(Visitor *v) override;

    std::unique_ptr<AST> expr;
};

class ArgsAST : public AST
{
public:
    ArgsAST(std::vector<std::unique_ptr<AST>> &args);
    void accept(Visitor *v) override;

    std::vector<std::unique_ptr<AST>> args;
};

class CallAST : public AST
{
public:
    CallAST(std::unique_ptr<AST> varrefast, std::unique_ptr<AST> arglistast);
    void accept(Visitor *v) override;

    std::unique_ptr<AST> varrefast;
    std::unique_ptr<AST> arglistast;
};

