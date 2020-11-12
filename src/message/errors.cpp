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
class LocationVisitor : public ASTVisitor
{
public:
    // LOCVISITOR METHODS START

// The following code was autogenerated - see the utils/ directory
void visitAdditionexpr(ASTNS::Additionexpr *ast) override;
void visitArgs(ASTNS::Args *ast) override;
void visitAssignmentexpr(ASTNS::Assignmentexpr *ast) override;
void visitBinandexpr(ASTNS::Binandexpr *ast) override;
void visitBinnotexpr(ASTNS::Binnotexpr *ast) override;
void visitBinorexpr(ASTNS::Binorexpr *ast) override;
void visitBitandexpr(ASTNS::Bitandexpr *ast) override;
void visitBitorexpr(ASTNS::Bitorexpr *ast) override;
void visitBitshiftexpr(ASTNS::Bitshiftexpr *ast) override;
void visitBitxorexpr(ASTNS::Bitxorexpr *ast) override;
void visitBlock(ASTNS::Block *ast) override;
void visitCallexpr(ASTNS::Callexpr *ast) override;
void visitCompeqexpr(ASTNS::Compeqexpr *ast) override;
void visitComplgtexpr(ASTNS::Complgtexpr *ast) override;
void visitDecl(ASTNS::Decl *ast) override;
void visitDecls(ASTNS::Decls *ast) override;
void visitEmptystmt(ASTNS::Emptystmt *ast) override;
void visitExpression(ASTNS::Expression *ast) override;
void visitExprstmt(ASTNS::Exprstmt *ast) override;
void visitFunction(ASTNS::Function *ast) override;
void visitMultexpr(ASTNS::Multexpr *ast) override;
void visitParamlist(ASTNS::Paramlist *ast) override;
void visitPrimaryexpr(ASTNS::Primaryexpr *ast) override;
void visitRetstmt(ASTNS::Retstmt *ast) override;
void visitStmt(ASTNS::Stmt *ast) override;
void visitStmts(ASTNS::Stmts *ast) override;
void visitTernaryexpr(ASTNS::Ternaryexpr *ast) override;
void visitType(ASTNS::Type *ast) override;
void visitUnaryexpr(ASTNS::Unaryexpr *ast) override;
void visitVarstmt(ASTNS::Varstmt *ast) override;
void visitVarstmtitem(ASTNS::Varstmtitem *ast) override;
void visitVarstmtitems(ASTNS::Varstmtitems *ast) override;
// This code was autogenerated - see the utils/ directory

