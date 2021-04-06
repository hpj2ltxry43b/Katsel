{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FlexibleContexts #-}
{-# LANGUAGE UndecidableInstances #-}

module IR
    ( getValue
    , getDeclSymbol
    , addValue
    , addDeclSymbol
    , buildIR
    , Module
    ) where

import qualified AST

import Location

import Data.Map(Map)
import qualified Data.Map as Map

import Data.List(foldl')

type StrMap = Map String
type DSMap = StrMap DeclSymbol
type VMap = StrMap Value

data Mutability = Mutable | Immutable
data Signedness = Signed | Unsigned

data Module = Module DSMap VMap

data Type
    = FloatType DSMap Int
    | IntType DSMap Int Signedness
    | CharType DSMap
    | BoolType DSMap
    | FunctionType DSMap Type [(Mutability, Type)]
    | VoidType DSMap
    | PointerType DSMap Mutability Type

data DeclSymbol
    = DSModule Module
    | DSType Type

data Value
    = VFunction Function
    | VRegister Register
    | VConstInt Integer
    | VConstFloat Double
    | VConstBool Bool
    | VConstChar Char
    | VVoid
    | VInstruction Instruction

data Function
    = Function
      { functionBlocks :: [BasicBlock]
      , functionRegisters :: [Register]
      , functionRetReg :: Int
      , functionParamRegs :: [Int]
      , functionType :: Type
      }
data BasicBlock = BasicBlock [Instruction] (Maybe Br)

data Register = Register Type Mutability

data Instruction
    = Copy Register Value
    | Call Function [Value]
    | Addrof Register Mutability
    | DerefPtr Value

data Br
    = BrRet
    | BrGoto BasicBlock
    | BrCond Value BasicBlock BasicBlock

-- DeclSymbol stuff {{{1
-- TODO: eventually types will have values (eg uint32::max)

getValues :: DeclSymbol -> VMap
getValues (DSType FloatType {}) = Map.empty
getValues (DSType IntType {}) = Map.empty
getValues (DSType CharType {}) = Map.empty
getValues (DSType BoolType {}) = Map.empty
getValues (DSType FunctionType {}) = Map.empty
getValues (DSType VoidType {}) = Map.empty
getValues (DSType PointerType {}) = Map.empty
getValues (DSModule (Module _ vmap)) = vmap

getDeclSymbols :: DeclSymbol -> DSMap
getDeclSymbols (DSModule (Module dsmap _)) = dsmap
getDeclSymbols (DSType (FloatType dsmap _)) = dsmap
getDeclSymbols (DSType (IntType dsmap _ _)) = dsmap
getDeclSymbols (DSType (CharType dsmap)) = dsmap
getDeclSymbols (DSType (BoolType dsmap)) = dsmap
getDeclSymbols (DSType (FunctionType dsmap _ _)) = dsmap
getDeclSymbols (DSType (VoidType dsmap)) = dsmap
getDeclSymbols (DSType (PointerType dsmap _ _)) = dsmap

getValue :: DeclSymbol -> String -> Maybe Value
getValue ds n = Map.lookup n $ getValues ds

getDeclSymbol :: DeclSymbol -> String -> Maybe DeclSymbol
getDeclSymbol ds n = Map.lookup n $ getDeclSymbols ds

addValue :: DeclSymbol -> Value -> DeclSymbol
addValue ds v = undefined

addDeclSymbol :: DeclSymbol -> Value -> DeclSymbol
addDeclSymbol = undefined

buildIR :: AST.LDModule -> IR.Module
buildIR lmod =
    case loweredMod of
        Just ir -> ir
        Nothing -> error "lowering ast to ir returned Nothing"
    where
        ddeclared = ddeclare Nothing lmod
        ddefined = ddefine ddeclared lmod
        vdeclared = vdeclare ddefined lmod
        vdefined = vdefine vdeclared lmod
        loweredMod = vdefined

class Lowerable l p where
    ddeclare :: p -> l -> p
    ddefine :: p -> l -> p
    vdeclare :: p -> l -> p
    vdefine :: p -> l -> p

class Parent p c i | p c -> i where
    add :: p -> i -> c -> p
    get :: p -> i -> Maybe c

type ModParent = Maybe IR.Module

instance Parent ModParent IR.Module () where
    add _ _ m = Just m
    get m _ = m

instance Parent IR.DeclSymbol IR.DeclSymbol String where
    add = undefined
    get = undefined
instance Parent IR.DeclSymbol IR.Value String where
    add = undefined
    get = undefined
instance Parent IR.Module IR.Value String where
    add = undefined
    get = undefined
instance Parent IR.Module IR.DeclSymbol String where
    add = undefined
    get = undefined

instance Parent p IR.Module () => Lowerable AST.LDModule p where
    ddeclare parent (Located _ (AST.DModule' decls)) = add parent () finalModule
        where
            startModule = IR.Module Map.empty Map.empty
            finalModule = foldl' ddeclare startModule decls

    ddefine parent (Located _ (AST.DModule' decls)) = add parent () defined
        where
            (Just parentmod) = get parent () :: Maybe IR.Module -- not sure why this type annotation is needed to compile
            defined = foldl' ddefine parentmod decls

    vdeclare = undefined
    vdefine = undefined

instance Parent p IR.Value String => Lowerable AST.LDDecl p where
    ddeclare _ (Located _ (AST.DDecl'Fun _)) = undefined
    ddeclare _ (Located _ (AST.DDecl'Impl _ _)) = undefined

    ddefine = undefined
    vdeclare = undefined
    vdefine = undefined