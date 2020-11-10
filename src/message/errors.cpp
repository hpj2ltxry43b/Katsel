#include "message/errors.h"
#include "visit/visitor.h"
#include "message/ansistuff.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

// getLine {{{1
void getLine(std::string::const_iterator &lstarto, std::string::const_iterator &lendo, File const &f, int linenr)
{
    int cline = linenr;
    std::string::const_iterator lstart = f.source.begin();
    for (; lstart < f.source.end() && cline > 1; ++lstart)
        if (*lstart == '\n')
            --cline;

    if (lstart == f.source.end())
    {
        lstarto = lendo = lstart;
    }

    auto lend (lstart);
    while (*lend != '\n' && lend != f.source.end())
        ++lend;

    lstarto = lstart;
    lendo = lend;
}
// getColN {{{1
int getColN(std::string::const_iterator const &start, std::string::const_iterator loc)
{
    int coln = 1;

    for (; loc != start && *loc != '\n'; ++coln, --loc)
        ;

    if (loc != start)
        ++loc, --coln;

    return coln;
}
// getLineN {{{1
int getLineN(std::string::const_iterator const &start, std::string::iterator loc)
{
    int linen = 0;
    while (loc >= start)
    {
        if (*loc == '\n') ++linen;
        --loc;
    }
    return linen + 1;
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
        retl = getL(a->type.get());
        retr = getR(a->assignments[a->assignments.size() - 1].get());
        retf = getF(a->type.get());
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
        retl = getL(a->type.get());
        retr = getR(a->assignments[a->assignments.size() - 1].get());
        retf = getF(a->type.get());
    }