    // LOCVISITOR METHODS END

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
// location visitor method implementations {{{1
// LOCVISITOR IMPL START

// The following code was autogenerated - see the utils/ directory
void LocationVisitor::visitAdditionexpr(ASTNS::Additionexpr *ast)
{
    switch (ast->form)
    {
        case ASTNS::Additionexpr::Form::LHS_OP_RHS:
            retl = getL(ast->lhs.get());
            retf = getF(ast->lhs.get());
            retr = getR(ast->rhs.get());
            break;
    }
}
void LocationVisitor::visitArgs(ASTNS::Args *ast)
{
    switch (ast->form)
    {
        case ASTNS::Args::Form::ARGS_COMMA_EXPR:
            retl = getL(ast->args.get());
            retf = getF(ast->args.get());
            retr = getR(ast->expr.get());
            break;
        case ASTNS::Args::Form::EXPR:
            retl = getL(ast->expr.get());
            retf = getF(ast->expr.get());
            retr = getR(ast->expr.get());
            break;
    }
}
void LocationVisitor::visitAssignmentexpr(ASTNS::Assignmentexpr *ast)
{
    switch (ast->form)
    {
        case ASTNS::Assignmentexpr::Form::TARGET_EQUAL_VALUE:
            retl = getL(ast->target.get());
            retf = getF(ast->target.get());
            retr = getR(ast->value.get());
            break;
    }
}
void LocationVisitor::visitBinandexpr(ASTNS::Binandexpr *ast)
{
    switch (ast->form)
    {
        case ASTNS::Binandexpr::Form::LHS_OP_RHS:
            retl = getL(ast->lhs.get());
            retf = getF(ast->lhs.get());
            retr = getR(ast->rhs.get());
            break;
    }
}
void LocationVisitor::visitBinnotexpr(ASTNS::Binnotexpr *ast)
{
    switch (ast->form)
    {
        case ASTNS::Binnotexpr::Form::OP_OPERAND:
            retl = ast->op.start;
            retf = ast->op.sourcefile;
            retr = getR(ast->operand.get());
            break;
    }
}
void LocationVisitor::visitBinorexpr(ASTNS::Binorexpr *ast)
{
    switch (ast->form)
    {
        case ASTNS::Binorexpr::Form::LHS_OP_RHS:
            retl = getL(ast->lhs.get());
            retf = getF(ast->lhs.get());
            retr = getR(ast->rhs.get());
            break;
    }
}
void LocationVisitor::visitBitandexpr(ASTNS::Bitandexpr *ast)
{
    switch (ast->form)
    {
        case ASTNS::Bitandexpr::Form::LHS_OP_RHS:
            retl = getL(ast->lhs.get());
            retf = getF(ast->lhs.get());
            retr = getR(ast->rhs.get());
            break;
    }
}
void LocationVisitor::visitBitorexpr(ASTNS::Bitorexpr *ast)
{
    switch (ast->form)
    {
        case ASTNS::Bitorexpr::Form::LHS_OP_RHS:
            retl = getL(ast->lhs.get());
            retf = getF(ast->lhs.get());
            retr = getR(ast->rhs.get());
            break;
    }
}
void LocationVisitor::visitBitshiftexpr(ASTNS::Bitshiftexpr *ast)
{
    switch (ast->form)
    {
        case ASTNS::Bitshiftexpr::Form::LHS_OP_RHS:
            retl = getL(ast->lhs.get());
            retf = getF(ast->lhs.get());
            retr = getR(ast->rhs.get());
            break;
    }
}
void LocationVisitor::visitBitxorexpr(ASTNS::Bitxorexpr *ast)
{
    switch (ast->form)
    {
        case ASTNS::Bitxorexpr::Form::LHS_OP_RHS:
            retl = getL(ast->lhs.get());
            retf = getF(ast->lhs.get());
            retr = getR(ast->rhs.get());
            break;
    }
}
void LocationVisitor::visitBlock(ASTNS::Block *ast)
{
    switch (ast->form)
    {
        case ASTNS::Block::Form::OCURB_STMTS_CCURB:
            retl = ast->ocurb.start;
            retf = ast->ocurb.sourcefile;
            retr = ast->ccurb.end;
            break;
    }
}
void LocationVisitor::visitCallexpr(ASTNS::Callexpr *ast)
{
    switch (ast->form)
    {
        case ASTNS::Callexpr::Form::CALLEE_OPARN_ARGS_CPARN:
            retl = getL(ast->callee.get());
            retf = getF(ast->callee.get());
            retr = ast->cparn.end;
            break;
        case ASTNS::Callexpr::Form::CALLEE_OPARN_CPARN:
            retl = getL(ast->callee.get());
            retf = getF(ast->callee.get());
            retr = ast->cparn.end;
            break;
    }
}
void LocationVisitor::visitCompeqexpr(ASTNS::Compeqexpr *ast)
{
    switch (ast->form)
    {
        case ASTNS::Compeqexpr::Form::LHS_OP_RHS:
            retl = getL(ast->lhs.get());
            retf = getF(ast->lhs.get());
            retr = getR(ast->rhs.get());
            break;
    }
}
void LocationVisitor::visitComplgtexpr(ASTNS::Complgtexpr *ast)
{
    switch (ast->form)
    {
        case ASTNS::Complgtexpr::Form::LHS_OP_RHS:
            retl = getL(ast->lhs.get());
            retf = getF(ast->lhs.get());
            retr = getR(ast->rhs.get());
            break;
    }
}
void LocationVisitor::visitDecl(ASTNS::Decl *ast)
{
    switch (ast->form)
    {
    }
}
void LocationVisitor::visitDecls(ASTNS::Decls *ast)
{
    switch (ast->form)
    {
        case ASTNS::Decls::Form::DECLS_DECL:
            retl = getL(ast->decls.get());
            retf = getF(ast->decls.get());
            retr = getR(ast->decl.get());
            break;
        case ASTNS::Decls::Form::DECL:
            retl = getL(ast->decl.get());
            retf = getF(ast->decl.get());
            retr = getR(ast->decl.get());
            break;
    }
}
void LocationVisitor::visitEmptystmt(ASTNS::Emptystmt *ast)
{
    switch (ast->form)
    {
        case ASTNS::Emptystmt::Form::SEMI:
            retl = ast->semi.start;
            retf = ast->semi.sourcefile;
            retr = ast->semi.end;
            break;
    }
}
void LocationVisitor::visitExpression(ASTNS::Expression *ast)
{
    switch (ast->form)
    {
    }
}
void LocationVisitor::visitExprstmt(ASTNS::Exprstmt *ast)
{
    switch (ast->form)
    {
        case ASTNS::Exprstmt::Form::EXPR_SEMI:
            retl = getL(ast->expr.get());
            retf = getF(ast->expr.get());
            retr = ast->semi.end;
            break;
    }
}
void LocationVisitor::visitFunction(ASTNS::Function *ast)
{
    switch (ast->form)
    {
        case ASTNS::Function::Form::FUN_RETTY_NAME_OPARN_CPARN_BODY:
            retl = ast->fun.start;
            retf = ast->fun.sourcefile;
            retr = getR(ast->body.get());
            break;
        case ASTNS::Function::Form::FUN_RETTY_NAME_OPARN_PARAMLIST_CPARN_BODY:
            retl = ast->fun.start;
            retf = ast->fun.sourcefile;
            retr = getR(ast->body.get());
            break;
    }
}
void LocationVisitor::visitMultexpr(ASTNS::Multexpr *ast)
{
    switch (ast->form)
    {
        case ASTNS::Multexpr::Form::LHS_OP_RHS:
            retl = getL(ast->lhs.get());
            retf = getF(ast->lhs.get());
            retr = getR(ast->rhs.get());
            break;
    }
}
void LocationVisitor::visitParamlist(ASTNS::Paramlist *ast)
{
    switch (ast->form)
    {
        case ASTNS::Paramlist::Form::PLIST_COMMA_TYPE_NAME:
            retl = getL(ast->plist.get());
            retf = getF(ast->plist.get());
            retr = ast->name.end;
            break;
        case ASTNS::Paramlist::Form::TYPE_NAME:
            retl = getL(ast->type.get());
            retf = getF(ast->type.get());
            retr = ast->name.end;
            break;
    }
}
void LocationVisitor::visitPrimaryexpr(ASTNS::Primaryexpr *ast)
{
    switch (ast->form)
    {
        case ASTNS::Primaryexpr::Form::VALUE:
            retl = ast->value.start;
            retf = ast->value.sourcefile;
            retr = ast->value.end;
            break;
        case ASTNS::Primaryexpr::Form::OPARN_EXPR_CPARN:
            retl = ast->oparn.start;
            retf = ast->oparn.sourcefile;
            retr = ast->cparn.end;
            break;
    }
}
void LocationVisitor::visitRetstmt(ASTNS::Retstmt *ast)
{
    switch (ast->form)
    {
        case ASTNS::Retstmt::Form::RET_EXPR_SEMI:
            retl = ast->ret.start;
            retf = ast->ret.sourcefile;
            retr = ast->semi.end;
            break;
    }
}
void LocationVisitor::visitStmt(ASTNS::Stmt *ast)
{
    switch (ast->form)
    {
    }
}
void LocationVisitor::visitStmts(ASTNS::Stmts *ast)
{
    switch (ast->form)
    {
        case ASTNS::Stmts::Form::STMTS_STMT:
            retl = getL(ast->stmts.get());
            retf = getF(ast->stmts.get());
            retr = getR(ast->stmt.get());
            break;
    }
}
void LocationVisitor::visitTernaryexpr(ASTNS::Ternaryexpr *ast)
{
    switch (ast->form)
    {
        case ASTNS::Ternaryexpr::Form::COND_QUEST_TRUES_COLON_FALSES:
            retl = getL(ast->cond.get());
            retf = getF(ast->cond.get());
            retr = getR(ast->falses.get());
            break;
    }
}
void LocationVisitor::visitType(ASTNS::Type *ast)
{
    switch (ast->form)
    {
        case ASTNS::Type::Form::TYPE:
            retl = ast->type.start;
            retf = ast->type.sourcefile;
            retr = ast->type.end;
            break;
    }
}
void LocationVisitor::visitUnaryexpr(ASTNS::Unaryexpr *ast)
{
    switch (ast->form)
    {
        case ASTNS::Unaryexpr::Form::OP_OPERAND:
            retl = ast->op.start;
            retf = ast->op.sourcefile;
            retr = getR(ast->operand.get());
            break;
    }
}
void LocationVisitor::visitVarstmt(ASTNS::Varstmt *ast)
{
    switch (ast->form)
    {
        case ASTNS::Varstmt::Form::VAR_TYPE_ASSIGNMENTS_SEMI:
            retl = ast->var.start;
            retf = ast->var.sourcefile;
            retr = ast->semi.end;
            break;
    }
}
void LocationVisitor::visitVarstmtitem(ASTNS::Varstmtitem *ast)
{
    switch (ast->form)
    {
        case ASTNS::Varstmtitem::Form::NAME_EQUAL_EXPR:
            retl = ast->name.start;
            retf = ast->name.sourcefile;
            retr = getR(ast->expr.get());
            break;
        case ASTNS::Varstmtitem::Form::NAME:
            retl = ast->name.start;
            retf = ast->name.sourcefile;
            retr = ast->name.end;
            break;
    }
}
void LocationVisitor::visitVarstmtitems(ASTNS::Varstmtitems *ast)
{
    switch (ast->form)
    {
        case ASTNS::Varstmtitems::Form::ITEMS_COMMA_ITEM:
            retl = getL(ast->items.get());
            retf = getF(ast->items.get());
            retr = getR(ast->item.get());
            break;
        case ASTNS::Varstmtitems::Form::ITEM:
            retl = getL(ast->item.get());
            retf = getF(ast->item.get());
            retr = getR(ast->item.get());
            break;
    }
}
// This code was autogenerated - see the utils/ directory

// LOCVISITOR IMPL END
// constructors for location {{{1
Location::Location(Token const &t): start(t.start), end(t.end), file(t.sourcefile) {}
Location::Location(Value const &v): Location(v.ast) {}
Location::Location(std::string::iterator start, std::string::iterator end, File const *file): start(start), end(end), file(file) {}

Location::Location(ASTNS::AST *a)
{
    LocationVisitor locV;
    start = locV.getL(a);
    end = locV.getR(a);
    file = locV.getF(a);
}
// Error methods {{{1
Error::Error(MsgType type, Location const &location, std::string message): type(type), location(location), message(message) {}
Error& Error::underline(Underline const &underline)
{
    underlines.push_back(underline);
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

    for (Error::Underline const &u : underlines)
    {
        std::string::const_iterator begin = u.location.file->source.begin();
        for (int i = getLineN(begin, u.location.start); i <= getLineN(begin, u.location.end - 1); ++i)
            showlocs.push_back(showloc(u.location.file, i));
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
    int lastnr = -1;
    for (showloc const &sl : showlocs)
    {
        if (sl.first != lastfile)
        {
            std::cerr << pad << "> " << attr(A_FG_CYAN, sl.first->filename) << std::endl;
            lastnr = -1;
        }

        if (sl.second != lastnr + 1 && lastnr != -1)
        {
            std::ios origState (nullptr);
            origState.copyfmt(std::cerr);
            std::cerr << std::setw(maxlinepad - 1) << std::right << std::string(maxlinepad, '.') << " | ...\n";
            std::cerr.copyfmt(origState);
        }

        {
            std::ios origState (nullptr);
            origState.copyfmt(std::cerr);
            std::cerr << std::setw(maxlinepad - 1) << std::right << sl.second;
            std::cerr.copyfmt(origState);
        }

        std::cerr << " | ";

        std::string::const_iterator lstart, lend;
        getLine(lstart, lend, *sl.first, sl.second);

        std::vector<Underline const *> lchars;
        using lunderlinety = std::pair<Underline const *, int>;
        std::vector<lunderlinety> lunderlines;

        lchars.reserve(std::distance(lstart, lend));

        auto itInLoc = [](std::string::const_iterator const &i, Location const &l)
        {
            return i >= l.start && i < l.end;
        };

        bool needsecond = false;
        for (std::string::const_iterator i = lstart; i < lend; ++i)
        {
            for (Underline const &u : underlines)
                if (itInLoc(i, u.location))
                {
                    lunderlinety pair (&u, getColN(u.location.file->source.begin(), u.location.end - 1));
                    if (u.location.end - 1 == i && u.messages.size()) // can only ever be one location where this underline ends
                        lunderlines.push_back(pair);
                    needsecond = true;
                }

            Underline const *charu = nullptr;
            for (Underline const &u : underlines)
                if (itInLoc(i, u.location))
                {
                    charu = &u;
                    break;
                }

            lchars.push_back(charu);

            if (charu && charu->messages.size())
                std::cerr << attr(A_BOLD, attr(charu->messages[0].color, std::string(1, *i)));
            else if (charu)
                std::cerr << attr(A_BOLD, std::string(1, *i));
            else
                std::cerr << *i;
        }

        std::cerr << std::endl;

        if (needsecond)
        {
            std::cerr << pad << "| ";
            for (Underline const *&i : lchars)
            {
                if (i && i->messages.size()) // in a underline
                    std::cerr << attr(A_BOLD, attr(i->messages[0].color, std::string(1, i->ch)));
                else if (i)
                    std::cerr << attr(A_BOLD, std::string(1, i->ch));
                else
                    std::cerr << " ";
            }
            std::cerr << std::endl;

            if (lunderlines.size())
            {
                std::sort(lunderlines.begin(), lunderlines.end(), [](lunderlinety const &i1, lunderlinety const &i2)
                    {
                        return i1.second > i2.second; // sort in reverse
                    });

                for (auto i = lunderlines.begin(); i < lunderlines.end(); ++i)
                {
                    size_t msgi = 0;
                    for (Error::Underline::Message const &message : i->first->messages)
                    {
                        std::cerr << pad << "| ";
                        for (auto j = lunderlines.end() - 1; j >= i; --j)
                        {
                            int last = j + 1 == lunderlines.end() ? 0 : (j + 1)->second;
                            int diff = j->second - last;
                            if (!diff)
                                continue;

                            int pamt = diff - 1;

                            std::cerr << std::string(pamt, ' ');
                            if (j != i)
                                std::cerr << '|';
                            else
                                if (msgi == i->first->messages.size() - 1)
                                    std::cerr << '`';
                                else
                                    std::cerr << '|';
                        }

                        std::cerr << attr(message.color, "-- " + message.type) << ": " << message.message << std::endl;

                        ++msgi;
                    }
                }
            }
        }

        lastfile = sl.first;
        lastnr = sl.second;
    }
}
void Error::reportAbort()
{
    report();
    std::abort();
}
// Underline message methods {{{1
Error::Underline::Underline(Location const &location, char ch): location(location), ch(ch) {}
Error::Underline& Error::Underline::error(std::string const &message)
{
    return addmsg("error", A_FG_RED, message);
}
Error::Underline& Error::Underline::warning(std::string const &message)
{
    return addmsg("warning", A_FG_MAGENTA, message);
}
Error::Underline& Error::Underline::note(std::string const &message)
{
    return addmsg("note", A_FG_GREEN, message);
}
Error::Underline& Error::Underline::help(std::string const &message)
{
    return addmsg("help", A_FG_CYAN, message);
}
Error::Underline& Error::Underline::hint(std::string const &message)
{
    return addmsg("hint", A_FG_YELLOW, message);
}
Error::Underline& Error::Underline::message(std::string const &type, std::string const &message)
{
    return addmsg(type, A_FG_WHITE A_BOLD, message);
}
Error::Underline& Error::Underline::addmsg(std::string const &type, char const * const color, std::string const &message)
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
void invalidTok(std::string const &name, Token const &underline)
{
    Error(Error::MsgType::INTERR, underline, "invalid token for " + name)
        .underline(Error::Underline(underline, '!')
            .error("invalid token")
            .note("for " + name))
        .reportAbort();
}
void calledWithOpTyNEthis(std::string const &classN, std::string const &fnn, std::string const &opname, Value const &op)
{
    Error(Error::MsgType::INTERR, op, classN + "::" + fnn + " called with " + opname + " type != this")
        .underline(Error::Underline(op, '^')
            .error(opname + " type != this"))
        .reportAbort();
}
void outOSwitchDDefaultLab(std::string const &fnn, Location const &highlight)
{
    Error(Error::MsgType::INTERR, highlight, fnn + " went out of switch despite default label")
        .underline(Error::Underline(highlight, '^')
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
