{-# LANGUAGE TupleSections #-}

module Message.Underlines
    ( Underline(..)
    , Message(..)
    , Importance(..)
    , Type(..)
    , show_underlines_section
    ) where

import Location
import File

import Message.Utils

import qualified Colors

import Data.List (sortBy, partition, findIndex)

import qualified System.Console.ANSI as ANSI

data Underline = Underline { get_span_of_underline :: Span, get_importance_of_underline :: Importance, get_messages_of_underline :: [Message] }
data Message = Message Type String
data Importance = Primary | Secondary | Tertiary
data Type = Error | Warning | Note | Hint

show_underlines_section :: [Underline] -> [DiagLine]
show_underlines_section underlines = singleline_underlines' ++ multiline_underlines'
    where
        (singleline_underlines, multiline_underlines) = partition (is_single_line . get_span_of_underline) underlines

        singleline_underlines' = show_singleline_underlines singleline_underlines
        multiline_underlines' = show_multiline_underlines multiline_underlines

show_singleline_underlines :: [Underline] -> [DiagLine]
show_singleline_underlines underlines = concatMap show_line $ add_file_and_elipsis_lines $ add_context_lines $ get_lines_shown underlines
    where
        show_line (FileLine fl) = [file_line fl]
        show_line ElipsisLine = [elipsis_line]
        show_line (QuoteLine fl nr) = show_quote_and_underlines fl nr underlines

show_quote_and_underlines :: File -> Int -> [Underline] -> [DiagLine]
show_quote_and_underlines file line_nr underlines =
    [DiagLine (show line_nr) '|' quote] ++
    underline_line ++ message_lines
    where
        underlines_on_line = filter (is_on_line . get_span_of_underline) underlines
        is_on_line (Span start _ _) = file_of_loc start == file && line_of_loc start == line_nr

        quote = get_line_from_file file line_nr

        underline_line
            | null underlines_on_line = []
            | otherwise = [DiagLine "" '|' $ concatMap get_und [1..max_col]]
                where
                    get_und col = head $ concatMap (in_col col) underlines_on_line ++ [" "]
                        where
                            in_col c (Underline (Span start before _) imp msgs)
                                | col_of_loc start <= c && col_of_loc before >= c =
                                    let sgr = sgr_of_msgs msgs
                                    in [enclose_sgr sgr [char_of_imp imp]]

                                | otherwise = []

                    max_col = maximum $ map (get_end_col . get_span_of_underline) underlines_on_line
                    get_end_col (Span _ before _) = col_of_loc before

        message_assignments = assign_messages $ concatMap get_messages underlines_on_line
            where
                get_messages (Underline (Span _ before _) _ msgs) = map (col_of_loc before,) msgs

        message_lines = map draw_message_line message_assignments
        draw_message_line msgs = DiagLine "" '|' $ draw msgs 1 ""
            where
                draw curmsgs col acc
                    | null curmsgs = acc
                    | otherwise =
                        let (curs, rest) = partition ((col==) . fst) curmsgs
                        in case curs of
                            [] -> draw rest (col + 1) (acc ++ " ")
                            [(_, Message ty str)] ->
                                let len = length str
                                    sgr = sgr_of_ty ty
                                in draw rest (col + len + 4) (acc ++ enclose_sgr sgr ("`-- " ++ str))

                            _ -> error "multiple messages on the same column"

assign_messages :: [(Int, Message)] -> [[(Int, Message)]]
assign_messages messages = takeWhile (not . null) $ map find_msgs_on_row [0..]
    where
        coln_comparator (col1, _) (col2, _)  = col2 `compare` col1
        assignments = zipWith (\ ind msg -> (assign msg ind, msg)) [0..] (sortBy coln_comparator messages)

        assign :: (Int, Message) -> Int -> Int
        assign to_assign ind =
            let already_assigned = take ind assignments

                msgs_on_row r = map snd $ filter ((r==) . fst) already_assigned

                end_col_of_msg (start_col, Message _ str) = start_col + length str + 4

                overlapping = (end_col_of_msg to_assign >=) . fst

            in case findIndex (not . any overlapping . msgs_on_row) [0..] of
                Just x -> x
                Nothing -> error "unreachable"

        find_msgs_on_row row = map snd $ filter ((row==) . fst) assignments

char_of_imp :: Importance -> Char
char_of_imp Primary = '^'
char_of_imp Secondary = '~'
char_of_imp Tertiary = '.'

sgr_of_ty :: Type -> [ANSI.SGR]
sgr_of_ty Error = Colors.error_sgr
sgr_of_ty Warning = Colors.warning_sgr
sgr_of_ty Note = Colors.note_sgr
sgr_of_ty Hint = Colors.hint_sgr

sgr_of_msgs :: [Message] -> [ANSI.SGR]
sgr_of_msgs [] = Colors.empty_underline_sgr
sgr_of_msgs (Message ty _ : _) = sgr_of_ty ty

get_lines_shown :: [Underline] -> [(File, Int)]
get_lines_shown = map (get_starts . get_span_of_underline)
    where
        get_starts (Span start _ _) = (file_of_loc start, line_of_loc start)

show_multiline_underlines :: [Underline] -> [DiagLine]
show_multiline_underlines = concatMap show_multiline_underline
    where
        show_multiline_underline (Underline sp@(Span sp_start _ _) imp msgs) =
                concat
                [ file_line'
                , box_lines
                , msgs_lines
                ]

            where
                tycolor = sgr_of_msgs msgs
                impchar = char_of_imp imp

                file_line' = [file_line (file_of_loc sp_start)]
                (box_lines, _, box_end_col) = draw_box sp impchar tycolor
                msgs_lines = map (DiagLine "" '|' . show_msg) msgs
                    where
                        show_msg (Message ty str) = replicate (box_end_col - 1) ' ' ++ enclose_sgr (sgr_of_ty ty) ("`-- " ++ str)
