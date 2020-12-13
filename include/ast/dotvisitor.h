#pragma once

#include "ast/visitor.h"
#include "ast/ast.h"
#include <string>

#include "llvm/Support/raw_ostream.h"

namespace ASTNS
{
    class DotVisitor :
        public ASTNS::DeclBVisitor,
        public ASTNS::ArgBVisitor,
        public ASTNS::StmtBVisitor,
        public ASTNS::ExprBVisitor,
        public ASTNS::VStmtIBVisitor,
        public ASTNS::PListBVisitor,
        public ASTNS::TypeBVisitor,
        public ASTNS::CUBVisitor,
        public ASTNS::StmtEndingBVisitor
    {
    public:
        DotVisitor(llvm::raw_ostream &ostream);
        // DOTVISIT METHODS START

// The following code was autogenerated - see the utils/ directory
void visitAdditionExpr(ASTNS::AdditionExpr *ast) override;
void visitArg(ASTNS::Arg *ast) override;
void visitArgList(ASTNS::ArgList *ast) override;
void visitArgList_OPT(ASTNS::ArgList_OPT *ast) override;
void visitArgSegment(ASTNS::ArgSegment *ast) override;
void visitAssignmentExpr(ASTNS::AssignmentExpr *ast) override;
void visitBinAndExpr(ASTNS::BinAndExpr *ast) override;
void visitBinOrExpr(ASTNS::BinOrExpr *ast) override;
void visitBitAndExpr(ASTNS::BitAndExpr *ast) override;
void visitBitOrExpr(ASTNS::BitOrExpr *ast) override;
void visitBitShiftExpr(ASTNS::BitShiftExpr *ast) override;
void visitBitXorExpr(ASTNS::BitXorExpr *ast) override;
void visitBracedBlock(ASTNS::BracedBlock *ast) override;
void visitBuiltinTypeNoVoid(ASTNS::BuiltinTypeNoVoid *ast) override;
void visitCU(ASTNS::CU *ast) override;
void visitCallExpr(ASTNS::CallExpr *ast) override;
void visitCastExpr(ASTNS::CastExpr *ast) override;
void visitCompEQExpr(ASTNS::CompEQExpr *ast) override;
void visitCompLGTExpr(ASTNS::CompLGTExpr *ast) override;
void visitDeclList(ASTNS::DeclList *ast) override;
void visitExprStmt(ASTNS::ExprStmt *ast) override;
void visitFunctionDecl(ASTNS::FunctionDecl *ast) override;
void visitIndentedBlock(ASTNS::IndentedBlock *ast) override;
void visitMultExpr(ASTNS::MultExpr *ast) override;
void visitParam(ASTNS::Param *ast) override;
void visitParamList(ASTNS::ParamList *ast) override;
void visitParamList_OPT(ASTNS::ParamList_OPT *ast) override;
void visitParamSegment(ASTNS::ParamSegment *ast) override;
void visitPrimaryExpr(ASTNS::PrimaryExpr *ast) override;
void visitRetStmt(ASTNS::RetStmt *ast) override;
void visitStmtEnding(ASTNS::StmtEnding *ast) override;
void visitStmtList(ASTNS::StmtList *ast) override;
void visitStmtList_OPT(ASTNS::StmtList_OPT *ast) override;
void visitTernaryExpr(ASTNS::TernaryExpr *ast) override;
void visitTypeV(ASTNS::TypeV *ast) override;
void visitUnaryExpr(ASTNS::UnaryExpr *ast) override;
void visitVarStmt(ASTNS::VarStmt *ast) override;
void visitVarStmtItem(ASTNS::VarStmtItem *ast) override;
void visitVarStmtItemList(ASTNS::VarStmtItemList *ast) override;
void visitVarStmtItemSegment(ASTNS::VarStmtItemSegment *ast) override;
// This code was autogenerated - see the utils/ directory

        // DOTVISIT METHODS END

        void dotVisit(ASTNS::CUB *ast);
    private:
        int _curid = 0;
        std::string curid();
        std::string makeTextNode(std::string type, std::string text);
        void connect(std::string startid, std::string fieldname, std::string connectto);
        std::string lastid;

        llvm::raw_ostream &ostream;
    };
}
