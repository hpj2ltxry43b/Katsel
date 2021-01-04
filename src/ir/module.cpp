#include "ir/module.h"
#include "utils/format.h"
#include "ir/type.h"

IR::Module::Module(std::string const &name, ASTNS::AST *declAST): _declAST(declAST), _name(name) {}

ASTNS::AST* IR::Module::declAST() const {
    return _declAST;
}
std::string IR::Module::name() const {
    return _name;
}

DERIVE_DECLSYMBOL_ITEMS_IMPL(IR::Module)

// do the dsaccept methods here, even though that doesn't really make sense with the file structure but whatever
#define DSACCEPTMETHOD(cl) \
    void IR::cl::dsaccept(IR::DeclSymbolVisitor *v) { v->dsvisit##cl(this); }
DECLSYM_CLASS_LIST(DSACCEPTMETHOD)
#undef DSACCEPTMETHOD
