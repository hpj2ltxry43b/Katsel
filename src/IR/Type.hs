{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE MultiParamTypeClasses #-}

module IR.Type
    ( Mutability(..)
    , Signedness(..)
    , TyIdx
    , Type(..)
    ) where

import IR.MapSynonyms
import IR.Parent
import IR.DeclSymbol
import IR.TyIdx

data Mutability = Mutable | Immutable deriving Eq
data Signedness = Signed | Unsigned deriving Eq

data Type
    = FloatType DSMap Int
    | IntType DSMap Int Signedness
    | CharType DSMap
    | BoolType DSMap
    | FunctionType DSMap TyIdx [(Mutability, TyIdx)]
    | VoidType DSMap
    | PointerType DSMap Mutability TyIdx

instance Parent Type DeclSymbol String where
    get_child_map ((FloatType dsmap _), _) = dsmap
    get_child_map ((IntType dsmap _ _), _) = dsmap
    get_child_map ((CharType dsmap), _) = dsmap
    get_child_map ((BoolType dsmap), _) = dsmap
    get_child_map ((FunctionType dsmap _ _), _) = dsmap
    get_child_map ((VoidType dsmap), _) = dsmap
    get_child_map ((PointerType dsmap _ _), _) = dsmap