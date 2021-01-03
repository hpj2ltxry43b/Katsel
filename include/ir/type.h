#pragma once

#include <vector>
#include <map>

namespace IR {
    struct ASTValue;
    class Block;
    class Function;
}

#include "ir/module.h"

#include "lex/token.h"
#include "lex/tokentype.h"

#include "llvm/IR/Type.h"
#include "llvm/IR/LLVMContext.h"

#include "codegen/codegen.h"

namespace IR {
    // Base class {{{1
    class Type : public DeclSymbol {
    public:
        inline Type(CodeGen::Context &context): context(context) {}
        virtual ~Type() {}
        virtual std::string stringify() const = 0;

        enum class BinaryOperator {
            plus,
            minus,
            star,
            slash,
            percent,
            greater,
            less,
            greaterequal,
            lessequal,
            amper,
            pipe,
            caret,
            doublegreater,
            doubleless,
            doubleequal,
            bangequal
        };
        enum class UnaryOperator {
            bang,
            tilde,
            minus,
            doubleplus,
            doubleminus
        };

        virtual IR::ASTValue binOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, BinaryOperator op, IR::ASTValue l, IR::ASTValue r, Token optok, ASTNS::AST *ast) = 0;
        virtual IR::ASTValue unaryOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, UnaryOperator op, IR::ASTValue operand, Token optok, ASTNS::AST *ast) = 0;

        virtual IR::ASTValue implCast(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v) = 0;

        virtual IR::ASTValue castTo(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v, ASTNS::AST *ast) = 0;

        virtual llvm::Type* toLLVMType(llvm::LLVMContext &con) const = 0;

        CodeGen::Context &context;
    };
    // }}}
