#pragma once

#include "llvm/Support/raw_ostream.h"
#include <vector>

#include "ir/value.h"

namespace IR
{
    class Function;
    class Value;
    class Type;

    class Block;

    class InstructionVisitor;
    class BrVisitor;

    namespace Instrs
    {
        class Instruction : public Value
        {
        public:
            virtual ~Instruction() {};
            virtual void accept(InstructionVisitor *v) = 0;
        };

        class Br
        {
        public:
            virtual ~Br() {};
            virtual void accept(BrVisitor *v) = 0;
        };

        // INSTR CLASSES START
// The following code was autogenerated - see the utils/ directory
    class Store;
    class Phi;
    class Register;
    class Or;
    class And;
    class Not;
    class ICmpNE;
    class ICmpEQ;
    class ICmpLT;
    class ICmpGT;
    class ICmpLE;
    class ICmpGE;
    class IAdd;
    class ISub;
    class IMult;
    class IDiv;
    class IMod;
    class INeg;
    class FCmpNE;
    class FCmpEQ;
    class FCmpLT;
    class FCmpGT;
    class FCmpLE;
    class FCmpGE;
    class FAdd;
    class FSub;
    class FMult;
    class FDiv;
    class FMod;
    class FNeg;
    class BitXor;
    class BitOr;
    class BitAnd;
    class BitNot;
    class ShiftR;
    class ShiftL;
    class NoOpCast;
    class IntToInt;
    class IntToFloat;
    class FloatToFloat;
    class FloatToInt;
    class Call;
    class Addrof;
    class DerefPtr;
    class Return;
    class GotoBr;
    class CondBr;
    class Store : public Instruction
    {
    public:
        Store(ASTValue target, ASTValue value);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue target;
        ASTValue value;
    };
    class Phi : public Instruction
    {
    public:
        Phi(std::vector<std::pair<Block*,ASTValue>> prevs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        std::vector<std::pair<Block*,ASTValue>> prevs;
    };
    class Register : public Instruction, public DeclaredValue
    {
    public:
        Register(ASTNS::AST *_defAST, Type *ty);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTNS::AST* defAST() const override;
    private:
        ASTNS::AST* _defAST;
    public:
        Type *ty;
    };
    class Or : public Instruction
    {
    public:
        Or(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class And : public Instruction
    {
    public:
        And(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class Not : public Instruction
    {
    public:
        Not(ASTValue op);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue op;
    };
    class ICmpNE : public Instruction
    {
    public:
        ICmpNE(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class ICmpEQ : public Instruction
    {
    public:
        ICmpEQ(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class ICmpLT : public Instruction
    {
    public:
        ICmpLT(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class ICmpGT : public Instruction
    {
    public:
        ICmpGT(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class ICmpLE : public Instruction
    {
    public:
        ICmpLE(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class ICmpGE : public Instruction
    {
    public:
        ICmpGE(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class IAdd : public Instruction
    {
    public:
        IAdd(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class ISub : public Instruction
    {
    public:
        ISub(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class IMult : public Instruction
    {
    public:
        IMult(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class IDiv : public Instruction
    {
    public:
        IDiv(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class IMod : public Instruction
    {
    public:
        IMod(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class INeg : public Instruction
    {
    public:
        INeg(ASTValue op);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue op;
    };
    class FCmpNE : public Instruction
    {
    public:
        FCmpNE(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class FCmpEQ : public Instruction
    {
    public:
        FCmpEQ(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class FCmpLT : public Instruction
    {
    public:
        FCmpLT(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class FCmpGT : public Instruction
    {
    public:
        FCmpGT(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class FCmpLE : public Instruction
    {
    public:
        FCmpLE(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class FCmpGE : public Instruction
    {
    public:
        FCmpGE(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class FAdd : public Instruction
    {
    public:
        FAdd(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class FSub : public Instruction
    {
    public:
        FSub(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class FMult : public Instruction
    {
    public:
        FMult(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class FDiv : public Instruction
    {
    public:
        FDiv(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class FMod : public Instruction
    {
    public:
        FMod(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class FNeg : public Instruction
    {
    public:
        FNeg(ASTValue op);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue op;
    };
    class BitXor : public Instruction
    {
    public:
        BitXor(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class BitOr : public Instruction
    {
    public:
        BitOr(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class BitAnd : public Instruction
    {
    public:
        BitAnd(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class BitNot : public Instruction
    {
    public:
        BitNot(ASTValue op);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue op;
    };
    class ShiftR : public Instruction
    {
    public:
        ShiftR(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class ShiftL : public Instruction
    {
    public:
        ShiftL(ASTValue lhs, ASTValue rhs);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue lhs;
        ASTValue rhs;
    };
    class NoOpCast : public Instruction
    {
    public:
        NoOpCast(ASTValue op, Type *newt);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue op;
        Type *newt;
    };
    class IntToInt : public Instruction
    {
    public:
        IntToInt(ASTValue op, IntType *newt);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue op;
        IntType *newt;
    };
    class IntToFloat : public Instruction
    {
    public:
        IntToFloat(ASTValue op, FloatType *newt);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue op;
        FloatType *newt;
    };
    class FloatToFloat : public Instruction
    {
    public:
        FloatToFloat(ASTValue op, FloatType *newt);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue op;
        FloatType *newt;
    };
    class FloatToInt : public Instruction
    {
    public:
        FloatToInt(ASTValue op, IntType *newt);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue op;
        IntType *newt;
    };
    class Call : public Instruction
    {
    public:
        Call(Function *f, std::vector<ASTValue> args);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        Function *f;
        std::vector<ASTValue> args;
    };
    class Addrof : public Instruction
    {
    public:
        Addrof(Register *op);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        Register *op;
    };
    class DerefPtr : public Instruction
    {
    public:
        DerefPtr(ASTValue ptr);
        void accept(InstructionVisitor *v) override;
        std::string stringify() const override;
        IR::Type* type() const override;
        ASTValue ptr;
    };
    class Return : public Br
    {
    public:
        Return(Register *value);
        void accept(BrVisitor *v) override;
        Register *value;
    };
    class GotoBr : public Br
    {
    public:
        GotoBr(Block *to);
        void accept(BrVisitor *v) override;
        Block *to;
    };
    class CondBr : public Br
    {
    public:
        CondBr(ASTValue v, Block *trueB, Block *falseB);
        void accept(BrVisitor *v) override;
        ASTValue v;
        Block *trueB;
        Block *falseB;
    };
// This code was autogenerated - see the utils/ directory
        // INSTR CLASSES END
    }
}
