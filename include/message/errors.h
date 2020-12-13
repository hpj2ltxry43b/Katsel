#pragma once

#include "lex/tokentype.h"
#include "ir/type.h"
#include "ir/value.h"
#include "ast/ast.h"

#include <vector>
#include <sstream>

// Location struct {{{1
struct Location
{
    std::string::iterator start;
    std::string::iterator end;
    File const *file;

    Location(Token const &t);
    Location(std::string::iterator start, std::string::iterator end, File const *file);
    Location(IR::ASTValue const &v);
    Location(IR::ASTValue const *v);
    Location(ASTNS::AST *ast);
};
// Error class {{{1
class Error
{
public:
    void report() const;

    // ERRORFRIENDS START

// The following code was autogenerated - see the utils/ directory
    friend void E0000(Token const &tok);
    friend void E0001(Token const &tok);
    friend void E0002(Token const &tok);
    friend void E0003(Token const &tok);
    friend void E0004(Token const &tok);
    friend void E0005(Token const &tok);
    friend void E0006(Token const &tok);
    friend void E0007(Token const &tok);
    friend void E0008(Token const &tok);
    friend void E0009(Token const &tok);
    friend void E0010(Token const &tok);
    friend void E0011(Token const &tok);
    friend void E0100(Token const &last, Token const &lookahead, std::vector<std::string> const &expectations);
    friend void E0101(Token const &last, Token const &lookahead, std::string const &bestfix, std::vector<std::string> const &expectations);
    friend void E0102(Token const &last, Token const &lookahead, Token const &panicuntil, std::vector<std::string> const &expectations);
    friend void E0200(Token const &name, IR::Value *val);
    friend void E0201(IR::ASTValue const &lhs, IR::ASTValue const &rhs, Token const &op);
    friend void E0203(IR::ASTValue const &operand, Token const &_operator);
    friend void E0204(IR::ASTValue const &func, Token const &oparn);
    friend void E0205(IR::ASTValue const &func, Token const &oparn, ASTNS::ArgB *argsast, std::vector<IR::ASTValue> const &args);
    friend void E0206(IR::ASTValue const &arg, IR::Type const *expected);
    friend void E0207(Token const &sym);
    friend void E0208(IR::ASTValue const &truev, IR::ASTValue const &falsev, Token const &quest);
    friend void E0209(Token const &eq, IR::ASTValue const &lhs);
    friend void E0210(IR::ASTValue const &lhs, IR::ASTValue const &rhs, Token const &eq);
    friend void E0212(IR::ASTValue const &val, IR::Function *f);
    friend void E0214(Token const &name, IR::Register const *prev);
    friend void E0215(Token const &eq, Token const &name, IR::ASTValue const &init, IR::Register const *var);
    friend void E0216(ASTNS::AST *ast, IR::ASTValue v, IR::Type const *newty);
    friend void E0217(IR::ASTValue const &lhs, IR::ASTValue const &rhs, Token const &op);
    friend void E0218(Token const &name, IR::Register const *prev);
    friend void E0219(IR::ASTValue const &v);
// This code was autogenerated - see the utils/ directory

    // ERRORFRIENDS END

    static enum class Format
    {
        HUMAN, JSON
    } errformat;

private:
    struct Span
    {
        File const &file;
        std::string::iterator start, end;
    };

    class Underline
    {
    public:
        struct Message
        {
            std::string type;
            std::string message;
            char const * const color;
        };
        Location location;
        std::vector<Message> messages;
        char ch;

        Underline& error(std::string const &message);
        Underline& warning(std::string const &message);
        Underline& note(std::string const &message);
        Underline& help(std::string const &message);
        Underline& hint(std::string const &message);
        Underline& message(std::string const &type, std::string const &message);

        Underline(Location const &location, char ch);

    private:
        Underline& addmsg(std::string const &type, char const * const color, std::string const &mesage);
    };

    enum class MsgType
    {
        ERROR,
        WARNING,
    };

    Error(MsgType type, Location const &location, std::string message);

    Error& underline(Underline const &underline);
    Error& span(Location const &start, Location const &end);

    MsgType type;
    Location location;
    std::string message;

    std::vector<Underline> underlines;
    std::vector<Span> spans;
};

// other reporting functions {{{1
void invalidTok [[ noreturn ]] (std::string const &name, Token const &primary);
void calledWithOpTyNEthis [[ noreturn ]] (std::string const &classN, std::string const &fnn, std::string const &opname);
void outOSwitchDDefaultLab [[ noreturn ]] (std::string const &fnn, Location const &highlight);
void fCalled [[ noreturn ]] (std::string const &fnn);
void outOSwitchNoh [[ noreturn ]] (std::string const &fnn);

