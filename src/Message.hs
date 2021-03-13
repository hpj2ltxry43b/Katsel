module Message
    ( Section(..)
    , SimpleDiagType(..)
    , SimpleDiag(..)
    , DiagCode(..)
    , ToDiagnostic
    , report
    , toDiagnostic
    ) where

import Location

data Section = SimpleText String

data SimpleDiagType = Error
                    | Warning
                    | DebugMessage

instance Show SimpleDiagType where
    show Error = "error"
    show Warning = "warning"
    show DebugMessage = "debug message"

newtype DiagCode = DiagCode String

data SimpleDiag = SimpleDiag SimpleDiagType Location DiagCode String [Section]

class ToDiagnostic e where
    toDiagnostic :: e -> SimpleDiag

report :: (ToDiagnostic e) => e -> String
report = report' . toDiagnostic

report' :: SimpleDiag -> String
report' (SimpleDiag ty loc (DiagCode code) name sections) =
    header ++ "\n" ++
    shownSections ++
    footer ++ "\n"
    where
        header = show ty ++ " at " ++ show loc ++ ":"
        footer = indentStr ++ "==> [" ++ code ++ "]: " ++ name

        shownSections = concat $ map (showSection indentAmt) sections

        indentAmt = maximum $ map indentOf sections
        indentStr = makeIndentStr indentAmt

indentOf :: Section -> Int
indentOf _ = 4

showSection :: Int -> Section -> String
showSection indent (SimpleText text) = makeIndentStr indent ++ text ++ "\n"

makeIndentStr :: Int -> String
makeIndentStr x = replicate x ' '
