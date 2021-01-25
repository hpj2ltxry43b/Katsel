#pragma once

#include "ir/instructionfwd.h"
#include "ir/value.h"
#include "ir/function.h"
#include "ir/unit.h"
#include "ir/visitor.h"
#include "mangle/mangler.h"

#include <unordered_map>

#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"

namespace Lower {
    class Lowerer : public IR::InstructionVisitor, public IR::BrVisitor, public IR::ValueVisitor {
    public:
        Lowerer(IR::Unit const &unit);

        // LOWER VISIT INSTR START
void visit(IR::Instrs::Store const &i) override;
void visit(IR::Instrs::Phi const &i) override;
void visit(IR::Instrs::Register const &i) override;
void visit(IR::Instrs::Or const &i) override;
void visit(IR::Instrs::And const &i) override;
void visit(IR::Instrs::Not const &i) override;
void visit(IR::Instrs::ICmpNE const &i) override;
void visit(IR::Instrs::ICmpEQ const &i) override;
void visit(IR::Instrs::ICmpLT const &i) override;
void visit(IR::Instrs::ICmpGT const &i) override;
void visit(IR::Instrs::ICmpLE const &i) override;
void visit(IR::Instrs::ICmpGE const &i) override;
void visit(IR::Instrs::IAdd const &i) override;
void visit(IR::Instrs::ISub const &i) override;
void visit(IR::Instrs::IMult const &i) override;
void visit(IR::Instrs::IDiv const &i) override;
void visit(IR::Instrs::IMod const &i) override;
void visit(IR::Instrs::INeg const &i) override;
void visit(IR::Instrs::FCmpNE const &i) override;
void visit(IR::Instrs::FCmpEQ const &i) override;
void visit(IR::Instrs::FCmpLT const &i) override;
void visit(IR::Instrs::FCmpGT const &i) override;
void visit(IR::Instrs::FCmpLE const &i) override;
void visit(IR::Instrs::FCmpGE const &i) override;
void visit(IR::Instrs::FAdd const &i) override;
void visit(IR::Instrs::FSub const &i) override;
void visit(IR::Instrs::FMult const &i) override;
void visit(IR::Instrs::FDiv const &i) override;
void visit(IR::Instrs::FMod const &i) override;
void visit(IR::Instrs::FNeg const &i) override;
void visit(IR::Instrs::BitXor const &i) override;
void visit(IR::Instrs::BitOr const &i) override;
void visit(IR::Instrs::BitAnd const &i) override;
void visit(IR::Instrs::BitNot const &i) override;
void visit(IR::Instrs::ShiftR const &i) override;
void visit(IR::Instrs::ShiftL const &i) override;
void visit(IR::Instrs::NoOpCast const &i) override;
void visit(IR::Instrs::IntToInt const &i) override;
void visit(IR::Instrs::IntToFloat const &i) override;
void visit(IR::Instrs::FloatToFloat const &i) override;
void visit(IR::Instrs::FloatToInt const &i) override;
void visit(IR::Instrs::Call const &i) override;
void visit(IR::Instrs::Addrof const &i) override;
void visit(IR::Instrs::DerefPtr const &i) override;
void visit(IR::Instrs::PtrArith const &i) override;
        // LOWER VISIT INSTR END
        // LOWER VISIT BRANCH START
void visit(IR::Instrs::Return const &i) override;
void visit(IR::Instrs::GotoBr const &i) override;
void visit(IR::Instrs::CondBr const &i) override;
        // LOWER VISIT BRANCH END

#define METHOD(cl, n) \
        void value_visit(IR::cl const &v) override;
        IR_VALUE_LIST(METHOD)
#undef METHOD

        void lower();
        bool objectify(llvm::raw_fd_ostream &ostream);

        void print_mod(llvm::raw_ostream &ostream);

        bool errored;

    private:
        void lower(IR::Function const &f);
        void lower(IR::Block const &b);
        llvm::Value& lower(IR::Value const &v);
        llvm::Value& lower(IR::ASTValue const &v);

        IR::Unit const &unit;

        llvm::LLVMContext context;
        llvm::IRBuilder<> builder;
        llvm::Module mod;
        llvm::legacy::FunctionPassManager fpm;

        std::unordered_map<NNPtr<IR::Instrs::Instruction const> , llvm::Value*> values;
        std::unordered_map<NNPtr<IR::Block const> , llvm::BasicBlock*> blocks;
        std::unordered_map<NNPtr<IR::Function const> , llvm::Function*> functions;

        Mangle::NameMangler mangler;

        int alloca_index;
        llvm::Function *cur_function;

        llvm::Value *lvret;
    };
}
