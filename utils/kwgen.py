#!/usr/bin/env python3
import argparse
import sys

# {{{ trienode class
class TrieNode:
    def __init__(self, value, length, tokentype=None):
        self.value = value
        self.length = length
        self.nodes = []
        self.tokentype = tokentype

    def addNode(self, node):
        self.nodes.append(node)

    def hasNode(self, nodevalue):
        return nodevalue in [node.value for node in self.nodes]

    def getNode(self, nodevalue):
        #   every i in the self.nodes where self.nodes[i].value == nodevalue
        i = [i for i in range(len(self.nodes)) if self.nodes[i].value == nodevalue][0]
        return self.nodes[i] 

    def show(self, uni=True):
        if uni:
            self.__show([], False, ['\u2502', '\u2514', '\u2500'])
        else:
            self.__show([], False, ['|', '+', '-'])
    
    def __show(self, indent, isLast, chars):
        if isLast:
            indent = list(indent)
            indent[-1] = chars[1]

        print(f'{"".join(indent)}{chars[2]}\'{self.value}\'', end='')
        if self.tokentype != None:
            print(f' - {self.tokentype}', end='')
        print()

        if isLast:
            indent[-1] = ' '

        for i, node in enumerate(self.nodes):
            node.__show(indent + ['  ', chars[0]], i == len(self.nodes) - 1, chars)
            
    def generate(self):
        print('// begin autogenerated code from utils/kwgen.py')
        print('TokenType Lexer::getIdentifierType()\n{')
        self.__generate(True, 1)
        print()
        print(f'{self.__getIndent(1)}return TokenType::IDENTIFIER;')
        print('}')
        print('// end autogenerated code from utils/kwgen.py')

    def __generate(self, root, indent):
        indentStr = self.__getIndent(indent)
        bodyIndentStr = self.__getIndent(indent + (1 if len(self.nodes) else 0))
        breakIndentStr = self.__getIndent(indent + 2)

        if self.tokentype != None:
            print(f'{bodyIndentStr}if (start + {self.length} == end) return TokenType::{self.tokentype};')

        if len(self.nodes) == 0:
            return

        print(f'{indentStr}switch (*(start + {self.length}))\n{indentStr}{{')
        for node in self.nodes:
            print(f'{bodyIndentStr}case \'{node.value}\':')
            node.__generate(False, indent + 2)
            print(f'{breakIndentStr}break;')
        print(f'{indentStr}' + '}')

    def __getIndent(self, indent, tab=False):
        return ('\t' if tab else '    ') * indent
# }}}

# {{{ keywords
keywords = [
    ('print', 'PRINT'),
    ('void', 'VOID'),
    ('namespace', 'NAMESPACE'),
    ('class', 'CLASS'),
    ('enum', 'ENUM'),
    ('return', 'RETURN'),
    ('this', 'THIS'),
    ('while', 'WHILE'),
    ('for', 'FOR'),
    ('if', 'IF'),
    ('else', 'ELSE'),
    ('switch', 'SWITCH'),
    ('case', 'CASE'),
    ('default', 'DEFAULT'),
    ('break', 'BREAK'),
    ('breakall', 'BREAKALL'),
    ('breakto', 'BREAKTO'),
    ('const', 'CONST'),
    ('continue', 'CONTINUE'),
    ('inline', 'INLINE'),
    ('volatile', 'VOLATILE'),
    ('int', 'INT'),
    ('float', 'FLOAT'),
    ('bool', 'BOOL'),
    ('double', 'DOUBLE'),
    ('true', 'TRUELIT'),
    ('false', 'FALSELIT'),
    ('null', 'NULLLIT'),
    ('assert', 'ASSERT'),
    ('char', 'CHAR')
]
# }}}

# {{{ parsing args
parser = argparse.ArgumentParser(description='Generate keyword parsing code.')
parser.add_argument('-t', '--trie', action='store_true', help='View trie of keywords')
parser.add_argument('-c', '--code', action='store_true', help='Generate code of keywords')

if len(sys.argv)==1:
    parser.print_help(sys.stderr)
    sys.exit(1)

args = parser.parse_args()
# }}}

trie = TrieNode(None, 0)

# {{{ generating
for keyword, tokentype in keywords:
    lastnode = trie
    for letter in keyword:
        if lastnode.hasNode(letter):
            lastnode = lastnode.getNode(letter);
            continue
        
        newnode = TrieNode(letter, lastnode.length + 1)
        lastnode.addNode(newnode)
        lastnode = newnode

    lastnode.tokentype = tokentype
# }}}

if args.trie:
    trie.show()

if args.code:
    trie.generate()

