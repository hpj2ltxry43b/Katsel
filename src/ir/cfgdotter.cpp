#include "ir/cfgdotter.h"
#include "ir/block.h"
#include "ir/value.h"

IR::CFGDotter::CFGDotter(llvm::raw_ostream &ostream): ostream(ostream) {}

// CFGDOTTER START
// The following code was autogenerated - see the utils/ directory
void IR::CFGDotter::visitReturn(IR::Instrs::Return *i) {
}
void IR::CFGDotter::visitGotoBr(IR::Instrs::GotoBr *i) {
    ostream << "        branch" << i << " -> " << "block" << i->to << " [label=\"to\"]\n";
}
void IR::CFGDotter::visitCondBr(IR::Instrs::CondBr *i) {
    ostream << "        branch" << i << " -> " << "block" << i->trueB << " [label=\"trueB\"]\n";
    ostream << "        branch" << i << " -> " << "block" << i->falseB << " [label=\"falseB\"]\n";
}
// This code was autogenerated - see the utils/ directory
// CFGDOTTER END