public:
    template <typename AST>
    std::string::iterator getL(AST *a)
    {
        std::string::iterator cachedr = retr;
        File *cachedf = retf;
        a->accept(this);
        retr = cachedr;
        retf = cachedf;
        return retl;
    }
    template <typename AST>
    std::string::iterator getR(AST *a)
    {
        std::string::iterator cachedl = retl;
        File *cachedf = retf;
        a->accept(this);
        retl = cachedl;
        retf = cachedf;
        return retr;
    }
    template <typename AST>
    File* getF(AST *a)
    {
        std::string::iterator cachedl = retl;
        std::string::iterator cachedr = retr;
        a->accept(this);
        retl = cachedl;
        retr = cachedr;
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
Location::Location(ASTNS::AST *a)
{
#define CHECKTY(ty)                                             \
    ASTNS::ty *ty##casted;                                      \
    if ((ty##casted = dynamic_cast<ASTNS::ty*>(a)))             \
    {                                                           \
        LocationVisitor locV;                                   \
        start = locV.getL(ty##casted);                          \
        end = locV.getR(ty##casted);                            \
        file = locV.getF(ty##casted);                           \
        return;                                                 \
    }

    CHECKTY(Expr)
    CHECKTY(Decl)
    CHECKTY(Type)
    CHECKTY(Stmt)
#undef CHECKTY

    reportAbortNoh("Location constructor called with ast of unconvertible type"); // should be unreachable
}
// Error methods {{{1
Error::Error(MsgType type, Location const &location, std::string message): type(type), location(location), message(message) {}
Error& Error::primary(Primary const &primary)
{
    primaries.push_back(primary);
    return *this;
}
Error& Error::secondary(Location const &location)
{
    secondaries.push_back(location);
    return *this;
}
Error& Error::span(Location const &start, Location const &end)
{
    if (start.file != end.file)
        std::abort();

    spans.push_back(Span {*start.file, start.start, end.end});
    return *this;
}

// Error report method {{{1
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
void Error::report() const
{
    switch (type)
    {
        case Error::MsgType::ERROR:
            std::cerr << attr(A_BOLD A_FG_RED, "Error");
            break;
        case Error::MsgType::WARNING:
            std::cerr << attr(A_BOLD A_FG_MAGENTA, "Warning");
            break;
        case Error::MsgType::INTERR:
            std::cerr << "!!! - " << attr(A_BOLD A_FG_RED, "Internal error");
            break;
    }
    std::string::const_iterator const fstart = location.file->source.cbegin();
    std::cerr << " at " << attr(A_FG_CYAN, location.file->filename, true) << ":" << getLineN(fstart, location.start) << ":" << getColN(fstart, location.start) << A_RESET << ": " << message << "\n";

    using showloc = std::pair<const File*, int>; // in order to have a copy assignment constructor for sorting
    std::vector<showloc> showlocs;

    for (Span const &span : spans)
    {
        for (int i = getLineN(span.file.source.begin(), span.start); i < getLineN(span.file.source.begin(), span.end); ++i)
            showlocs.push_back(showloc(&span.file, i));
    }

    for (Error::Primary const &pr : primaries)
    {
        std::string::const_iterator begin = pr.location.file->source.begin();
        for (int i = getLineN(begin, pr.location.start); i <= getLineN(begin, pr.location.end - 1); ++i)
            showlocs.push_back(showloc(pr.location.file, i));
    }
    for (Location const &s : secondaries)
    {
        std::string::const_iterator begin = s.file->source.begin();
        for (int i = getLineN(begin, s.start); i <= getLineN(begin, s.end - 1); ++i)
            showlocs.push_back(showloc(s.file, i));
    }

    std::sort(showlocs.begin(), showlocs.end(), [](showloc const &a, showloc const &b) {
                return a.second < b.second;
            });
    std::stable_sort(showlocs.begin(), showlocs.end(), [](showloc const &a, showloc const &b) {
                return a.first->filename < b.first->filename;
            });

    int maxlinepad = 0;
    // i + 1 < instead of i < size - 1 because - 1 can overflow to the highest value and become true
    for (size_t i = 0; i + 1 < showlocs.size(); )
    {
        if (showlocs[i].first == showlocs[i + 1].first && showlocs[i].second == showlocs[i + 1].second)
            showlocs.erase(showlocs.begin() + i + 1);
        else
            ++i;
    }

    for (showloc const &s : showlocs)
    {
        int linew = 1, linenr = s.second;
        while (linenr /= 10)
            ++linew;
        maxlinepad = std::max(linew, maxlinepad);
    }

    std::string pad (maxlinepad + 1, ' ');
    File const *lastfile = nullptr;
    for (showloc const &sl : showlocs)
    {
        using lprimaryty = std::pair<Error::Primary const *, int>;
        std::vector<lprimaryty> lprimaries;
        if (sl.first != lastfile)
            std::cerr << pad << "> " << attr(A_FG_CYAN, sl.first->filename) << std::endl;

        {
            std::ios origState (nullptr);
            origState.copyfmt(std::cerr);
            std::cerr << std::setw(maxlinepad - 1) << std::right << sl.second;
            std::cerr.copyfmt(origState);
        }

        std::cerr << " | ";

        std::string::const_iterator lstart, lend;
        getLine(lstart, lend, *sl.first, sl.second);

        using inprimsec = std::pair<bool, bool>;
        std::vector<inprimsec> chars;
        chars.reserve(std::distance(lstart, lend));

        auto itInLoc = [](std::string::const_iterator const &i, Location const &l)
        {
            return i >= l.start && i < l.end;
        };

        bool needsecond = false;
        for (std::string::const_iterator i = lstart; i < lend; ++i)
        {
            bool insec, inprim = insec = false;
            for (Primary const &prim : primaries)
                if (itInLoc(i, prim.location))
                {
                    inprim = true;
                    lprimaryty pair (&prim, getColN(prim.location.file->source.begin(), prim.location.end - 1));
                    if (prim.location.end - 1 == i && std::find(lprimaries.begin(), lprimaries.end(), pair) == lprimaries.end())
                        lprimaries.push_back(pair);
                }

            for (Location const &sec: secondaries)
                if (itInLoc(i, sec))
                {
                    insec = true;
                    break;
                }

            needsecond |= inprim || insec;

            chars.push_back(std::make_pair(inprim, insec));

            if (inprim)
                std::cerr << attr(A_FG_RED A_BOLD, std::string(1, *i));
            else if (insec)
                std::cerr << attr(A_FG_GREEN, std::string(1, *i));
            else
                std::cerr << *i;
        }

        std::cerr << std::endl;

        if (needsecond)
        {
            std::cerr << pad << "| ";
            for (inprimsec const &i : chars)
            {
                if (i.first) // in a primary
                    std::cerr << attr(A_FG_RED A_BOLD, "^");
                else if (i.second) // in a seconary
                    std::cerr << attr(A_FG_GREEN, "-");
                else
                    std::cerr << " ";
            }
            std::cerr << std::endl;

            if (lprimaries.size())
            {
                std::sort(lprimaries.begin(), lprimaries.end(), [](lprimaryty const &i1, lprimaryty const &i2)
                    {
                        return i1.second > i2.second; // sort in reverse
                    });

                for (auto i = lprimaries.begin(); i < lprimaries.end(); ++i)
                {
                    size_t msgi = 0;
                    for (Error::Primary::Message const &message : i->first->messages)
                    {
                        std::cerr << pad << "| ";
                        for (auto j = lprimaries.end() - 1; j >= i; --j)
                        {
                            int last = j + 1 == lprimaries.end() ? 0 : (j + 1)->second;
                            int diff = j->second - last;
                            if (!diff)
                                continue;

                            int pamt = diff - 1;

                            std::cerr << std::string(pamt, ' ');
                            if (j != i)
                                std::cerr << '|';
                        }

                        if (msgi == i->first->messages.size() - 1)
                            std::cerr << "`";
                        else
                            std::cerr << "|";
                        std::cerr << "-- " << attr(message.color, message.type) << ": " << message.message << std::endl;

                        ++msgi;
                    }
                }
            }
        }

        lastfile = sl.first;
    }
}
void Error::reportAbort()
{
    report();
    std::abort();
}
// Primary message methods {{{1
Error::Primary::Primary(Location const &location): location(location) { }
Error::Primary& Error::Primary::error(std::string const &message)
{
    return addmsg("error", A_FG_RED, message);
}
Error::Primary& Error::Primary::warning(std::string const &message)
{
    return addmsg("warning", A_FG_MAGENTA, message);
}
Error::Primary& Error::Primary::note(std::string const &message)
{
    return addmsg("note", A_FG_GREEN, message);
}
Error::Primary& Error::Primary::help(std::string const &message)
{
    return addmsg("help", A_FG_CYAN, message);
}
Error::Primary& Error::Primary::hint(std::string const &message)
{
    return addmsg("hint", A_FG_YELLOW, message);
}
Error::Primary& Error::Primary::message(std::string const &type, std::string const &message)
{
    return addmsg(type, A_FG_WHITE A_BOLD, message);
}
Error::Primary& Error::Primary::addmsg(std::string const &type, char const * const color, std::string const &message)
{
    messages.push_back(Message {type, message, color});
    return *this;
}
// other internal errors {{{1
void reportAbortNoh(std::string const &message)
{
    std::cerr << "!!! - " << attr(A_BOLD A_FG_RED, "Internal error") << " " << message << std::endl;
    std::abort();
}
void invalidTok(std::string const &name, Token const &primary)
{
    Error(Error::MsgType::INTERR, primary, "invalid token for " + name)
        .primary(Error::Primary(primary)
            .error("invalid token")
            .note("for " + name))
        .reportAbort();
}
void calledWithOpTyNEthis(std::string const &classN, std::string const &fnn, std::string const &opname, Value const &op)
{
    Error(Error::MsgType::INTERR, op, classN + "::" + fnn + " called with " + opname + " type != this")
        .primary(Error::Primary(op)
            .error(opname + " type != this"))
        .reportAbort();
}
void outOSwitchDDefaultLab(std::string const &fnn, Location const &highlight)
{
    Error(Error::MsgType::INTERR, highlight, fnn + " went out of switch despite default label")
        .primary(Error::Primary(highlight)
            .error("out of switch"))
        .reportAbort();
}
void fCalled(std::string const &fnn)
{
    reportAbortNoh(fnn + " called");
}
void outOSwitchNoh(std::string const &fnn)
{
    reportAbortNoh(fnn + " went out of switch");
}
// shorthands for errors {{{1
Error Error::makeBasicErr(Location const &l, std::string message)
{
    return Error(Error::MsgType::ERROR, l, message)
        .primary(Error::Primary(l)
            .error(message));
}
