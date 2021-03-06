{-# LANGUAGE TupleSections #-}

module Message.Utils where

import File
import Location

import qualified Colors

import Data.Char (isSpace)
import Data.List (nub, sortBy)

import qualified System.Console.ANSI as ANSI

-- TODO: clean up everything in the Message.* modules

data DiagLine = DiagLine String Char String

draw_box :: Span -> Char -> [ANSI.SGR] -> ([DiagLine], Int, Int)
draw_box (Span sp_start sp_before _) border_char sgr =
    ( concat
          [ before_first_quote_line
          , first_quote_line
          , after_first_quote_line

          , middle_quote_lines

          , before_last_quote_line
          , last_quote_line
          , after_last_quote_line
          ]
    , first_col + 1
    , last_col + 3 + 2
    )
    where
        colorify = enclose_sgr sgr

        first_line_nr = line_of_loc sp_start
        last_line_nr = line_of_loc sp_before
        first_col = col_of_loc sp_start
        last_col = col_of_loc sp_before

        min_col = 1 + minimum (map amt_wh [first_line_nr + 1 .. last_line_nr])
            where
                amt_wh lnnr
                    | all isSpace ln = maxBound
                    | otherwise = length $ takeWhile isSpace ln
                    where
                        ln = get_line lnnr
        max_col = 1 + maximum (map (length . get_line) [first_line_nr .. last_line_nr - 1])

        padded_border_char = [' ', border_char, ' ']

        get_line n = case drop (n - 1) $ lines $ file_source $ file_of_loc sp_start of
            x:_ -> x
            [] -> ""

        surround_line str startcol endcol =
            not_surrounded_left ++ colorify padded_border_char ++ surrounded ++ colorify padded_border_char ++ not_surrounded_right
            where
                str_extended = str ++ repeat ' '
                (not_surrounded_left, rest) = splitAt (startcol - 1) str_extended
                                               -- +1 because end column is included in the box
                (surrounded, rest') = splitAt (endcol - startcol + 1) rest
                not_surrounded_right = take (length str - endcol) rest'

                                                                                        -- +4 for '^ ' and ' ^'
                                                                                        -- +1 for inclusive end
        top_or_bottom startcol endcol = colorify $ replicate startcol ' ' ++ replicate (endcol - startcol + 4 + 1) border_char

        transition_line a1 b1 a2 b2 =
            if a1 == b1 && a2 == b2
            then []
            else [DiagLine "" '|' $ colorify (replicate abs1start ' ' ++ replicate abs1len border_char ++ replicate absdistbetween ' ' ++ replicate abs2len border_char)]
            where
                lowerupper a b = (min a b, max a b)
                (lower1, upper1) = lowerupper a1 b1
                (lower2, upper2) = lowerupper a2 b2

                abs1start = lower1
                abs1end = upper1
                abs2start = lower2 + 3 -- +3 for first divider, +1 for space before current divider, -1 for zero based columns
                abs2end = upper2 + 3

                abs1len = abs1end - abs1start + 1 -- +1 for inclusive end, if not then it's just the number of columsn in between, not including the end
                absdistbetween = abs2start - abs1end
                abs2len = abs2end - abs2start + 1 -- +1 also for inclusive end

        before_first_quote_line = [DiagLine "" '|' (top_or_bottom first_col max_col)]
        first_quote_line = [DiagLine (show first_line_nr) '|' (surround_line (get_line first_line_nr) first_col max_col)]
        after_first_quote_line = transition_line first_col min_col max_col max_col

        middle_quote_lines = lines_trimmed
            where
                lines_trimmed =
                    let middle_line_nrs = [first_line_nr + 1 .. last_line_nr - 1]
                        amt_middle_lines = length middle_line_nrs
                    in if amt_middle_lines  <= 1
                        then map make_line middle_line_nrs
                        else
                            map make_line (take 5 middle_line_nrs) ++
                            [DiagLine "..." '|' "..."] ++
                            map make_line (drop (amt_middle_lines - 5) middle_line_nrs)
                    where
                        make_line lnnr = DiagLine (show lnnr) '|' (surround_line (get_line lnnr) min_col max_col)

        before_last_quote_line = transition_line min_col min_col max_col last_col
        last_quote_line = [DiagLine (show last_line_nr) '|' (surround_line (get_line last_line_nr) min_col last_col)]
        after_last_quote_line = [DiagLine "" '|' (top_or_bottom min_col last_col)]

horiz_line :: Char -> Int -> Int -> String
horiz_line ch start end = replicate (start - 1) ' ' ++ replicate (end - start + 1) ch

replace_at :: Int -> a -> a -> [a] -> [a]
replace_at ind fill change orig =
    let extended = orig ++ repeat fill
        (keep, _:keep2) = splitAt ind extended
    in take (max (ind + 1) (length orig)) (keep ++ change : keep2)

get_line_from_file :: File -> Int -> String
get_line_from_file file lnnr =
    case drop (lnnr - 1) (lines $ file_source file) of
        x:_ -> x
        [] -> ""

elipsis_line :: DiagLine
elipsis_line = DiagLine "..." '|' "..."

file_line :: File -> DiagLine
file_line f = DiagLine "" '>' $ enclose_sgr Colors.file_path_sgr (file_name f)

quote_line :: File -> Int -> DiagLine
quote_line f l = DiagLine (show l) '|' (get_line_from_file f l)

add_context_lines :: [(File, Int)] -> [(File, Int)]
add_context_lines = sortBy flnr_sort_comparator . nub . concatMap add_contexts
    where
        add_contexts (fl, lnnr) = map (fl,) $ filter (>=1) $ map (lnnr+) [-2..2]

flnr_sort_comparator :: (File, Int) -> (File, Int) -> Ordering
flnr_sort_comparator (fl1, nr1) (fl2, nr2)
    | fl1 == fl2 = nr1 `compare` nr2
    | otherwise = file_name fl1 `compare` file_name fl2

data FileElipsisRes
    = FileLine File
    | ElipsisLine
    | QuoteLine File Int

add_file_and_elipsis_lines :: [(File, Int)] -> [FileElipsisRes]
add_file_and_elipsis_lines = concat . add_file_and_elipsis_lines_grouped

add_file_and_elipsis_lines_grouped :: [(File, Int)] -> [[FileElipsisRes]]
add_file_and_elipsis_lines_grouped lns = zipWith make_lines lns (Nothing : map Just lns)
    where
        make_lines (file, line) last_flnr =
            (case last_flnr of
                Just (last_fl, _)
                    | last_fl == file -> []

                _ -> [FileLine file]
            ) ++
            (case last_flnr of
                Just (last_fl, last_nr)
                    | last_fl == file && last_nr + 1 /= line -> [ElipsisLine]

                _ -> []
            ) ++
            [QuoteLine file line]

enclose :: [a] -> [a] -> [a] -> [a]
enclose open close contents = open ++ contents ++ close

enclose_sgr :: [ANSI.SGR] -> String -> String
enclose_sgr sgr = enclose (ANSI.setSGRCode sgr) (ANSI.setSGRCode [])

surround :: [a] -> [a] -> [a]
surround d = enclose d d
