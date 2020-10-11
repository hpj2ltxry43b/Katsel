#!/usr/bin/env python3
## @file astgen.py
#  Generate AST classes
#  Generate AST class related stuff

# Classes {{{1
# ASTClass {{{2
class ASTClass:
    def __init__(self, name, fields=[], extends=None, annotations=[]):
        self.name = name
        self.fields = fields
        self.extends = extends
        self.annotations = annotations
# PureASTClass {{{2
class PureASTClass:
    def __init__(self, name, annotations=[]):
        self.name = name
        self.annotations = annotations
# ASTField {{{2
class ASTField:
    # im for initialization method
    IM_ASSIGN = 0
    IM_MOVE = 1
    IM_ITERATE_MOVE = 2

    # pm for print method
    PM_CHILD = 0
    PM_TOKEN = 0
    PM_ITERATE_CHILD = 0

    def __init__(self, type_, name, passRef, initializationMethod, printMethod):
        self.type_ = type_
        self.name = name
        self.passRef = passRef
        self.initializationMethod = ASTField.IM_ASSIGN if initializationMethod is None else initializationMethod
        self.printMethod = printMethod

    @staticmethod
    def tokenField(name):
        return ASTField('Token', name, False, ASTField.IM_ASSIGN, ASTField.PM_TOKEN)
    @staticmethod
    def uptrField(pointto, name):
        return ASTField(f'std::unique_ptr<{pointto}>', name, False, ASTField.IM_MOVE, ASTField.PM_CHILD)
    @staticmethod
    def opField():
        return ASTField.tokenField('op')
    @staticmethod
    def exprField(name):
        return ASTField.uptrField('Expr', name)
# Classes to generate {{{1
annotations = {
    'ExprAn': [('bool', 'isLValue'), ('int', 'type')],
    'FuncDeclAn': [('int', 'retType'), ('int', 'nArgs')],
}
asts = [
    PureASTClass('Expr', annotations=['ExprAn']),
    PureASTClass('Decl'),
    PureASTClass('Type'),
    PureASTClass('Stmt'),

    ASTClass('Program', fields=[
            ASTField('std::vector<std::unique_ptr<Decl>>', 'decls', True, ASTField.IM_ITERATE_MOVE, ASTField.PM_ITERATE_CHILD),
        ]),

    ASTClass('BinaryExpr', fields=[
            ASTField.exprField('lhs'),
            ASTField.exprField('rhs'),
            ASTField.opField(),
        ], extends='Expr'),

    ASTClass('TernaryExpr', fields=[
            ASTField.exprField('condition'),
            ASTField.exprField('trues'),
            ASTField.exprField('falses'),
        ], extends='Expr'),

    ASTClass('UnaryExpr', fields=[
            ASTField.exprField('operand'),
            ASTField.opField(),
        ], extends='Expr'),

    ASTClass('PrimaryExpr', fields=[
            ASTField.tokenField('value'),
        ], extends='Expr'),

    ASTClass('CallExpr', fields=[
            ASTField.exprField('func'),
            ASTField.uptrField('Arg', 'args'),
        ], extends='Expr'),

    ASTClass('LtoRVExpr', fields=[
            ASTField.exprField('val')
        ], extends='Expr'),

    ASTClass('BlockStmt', fields=[
            ASTField('std::vector<std::unique_ptr<Stmt>>', 'stmts', True, ASTField.IM_ITERATE_MOVE, ASTField.PM_ITERATE_CHILD),
        ], extends='Stmt'),

    ASTClass('ExprStmt', fields=[
            ASTField.exprField('expr'),
        ], extends='Stmt'),

    ASTClass('ReturnStmt', fields=[
            ASTField.exprField('val'),
        ], extends='Stmt'),

    ASTClass('VarStmt', fields=[
            ASTField.uptrField('Type', 'type'),
            ASTField.tokenField('name'),
            ASTField.exprField('value'),
        ], extends='Stmt'),

    ASTClass('BaseType', fields=[
            ASTField.tokenField('type'),
        ], extends='Type'),

    ASTClass('FunctionDecl', fields=[
            ASTField.uptrField('Type', 'rettype'),
            ASTField.tokenField('name'),
            ASTField.uptrField('Param', 'params'),
            ASTField.uptrField('BlockStmt', 'block'),
        ], extends='Decl', annotations=['FuncDeclAn']),

    ASTClass('GlobalVarDecl', fields=[
            ASTField.uptrField('Type', 'type'),
            ASTField.tokenField('name'),
            ASTField.exprField('value'),
        ], extends='Decl'),

    ASTClass('Param', fields=[
            ASTField.uptrField('Type', 'type'),
            ASTField.tokenField('name'),
            ASTField.uptrField('Param', 'next'),
        ]),

    ASTClass('Arg', fields=[
            ASTField.exprField('value'),
            ASTField.uptrField('Arg', 'next'),
        ])
]
# Generating methods {{{1
# Generating helper methods {{{2
def asArgument(field):
    return f'{field.type_} {"&" if field.passRef else ""}{field.name}'
