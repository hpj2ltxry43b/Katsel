#pragma once

#include "ir/block.h"
#include <string>
#include <cstddef>
#include <vector>
#include "ast/ast.h"

namespace IR
{
    class Type;
    class BuiltinType;
    class FunctionType;

    class Value
    {
    public:
        virtual ~Value() {};
        virtual std::string stringify() const = 0;

        virtual Type* type() const = 0;
    };

    class DeclaredValue
    {
    public:
        virtual ASTNS::AST* defAST() const = 0;
    };

    class Register : public Value, public DeclaredValue
    {
    public:
        Register(int index, Type *type, ASTNS::AST *defAST);

        std::string stringify() const override;
        void definition(llvm::raw_ostream &os) const;
        ASTNS::AST* defAST() const override;

        Type* type() const override;

    private:
        ASTNS::AST* _defAST;
        int index;
        Type *ty;
    };

    class TempRegister : public Value
    {
    public:
        TempRegister(int index, Type *type);

        std::string stringify() const override;

        Type* type() const override;

    private:
        int index;
        Type *ty;
    };

    class Function : public Value, public DeclaredValue
    {
    public:
        Function(FunctionType *ty, std::string name, ASTNS::FunctionDecl *defAST);

        void add(std::unique_ptr<Block> block);

        std::string stringify() const override;
        void definition(llvm::raw_ostream &os) const;
        ASTNS::FunctionDecl* defAST() const override;
        void cfgDot(llvm::raw_ostream &os) const;

        Type* type() const override;

        std::vector<std::unique_ptr<Block>> blocks;
        std::vector<std::unique_ptr<Register>> registers;
        std::vector<std::unique_ptr<TempRegister>> tempregisters;

        Block* addBlock(std::string name);
        Register* addRegister(Type *ty, ASTNS::AST *defAST);
        TempRegister* addTempRegister(Type *ty);

        FunctionType *ty;
        std::string name;

        bool prototypeonly;

    private:
        ASTNS::FunctionDecl *_defAST;

        size_t blocki;
        size_t regi;
        size_t tempregi;
    };

    class ConstInt : public Value
    {
    public:
        ConstInt(BuiltinType *ty, uint64_t val);

        std::string stringify() const override;

        Type* type() const override;

        uint64_t val;

    private:
        BuiltinType *ty;
    };

    struct ASTValue
    {
        // Because multiple ASTs can evaluate to the same value (same pointer)
        // (see primary expressions (multiple PrimaryASTs can evaluate to the same register),
        // also especially since ConstInts are uniqued together),
        // this struct allows values to be associated with an ast, and more importantly,
        // it isn't supposed to be heap-allocated and uniqued, so one value can have multiple ASTs
        Value *val;
        ASTNS::AST *ast;

        inline ASTValue(Value *val, ASTNS::AST *ast): val(val), ast(ast) {}
        inline ASTValue(): val(nullptr), ast(nullptr) {}

        explicit inline operator bool() const
        {
            return val;
        }

        inline Type* type() const
        {
            return val->type();
        }
        inline std::string stringify() const
        {
            return val->stringify();
        }
    };
}

inline std::ostream& operator<<(std::ostream& os, IR::Value *v)
{
    os << v->stringify();
    return os;
}

inline std::ostream& operator<<(std::ostream &os, IR::ASTValue const &v)
{
    os << v.stringify();
    return os;
}
