#include "message/errors.h"
#include "visit/visitor.h"
#include "message/ansistuff.h"
#include <iostream>
#include <cstdlib>
#include <sstream>

// getLine {{{1
Location getLine(Location const &l)
{
    auto linestart (l.start);
    while (linestart != l.file->source.begin() && *linestart != '\n') --linestart; // until *linestart is \n
    // once *linestart is \n then go forward once

    // if linestart == l.file.source.begin(), then loop stopped
    // because iterator hit beginning of sourcefile.source, not
    // because it hit \n, so there is no need to consume the \n
    if (linestart != l.file->source.begin())
        ++linestart;

    auto lineend (l.end);
    while (lineend != l.file->source.end() && *lineend != '\n') ++lineend;
    // *lineend should be \n

    return Location(linestart, lineend, l.file);
}
// getColN {{{1
int getColN(std::string::const_iterator const &start, std::string::iterator loc)
{
    int coln = 1;
    --loc;

    for (; loc != start && *loc != '\n'; ++coln, --loc)
        ;

    if (loc != start)
        ++loc, --coln;

    return coln + 1;
}
// getLineN {{{1
int getLineN(std::string::const_iterator const &start, std::string::iterator loc)
{
    int linen = 0;
    while (loc != start)
    {
        if (*loc == '\n') ++linen;
        --loc;
    }
    return linen;
}
// LocationVisitor {{{1
class LocationVisitor :
    public ExprVisitor,
    public DeclVisitor,
    public TypeVisitor,
    public StmtVisitor
{
    void visitBinaryExpr(ASTNS::BinaryExpr *a)
    {
        retl = getL(a->lhs.get());
        retr = getR(a->rhs.get());
        retf = getF(a->lhs.get());
    }
    void visitTernaryExpr(ASTNS::TernaryExpr *a)
    {
        retl = getL(a->condition.get());
        retr = getR(a->falses.get());
        retf = getF(a->falses.get());
    }
    void visitUnaryExpr(ASTNS::UnaryExpr *a)
    {
        retl = a->op.start;
        retr = getR(a->operand.get());
        retf = a->op.sourcefile;
    }
    void visitPrimaryExpr(ASTNS::PrimaryExpr *a)
    {
        retl = a->value.start;
        retr = a->value.end;
        retf = a->value.sourcefile;
    }
    void visitCallExpr(ASTNS::CallExpr *a)
    {
        retl = getL(a->func.get());
        retr = getR(a->func.get()); // TODO: get closing paren token
        retf = getF(a->func.get());
    }
    void visitFunctionDecl(ASTNS::FunctionDecl *a)
    {
        retl = a->name.start; // TODO: get fun token
        retr = getR(a->block.get());
        retf = a->name.sourcefile;
    }
    void visitGlobalVarDecl(ASTNS::GlobalVarDecl *a)
    {
        retl = a->name.start; // TODO
        retr = getR(a->value.get());
        retf = a->name.sourcefile;
    }
    void visitBaseType(ASTNS::BaseType *a)
    {
        retl = a->type.start;
        retr = a->type.end;
        retf = a->type.sourcefile;
    }
    void visitBlockStmt(ASTNS::BlockStmt *a)
    {
        retl = getL(a->stmts[0].get()); // TODO
        retr = getR(a->stmts[a->stmts.size() - 1].get()); // TODO
        retf = getF(a->stmts[0].get());
    }
    void visitExprStmt(ASTNS::ExprStmt *a)
    {
        retl = getL(a->expr.get());
        retr = getR(a->expr.get());
        retf = getF(a->expr.get());
    }
    void visitReturnStmt(ASTNS::ReturnStmt *a)
    {
        retl = getL(a->val.get()); // TODO
        retr = getR(a->val.get());
        retf = getF(a->val.get());
    }
    void visitVarStmt(ASTNS::VarStmt *a)
    {
        retl = a->name.start; // TODO
        retr = getR(a->assign.get());
        retf = a->name.sourcefile;
    }

public:
    template <typename AST>
    std::string::iterator getL(AST *a)
    {
        a->accept(this);
        return retl;

    }
    template <typename AST>
    std::string::iterator getR(AST *a)
    {
        a->accept(this);
        return retr;
    }
    template <typename AST>
    File* getF(AST *a)
    {
        a->accept(this);
        return retf;
    }

private:
    std::string::iterator retl;
    std::string::iterator retr;
    File *retf;
};