def asDeclaration(field):
    return f'{field.type_} {field.name};'
def fieldInitialziation(field):
    if field.initializationMethod == ASTField.IM_ASSIGN:
        return f'this->{field.name} = {field.name};'
    elif field.initializationMethod == ASTField.IM_MOVE:
        return f'this->{field.name} = std::move({field.name});'
    elif field.initializationMethod == ASTField.IM_ITERATE_MOVE:
        return f'for (auto &p : {field.name}) this->{field.name}.push_back(std::move(p)); {field.name}.clear();'
    else:
        raise Exception(f'Inavlid initialization method {field.initializationMethod}')
# Generating AST stuff {{{2
# Generate AST declarations {{{3
def genASTDecls():
    output = []
    for ast in asts:
        output.append(f'    class {ast.name};\n')

    for ast in asts:
        if type(ast) != PureASTClass:
            if ast.extends is not None:
                output.append(f'    class {ast.name} : public {ast.extends}\n')
            else:
                output.append(f'    class {ast.name}\n')

            output.append( '    {\n')
            output.append( '    public:\n')
            output.append(f'        {ast.name}({", ".join(asArgument(field) for field in ast.fields)});\n')

            for field in ast.fields:
                output.append('        ')
                output.append(asDeclaration(field))
                output.append('\n')

            for annotation in ast.annotations:
                annotationvName = annotation[0].lower() + annotation[1:]
                output.append(f'        {annotation} {annotationvName};\n')

            output.append(f'        virtual void accept({ast.name if ast.extends is None else ast.extends}Visitor *v);\n')

            if ast.extends is None:
                output.append(f'        virtual ~{ast.name}() {{}}\n')

            output.append( '    };\n')
        else:
            output.append(f'    class {ast.name}\n')
            output.append( '    {\n')
            output.append( '    public:\n')
            output.append(f'        virtual ~{ast.name}() {{}}\n')

            for annotation in ast.annotations:
                annotationvName = annotation[0].lower() + annotation[1:]
                output.append(f'        {annotation} {annotationvName};\n')

            output.append(f'        virtual void accept({ast.name}Visitor *v) = 0;\n')

            output.append( '    };\n')

    return ''.join(output)
# Generate AST definitions {{{3
def genASTDefs():
    output = ['#include "parse/ast.h"\n']
    for ast in asts:
        if type(ast) != PureASTClass:
            output.append(f'ASTNS::{ast.name}::{ast.name}({", ".join(asArgument(field) for field in ast.fields)})\n')
            output.append( '{\n')
            for field in ast.fields:
                output.append('    ')
                output.append(fieldInitialziation(field))
                output.append('\n')
            output.append( '}\n')

            output.append(f'void ASTNS::{ast.name}::accept({ast.name if ast.extends is None else ast.extends}Visitor *v) {{ v->visit{ast.name}(this); }}\n')

    return ''.join(output)
# Generate annotation structs {{{2
def genAnnotationStructs():
    output = []
    for annotationn, annotationfs in annotations.items():
        output.append(f'''struct {annotationn}
{{
''')
        output.append(f'    bool valid = false;\n')
        for annotationfty, annotationfn in annotationfs:
            output.append(f'    {annotationfty} {annotationfn};\n')
        output.append('''};
''')

    return ''.join(output)
# Generating Visitor stuff {{{2
# Generate AST forward declarations {{{3
def genASTForwDecls():
    output = []
    for ast in asts:
        output.append(f'class {ast.name};\n')
    return ''.join(output)
# Generate pure Visitor declarations {{{3
def genPureASTVisitorDecls():
    genclasses = [x for x in asts if type(x) == PureASTClass or x.extends is None]

    output = []
    for genclass in genclasses:
        output.append(f'''class {genclass.name}Visitor
{{
public:
''')

        for ast in asts:
            if type(ast) != PureASTClass and (ast.extends == genclass.name or ast.name == genclass.name):
                output.append(f'    virtual void visit{ast.name}(ASTNS::{ast.name} *a) = 0;\n')

        output.append(f'''    virtual ~{genclass.name}Visitor();
}};
''')

    return ''.join(output)
# Generate pure Visitor destructors {{{3
def genPureASTVisitorDestructs():
    genclasses = [x for x in asts if type(x) == PureASTClass or x.extends is None]

    output = []
    for genclass in genclasses:
        output.append(f'{genclass.name}Visitor::~{genclass.name}Visitor() {{}}\n')

    return ''.join(output)
