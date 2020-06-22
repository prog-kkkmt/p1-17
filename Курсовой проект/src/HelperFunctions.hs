module HelperFunctions where

import           Data.Char
import           Text.ParserCombinators.ReadP

lineWrap :: String -> String
lineWrap s = unwords $ helper maxSpace $ words s
  where
    maxSpace = 33
    spaceWidth = 1
    helper _ [] = []
    helper spaceLeft (w1:ws) =
        if (length (w1) + spaceWidth) > spaceLeft
            then ('\n':w1) : (helper (maxSpace - length(w1)) ws)
            else w1 : (helper (spaceLeft - length (w1) - spaceWidth) ws)

lineWrap' :: Int -> String -> String
lineWrap' maxSpace s = unwords $ helper maxSpace $ words s
  where
    spaceWidth = 1
    helper _ [] = []
    helper spaceLeft (w1:ws) =
        if (length (w1) + spaceWidth) > spaceLeft
            then ('\n':w1) : (helper (maxSpace - length(w1)) ws)
            else w1 : (helper (spaceLeft - length (w1) - spaceWidth) ws)

interleave :: [a] -> [a] -> [a]
interleave (e:es) (o:os) = e : o : interleave es os
interleave _ _           = []

dotOr :: (a -> Bool) -> (a -> Bool) -> a -> Bool
dotOr f1 f2 = (||) <$> f1 <*> f2

void :: Monad m => m a -> m ()
void a = a >> return ()

showResult :: [(a, String)] -> Maybe a
showResult r =
    case showResults r of
        []    -> Nothing
        (x:_) -> Just $ fst x

showResults :: [(a, String)] -> [(a, String)]
showResults =
    filter
        (\(x, leftovers) ->
             if leftovers == ""
                 then True
                 else False)

showShortOutput :: [(a, String)] -> [(a, String)]
showShortOutput = map (\(x, leftovers) -> (x, take 10 leftovers))

lastMaybe :: [a] -> Maybe a
lastMaybe xs =
    if null xs
        then Nothing
        else Just (last xs)

addLineBreaks :: String -> String
addLineBreaks [] = []
addLineBreaks (x:xs) =
    if x == ','
        then x : '\n' : (addLineBreaks xs)
        else x : (addLineBreaks xs)

letter :: ReadP Char
letter = satisfy isAlpha

digit :: ReadP Char
digit = satisfy isDigit

number :: ReadP Int
number = fmap (read) $ many1 digit

isEndOfLine :: Char -> Bool
isEndOfLine = (==) '\n'

stringParser :: ReadP String
stringParser = munch1 $ not . isEndOfLine

endOfLine :: ReadP () -- TODO \ \n
endOfLine = void $ satisfy isEndOfLine