// only a temporary solution to work around linker errors
// later, these types will be able to have declsymbols in them as well
// these types cannot have values in them, or maybe they will
#define EMPTY_DECLSYMBOL() \
    inline void addValue(std::string const &name, Value *t) override { reportAbortNoh("cannot add value"); } \
    inline void addDeclSymbol(std::string const &name, DeclSymbol *t) override { reportAbortNoh("cannot add DeclSymbol"); } \
    inline DeclSymbol* getDeclSymbol(std::string const &name) const override { return nullptr; } \
    inline Value* getValue(std::string const &name) const override { return nullptr; }

    // Float {{{1
    class FloatType : public Type {
    public:
        FloatType(CodeGen::Context &context, ASTNS::AST *declAST, int size);

        std::string stringify() const override;

        IR::ASTValue binOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, BinaryOperator op, IR::ASTValue l, IR::ASTValue r, Token optok, ASTNS::AST *ast) override;
        IR::ASTValue unaryOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, UnaryOperator op, IR::ASTValue operand, Token optok, ASTNS::AST *ast) override;

        IR::ASTValue castTo(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v, ASTNS::AST *ast) override;

        IR::ASTValue implCast(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v) override;

        llvm::Type* toLLVMType(llvm::LLVMContext &context) const override;

        ASTNS::AST *declAST() const override;

        int size;

        EMPTY_DECLSYMBOL()
    private:
        ASTNS::AST *_declAST;
    };
    // Int {{{1
    class IntType : public Type {
    public:
        IntType(CodeGen::Context &context, ASTNS::AST *declAST, int size, bool isSigned);

        std::string stringify() const override;

        IR::ASTValue binOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, BinaryOperator op, IR::ASTValue l, IR::ASTValue r, Token optok, ASTNS::AST *ast) override;
        IR::ASTValue unaryOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, UnaryOperator op, IR::ASTValue operand, Token optok, ASTNS::AST *ast) override;

        IR::ASTValue castTo(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v, ASTNS::AST *ast) override;

        IR::ASTValue implCast(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v) override;

        llvm::Type* toLLVMType(llvm::LLVMContext &context) const override;

        ASTNS::AST *declAST() const override;

        int size;
        bool isSigned;

        EMPTY_DECLSYMBOL()
    private:
        ASTNS::AST *_declAST;
    };
    // Char {{{1
    class CharType : public Type {
    public:
        CharType(CodeGen::Context &context, ASTNS::AST *declAST);

        std::string stringify() const override;

        IR::ASTValue binOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, BinaryOperator op, IR::ASTValue l, IR::ASTValue r, Token optok, ASTNS::AST *ast) override;
        IR::ASTValue unaryOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, UnaryOperator op, IR::ASTValue operand, Token optok, ASTNS::AST *ast) override;

        IR::ASTValue castTo(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v, ASTNS::AST *ast) override;

        IR::ASTValue implCast(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v) override;

        llvm::Type* toLLVMType(llvm::LLVMContext &context) const override;

        ASTNS::AST *declAST() const override;

        EMPTY_DECLSYMBOL()
    private:
        ASTNS::AST *_declAST;
    };
    // Bool {{{1
    class BoolType : public Type {
    public:
        BoolType(CodeGen::Context &context, ASTNS::AST *declAST);

        std::string stringify() const override;

        IR::ASTValue binOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, BinaryOperator op, IR::ASTValue l, IR::ASTValue r, Token optok, ASTNS::AST *ast) override;
        IR::ASTValue unaryOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, UnaryOperator op, IR::ASTValue operand, Token optok, ASTNS::AST *ast) override;

        IR::ASTValue castTo(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v, ASTNS::AST *ast) override;

        IR::ASTValue implCast(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v) override;

        llvm::Type* toLLVMType(llvm::LLVMContext &context) const override;

        ASTNS::AST *declAST() const override;

        EMPTY_DECLSYMBOL()
    private:
        ASTNS::AST *_declAST;
    };
    // Function {{{1
    class FunctionType : public Type {
    public:
        Type *ret;
        std::vector<Type*> paramtys;

        FunctionType(CodeGen::Context &context, ASTNS::AST *declAST, Type *ret, std::vector<Type*> paramtys);
        std::string stringify() const override;

        IR::ASTValue binOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, BinaryOperator op, IR::ASTValue l, IR::ASTValue r, Token optok, ASTNS::AST *ast) override;
        IR::ASTValue unaryOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, UnaryOperator op, IR::ASTValue operand, Token optok, ASTNS::AST *ast) override;

        IR::ASTValue castTo(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v, ASTNS::AST *ast) override;

        IR::ASTValue implCast(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v) override;

        llvm::Type* toLLVMType(llvm::LLVMContext &context) const override;

        ASTNS::AST *declAST() const override;

        EMPTY_DECLSYMBOL()
    private:
        ASTNS::AST *_declAST;
    };
    // Void {{{1
    class VoidType : public Type {
    public:
        VoidType(CodeGen::Context &context, ASTNS::AST *declAST);

        std::string stringify() const override;

        IR::ASTValue binOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, BinaryOperator op, IR::ASTValue l, IR::ASTValue r, Token optok, ASTNS::AST *ast) override;
        IR::ASTValue unaryOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, UnaryOperator op, IR::ASTValue operand, Token optok, ASTNS::AST *ast) override;

        IR::ASTValue castTo(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v, ASTNS::AST *ast) override;

        IR::ASTValue implCast(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v) override;

        llvm::Type* toLLVMType(llvm::LLVMContext &context) const override;

        ASTNS::AST *declAST() const override;

        EMPTY_DECLSYMBOL()
    private:
        ASTNS::AST *_declAST;
    };
    // Pointer {{{1
    class PointerType : public Type {
    public:
        PointerType(CodeGen::Context &context, ASTNS::AST *declAST, Type *ty);

        std::string stringify() const override;

        IR::ASTValue binOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, BinaryOperator op, IR::ASTValue l, IR::ASTValue r, Token optok, ASTNS::AST *ast) override;
        IR::ASTValue unaryOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, UnaryOperator op, IR::ASTValue operand, Token optok, ASTNS::AST *ast) override;

        IR::ASTValue castTo(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v, ASTNS::AST *ast) override;

        IR::ASTValue implCast(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v) override;

        llvm::Type* toLLVMType(llvm::LLVMContext &context) const override;

        Type *ty;

        ASTNS::AST *declAST() const override;

        EMPTY_DECLSYMBOL()
    private:
        ASTNS::AST *_declAST;
    };
    // Generic literal types {{{1
    // Int {{{2
    class GenericIntType : public Type {
    public:
        GenericIntType(CodeGen::Context &context, ASTNS::AST *declAST);

        std::string stringify() const override;

        IR::ASTValue binOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, BinaryOperator op, IR::ASTValue l, IR::ASTValue r, Token optok, ASTNS::AST *ast) override;
        IR::ASTValue unaryOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, UnaryOperator op, IR::ASTValue operand, Token optok, ASTNS::AST *ast) override;

        IR::ASTValue castTo(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v, ASTNS::AST *ast) override;

        IR::ASTValue implCast(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v) override;

        llvm::Type* toLLVMType(llvm::LLVMContext &context) const override;

        ASTNS::AST *declAST() const override;

        EMPTY_DECLSYMBOL()
    private:
        ASTNS::AST *_declAST;
    };
    // Float {{{2
    class GenericFloatType : public Type {
    public:
        GenericFloatType(CodeGen::Context &context, ASTNS::AST *declAST);

        std::string stringify() const override;

        IR::ASTValue binOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, BinaryOperator op, IR::ASTValue l, IR::ASTValue r, Token optok, ASTNS::AST *ast) override;
        IR::ASTValue unaryOp(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, UnaryOperator op, IR::ASTValue operand, Token optok, ASTNS::AST *ast) override;

        IR::ASTValue castTo(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v, ASTNS::AST *ast) override;

        IR::ASTValue implCast(CodeGen::Context &cgc, IR::Function &fun, IR::Block *&curBlock, IR::ASTValue v) override;

        llvm::Type* toLLVMType(llvm::LLVMContext &context) const override;

        ASTNS::AST *declAST() const override;

        EMPTY_DECLSYMBOL()
    private:
        ASTNS::AST *_declAST;
    };
    // }}}1
#undef EMPTY_DECLSYMBOL
}

std::ostream& operator<<(std::ostream &os, IR::Type const *t);
