module HelperFunctions where

import           Data.Char
import           Text.ParserCombinators.ReadP

lineWrap :: String -> String -- adds "\n" to split string into lines to fit into line
lineWrap s = unwords $ helper maxSpace $ words s
  where
    maxSpace = 33
    spaceWidth = 1
    helper _ [] = []
    helper spaceLeft (w1:ws) =
        if (length (w1) + spaceWidth) > spaceLeft
            then ('\n':w1) : (helper (maxSpace - length(w1)) ws)
            else w1 : (helper (spaceLeft - length (w1) - spaceWidth) ws)

lineWrap' :: Int -> String -> String -- adds "\n" to split string into lines. also takes max line length
lineWrap' maxSpace s = unwords $ helper maxSpace $ words s
  where
    spaceWidth = 1
    helper _ [] = []
    helper spaceLeft (w1:ws) =
        if (length (w1) + spaceWidth) > spaceLeft
            then ('\n':w1) : (helper (maxSpace - length(w1)) ws)
            else w1 : (helper (spaceLeft - length (w1) - spaceWidth) ws)

interleave :: [a] -> [a] -> [a] -- combines two list with alternating elements
interleave (e:es) (o:os) = e : o : interleave es os
interleave _ _           = []

dotOr :: (a -> Bool) -> (a -> Bool) -> a -> Bool -- takes two predicates and a value to check. returns true if one of the predicates is true
dotOr f1 f2 = (||) <$> f1 <*> f2

void :: Monad m => m a -> m () -- voids a monad action
void a = a >> return ()

showResult :: [(a, String)] -> Maybe a -- returns parsing result
showResult r =
    case showResults r of
        []    -> Nothing
        (x:_) -> Just $ fst x

showResults :: [(a, String)] -> [(a, String)] -- returns parsing results
showResults =
    filter
        (\(x, leftovers) ->
             if leftovers == ""
                 then True
                 else False)

showShortOutput :: [(a, String)] -> [(a, String)] -- returns parsing results but with shortened string
showShortOutput = map (\(x, leftovers) -> (x, take 10 leftovers))

lastMaybe :: [a] -> Maybe a -- maybe returns a last element of the list
lastMaybe xs =
    if null xs
        then Nothing
        else Just (last xs)

addLineBreaks :: String -> String -- add line breaks on commas
addLineBreaks [] = []
addLineBreaks (x:xs) =
    if x == ','
        then x : '\n' : (addLineBreaks xs)
        else x : (addLineBreaks xs)

letter :: ReadP Char -- reads letters
letter = satisfy isAlpha

digit :: ReadP Char -- reads digits
digit = satisfy isDigit

number :: ReadP Int -- reads a number
number = fmap (read) $ many1 digit

isEndOfLine :: Char -> Bool -- end of line predicate
isEndOfLine = (==) '\n'

stringParser :: ReadP String -- reads a line
stringParser = munch1 $ not . isEndOfLine

-- reads endOfLine
endOfLine :: ReadP () -- TODO \ \n
endOfLine = void $ satisfy isEndOfLine
