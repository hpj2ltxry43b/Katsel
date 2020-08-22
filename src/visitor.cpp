#include "visitor.h"
#include "ast.h"

// {{{ print
PrintVisitor::PrintVisitor(): indent(0), pindent(false) {}

void PrintVisitor::visitBinaryAST(const BinaryAST *ast)
{
    print("(");
    ast->last->accept(this);
    print(std::string(ast->op.start, ast->op.end));
    ast->rast->accept(this);
    print(")");
}

void PrintVisitor::visitTernaryOpAST(const TernaryOpAST *ast)
{
    print("(");
    ast->conditional->accept(this);
    print("?");
    ast->trueast->accept(this);
    print(":");
    ast->falseast->accept(this);
    print(")");
}

void PrintVisitor::visitUnaryAST(const UnaryAST *ast)
{
    print("(");
    print(std::string(ast->op.start, ast->op.end));
    ast->ast->accept(this);
    print(")");
}

void PrintVisitor::visitPrimaryAST(const PrimaryAST *ast)
{
    print(std::string(ast->value.start, ast->value.end));
}

void PrintVisitor::visitExprStmtAST(const ExprStmtAST *ast)
{
    print("ExprStmt: ");
    ast->ast->accept(this);
    print("\n");
}

void PrintVisitor::visitProgramAST(const ProgramAST *ast)
{
    print("Program:\n");
    ++indent;

    for (const std::unique_ptr<AST> &ast : ast->asts)
    {
        ast->accept(this);
    }

    --indent;
    print("\n");
}

void PrintVisitor::visitFunctionAST(const FunctionAST *ast)
{
    print("Function: name " + std::string(ast->name.start, ast->name.end) + ", ret ");
    ast->type->accept(this);
    if (ast->args)
    {
        print(", with args ");
        ast->args->accept(this);
    } else
    {
        print(", without args ");
    }

    print("\n");
    ++indent;
    ast->body->accept(this);
    print("\n");
}

void PrintVisitor::visitBlockAST(const BlockAST *ast)
{
    print("Block:\n");
    ++indent;

    for (const std::unique_ptr<AST> &ast : ast->stmts)
    {
        ast->accept(this);
    }
    --indent;
}

void PrintVisitor::visitTypeAST(const TypeAST *ast)
{
    print(std::string(ast->type.start, ast->type.end));
}

void PrintVisitor::visitArgAST(const ArgAST *ast)
{
    print("(Arg: " + std::string(ast->argname.start, ast->argname.end) + " with type ");
    ast->type->accept(this);
    print(")");
}

void PrintVisitor::visitArgsAST(const ArgsAST *ast)
{
    print("Args: \n");
    ++indent;

    for (const std::unique_ptr<AST> &ast : ast->args)
    {
        ast->accept(this);
    }
    --indent;
}

void PrintVisitor::print(std::string &str)
{
    for (auto i = str.begin(); i != str.end(); ++i)
    {
        if (pindent)
        {
            std::cout << std::string(indent * 2, ' ');
        }

        pindent = false;
        std::cout << *i;

        if (*i == '\n')
            pindent = true;
    }

    std::cout << std::flush;
}
void PrintVisitor::print(std::string &&str)
{
    print(str);
}
// }}}