// constructors for location {{{1
Location::Location(Token const &t): start(t.start), end(t.end), file(t.sourcefile) {}
Location::Location(Value const &v): Location(v.ast) {}
Location::Location(std::string::iterator start, std::string::iterator end, File const *file): start(start), end(end), file(file) {}

Location::Location(ASTNS::Expr *a)
{
    LocationVisitor locV;
    start = locV.getL(a);
    end = locV.getR(a);
    file = locV.getF(a);
}
Location::Location(ASTNS::Decl *a)
{
    LocationVisitor locV;
    start = locV.getL(a);
    end = locV.getR(a);
    file = locV.getF(a);
}
Location::Location(ASTNS::Type *a)
{
    LocationVisitor locV;
    start = locV.getL(a);
    end = locV.getR(a);
    file = locV.getF(a);
}
Location::Location(ASTNS::Stmt *a)
{
    LocationVisitor locV;
    start = locV.getL(a);
    end = locV.getR(a);
    file = locV.getF(a);
}
// Reporting functions {{{1
// helpers {{{2
// apply attr to string {{{3
inline std::string attr(std::string const &ansicode, std::string const &message, bool noreset=false)
{
    if (ansiCodesEnabled())
    {
        if (noreset)
            return ansicode + message;
        else
            return ansicode + message + A_RESET;
    }
    else
        return message;
}
// print message types {{{3
void printErr()
{
    std::cout << attr(A_BOLD A_FG_RED, "Error");
}
void printWarn()
{
    std::cout << attr(A_BOLD A_FG_MAGENTA, "Warning");
}
void printDebug()
{
    std::cout << attr(A_BOLD A_FG_CYAN, "Debug");
}
void printIntErr()
{
    std::cout << "!!! - " << attr(A_BOLD A_FG_RED, "Internal error");
}
// print message locations {{{3
void printAtFileLC(Location const &l)
{
    std::string::const_iterator const fstart = l.file->source.cbegin();
    std::cout << " at " << attr(A_FG_CYAN, l.file->filename, true) << ":" << getLineN(fstart, l.start) << ":" << getColN(fstart, l.start) << A_RESET;
}
// print lines and underlines {{{3
void printLine(Location const &l)
{
    Location line (getLine(l));
    std::cout << attr(A_DIM, " | ") << std::string(line.start, line.end) << "\n";
}
void printUnderline(int startc, int endc)
{
    std::cout << attr(A_DIM, " |");
    std::cout << attr(A_FG_GREEN, " ", true);
    for (int i = 1; i < endc; ++i) std::cout << (i >= startc && i < endc ? '^' : ' ');
    std::cout << A_RESET "\n";
}
void printUnderline(Location const &l)
{
    std::string::const_iterator const begin (l.file->source.cbegin());
    int startc = getColN(begin, l.start);
    int endc = getColN(begin, l.end);
    printUnderline(startc, endc);
}
// print other things {{{3
void printColon()
{
    std::cout << ": ";
}
// print header line {{{3
void printHeaderLine(void (*msgType)(), Location loc, std::string const &message)
{
    msgType();
    printAtFileLC(loc);
    printColon();
    std::cout << message << "\n";
}
// common patterns {{{2
void printLineAndUnder(Location const &l)
{
    printLine(l);
    printUnderline(l);
}
// actually reporting errors {{{2
namespace msg
{
#define BASIC_ERR_AT_TOK(name, func, message) void name(Token const &t) \
    {\
        printHeaderLine(&func, t, message);\
        printLineAndUnder(t);\
    }

    BASIC_ERR_AT_TOK(reportLexTok, printErr, t.message)
    BASIC_ERR_AT_TOK(expectedPrimaryOrUnary, printErr, "Expected primary token or unary operator")
    BASIC_ERR_AT_TOK(expectedType, printErr, "Expected type")
    BASIC_ERR_AT_TOK(expectedDecl, printErr, "Expected declaration")

    void expectedTokGotTok(Token const &t, TokenType got, TokenType expected)
    {
        std::stringstream ss;
        ss << "Unexpected token " << stringifyTokenType(got) << ", expected " << stringifyTokenType(expected);
        printHeaderLine(&printErr, t, ss.str());
        printLineAndUnder(t);
    }
    void reportAssertConsumeErr(Token const &t, std::string const &message)
    {
        printHeaderLine(&printErr, t, message);
        printLineAndUnder(t);
    }

