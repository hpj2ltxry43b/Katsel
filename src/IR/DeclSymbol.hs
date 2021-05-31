{-# LANGUAGE FlexibleContexts #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE GADTs #-}

module IR.DeclSymbol
    ( DeclSymbol(..)
    , ds_cast
    ) where

import IR.Describe
import IR.DeclSpan
import IR.Parent
import IR.Value

import IR.PrintClasses

import Data.Typeable(Typeable, cast)

data DeclSymbol where
    DeclSymbol :: (DSPrint d, Typeable d, DeclSpan d, Describe d, Parent d DeclSymbol String, Parent d Value String) => d -> DeclSymbol

instance Parent DeclSymbol DeclSymbol String where
    get_child_map (DeclSymbol d, irctx) = get_child_map (d, irctx)
    add name child (DeclSymbol ds, irctx) =
        let (replaced, (added, irctx')) = add name child (ds, irctx)
        in (replaced, (DeclSymbol added, irctx'))

instance Parent DeclSymbol Value String where
    get_child_map (DeclSymbol d, irctx) = get_child_map (d, irctx)
    add name child (DeclSymbol ds, irctx) =
        let (replaced, (added, irctx')) = add name child (ds, irctx)
        in (replaced, (DeclSymbol added, irctx'))

instance DeclSpan DeclSymbol where
    decl_span irctx (DeclSymbol ds) = decl_span irctx ds
instance Describe DeclSymbol where
    describe irctx (DeclSymbol ds) = describe irctx ds
instance DSPrint DeclSymbol where
    ds_print irctx (DeclSymbol ds) = ds_print irctx ds

ds_cast :: Typeable r => DeclSymbol -> Maybe r
ds_cast (DeclSymbol v) = cast v

