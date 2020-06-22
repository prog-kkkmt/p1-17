module IndentParsing where

import           Text.ParserCombinators.ReadP

type Indent = (Int, IndentType)

data IndentType
    = Spaces
    | Tabs
    deriving (Show, Eq)

indentChar :: IndentType -> Char
indentChar Spaces = ' '
indentChar Tabs   = '\t'

indentN :: Indent -> ReadP [Char]
indentN (n, t) = count n $ char $ indentChar t

lookTypeIndent :: IndentType -> ReadP Indent
lookTypeIndent t = do
    s <- look
    return (indent s, t)
  where
    indent (c:s)
        | (c == indentChar t) = 1 + indent s
    indent _ = 0

lookSpaceIndent :: ReadP Indent
lookSpaceIndent = lookTypeIndent Spaces

lookTabIndent :: ReadP Indent
lookTabIndent = lookTypeIndent Tabs

lookIndent :: ReadP Indent
lookIndent = do
    spaceInd@(nSpaces, _) <- lookSpaceIndent
    if nSpaces == 0
        then do
            tabInd <- lookTabIndent
            return tabInd
        else return spaceInd