    BASIC_ERR_AT_TOK(duplicateFunction, printErr, "Cannot redefine function")
    BASIC_ERR_AT_TOK(cannotRedefineVariable, printErr, "Cannot redefine variable")
    void typeNoOp(Value const &lhs, Token const &op)
    {
        std::stringstream ss;
        ss << "Type \"" << lhs.type->stringify() << "\" does not support operator \"" << tokenToStr(op) << "\"";
        printHeaderLine(&printErr, lhs, ss.str());
        printLineAndUnder(op);
    }
    void invalidROperand(Value const &lop, Token const &op, Value const &rop)
    {
        std::stringstream ss;
        ss << "Invalid right operand of type \"" << rop.type->stringify() << "\" to operator \"" << tokenToStr(op) << "\" with left operand of type \"" << lop.type->stringify() << "\"";
        printHeaderLine(&printErr, lop, ss.str());
        printLineAndUnder(op);
    }
    void invalidCast(Value const &v, Type *ety)
    {
        std::stringstream ss;
        ss << "Invalid cast from type \"" << v.type->stringify() << "\" to \"" << ety->stringify() << "\"";
        printHeaderLine(&printErr, v, ss.str());
        printLineAndUnder(v);
    }
    BASIC_ERR_AT_TOK(undefVar, printErr, "Name is not defined")
    void cannotCall(Value const &v)
    {
        printHeaderLine(&printErr, v, "Cannot call non-function");
        printLineAndUnder(v);
    }
    void invalidAssign(Value const &target, Token const &eq)
    {
        printHeaderLine(&printErr, target, "Invalid assignment target");
        printLineAndUnder(target);
    }
    void voidVarNotAllowed(Location const &voidTok) {
        printHeaderLine(&printErr, voidTok, "Variable cannot be of type void");
        printLineAndUnder(voidTok);
    }
    void cannotPick2Tys(Value const &v1, Value const &v2)
    {
        printHeaderLine(&printErr, v1, "Cannot cast two values to same type");
        printLineAndUnder(v1);
        printUnderline(v2);
    }
    void wrongNOfArgs(ASTNS::CallExpr *a)
    {
        printHeaderLine(&printErr, a, "Wrong number of arguments to function");
        printLineAndUnder(a);
    }
    void incorrectArg(Value const &v, Type *expected)
    {
        std::stringstream ss;
        ss << "Incorrect argument to function call, expected \"" << expected->stringify() << "\" but got \"" << v.type->stringify() << "\"";
        printHeaderLine(&printErr, v, ss.str());
        printLineAndUnder(v);
    }

    BASIC_ERR_AT_TOK(noNullPtrLit, printErr, "Nullptr literals are currently not supported")
    BASIC_ERR_AT_TOK(noStringLit, printErr, "String literals are currently not supported")
    void invalidTok(std::string const &name, Token const &primary)
    {
        std::stringstream ss;
        ss << "Invalid " << name;
        printHeaderLine(&printIntErr, primary, ss.str());
        printLineAndUnder(primary);
        std::abort();
    }
    void calledWithOpTyNEthis(std::string const &classN, std::string const &fnn, std::string const &opname, Value const &op)
    {
        std::stringstream ss;
        ss << classN << "::" << fnn << " called with " << opname << " type != this";
        printHeaderLine(&printIntErr, op, ss.str());
        printLineAndUnder(op);
        std::abort();
    }
    void outOSwitchDDefaultLab(std::string const &fnn, Location const &highlight)
    {
        std::stringstream ss;
        ss << fnn << " went out of switch despite default label";
        printHeaderLine(&printIntErr, highlight, ss.str());
        printLineAndUnder(highlight);
        std::abort();
    }
    void fCalled(std::string const &fnn)
    {
        std::stringstream ss;
        printIntErr();
        printColon();
        std::cout << fnn << " called\n";
        std::abort();
    }
    void outOSwitchNoh(std::string const &fnn)
    {
        printIntErr();
        printColon();
        std::cout << fnn << " went out of switch\n";
        std::abort();
    }

    void intErrNoh(std::string const &message)
    {
        printIntErr();
        printColon();
        std::cout << message << "\n";
        std::abort();
    }
}
