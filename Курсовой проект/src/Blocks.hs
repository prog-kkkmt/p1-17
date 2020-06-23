module Blocks
    ( Block(..)
    , programmToBlock
    , functionsToBlock
    ) where

import           ASTTypes
import           Data.List

type Comment = String

data Block -- Block-scheme data type
    = Start (Maybe Comment) Block
    | IOBlock String Block
    | AssignBlock String Block -- Mod
    | Procedure String Block
    | Decision String Block (Maybe Block) Block
    | LoopBlock String Block
    | LoopEnd String Block
    | Next
    | End (Maybe String)
    deriving (Show)

-- names for loops
defaultNames = map (\c -> c : []) ['A' .. 'Z']

isIOAction :: String -> Bool -- checks if function name corresponds to an IO function
isIOAction s = s `elem` ioActions
  where
    ioActions = ["print", "input"]

isExitAction :: String -> Bool -- checks if function name corresponds to an exit function
isExitAction s = s `elem` exitActions
  where
    exitActions = ["exit"]

functionsToBlock :: [Action] -> [Block] -- converts function definitions to blocks
functionsToBlock as = map (\a -> actionsToBlock [a] (End Nothing) defaultNames) as

programmToBlock :: Programm -> Block -- converts whole AST to block
programmToBlock (Programm c) = Start Nothing $ codeToBlock c (End Nothing) defaultNames

codeToBlock :: Code -> Block -> [String] -> Block -- converts code to block
                                                  -- takes code, block to end the code, and names string
codeToBlock (Code as) = actionsToBlock as

actionsToBlock :: [Action] -> Block -> [String] -> Block -- converts a list of actions to block
                                                  -- takes actions, block to end the code, and names string
actionsToBlock [] lastB _         = lastB
actionsToBlock (a:as) lastB names = actionToBlock a names $ actionsToBlock as lastB names

combineSnFnArgs :: Maybe String -> String -> [String] -> String -- combines source name, function name and arguments into one string
combineSnFnArgs Nothing fn args   = combineFnArgs fn args
combineSnFnArgs (Just sn) fn args = sn ++ '.' : (combineFnArgs fn args)

combineFnArgs :: String -> [String] -> String -- combines function name and arguments into one string
combineFnArgs fn args = fn ++ ('(' : combArgs ++ ")")
  where
    combArgs = (intercalate ", " args)

combineNE :: String -> String -> String -- combines name and expression into one assignment string
combineNE s1 s2 = s1 ++ " = " ++ s2

elseToBlock :: Maybe Else -> [String] -> Maybe Block -- converts else construction into block
elseToBlock Nothing _             = Nothing
elseToBlock (Just (Else c)) names = Just (codeToBlock c Next names)

codeToLoop :: Code -> String -> [String] -> Block -> Block -- converts code into a loop section block
codeToLoop c s names b = codeToBlock c (LoopEnd s b) names

flowActToBlock :: FlowAct -> Block -> Block -- converts actions like return, continue, brake into block
flowActToBlock Break _      = Next
flowActToBlock Continue _   = Next
flowActToBlock (Return s) _ = End (Just s)
flowActToBlock (Yield s) _  = End (Just s)

actionToBlock :: Action -> [String] -> Block -> Block -- converts action of every type into block
                                                      -- takes action, names, and next block
actionToBlock (Assign (Assignment n e)) _ = AssignBlock $ combineNE n e
actionToBlock (Call (CallF sn fn args)) _ =
    if isIOAction fn
        then IOBlock s
        else if isExitAction fn
                 then (\_ -> End Nothing)
                 else Procedure s
  where
    s = combineSnFnArgs sn fn args
actionToBlock (Def (Function fn args c)) names =
    \_ -> Start (Just $ combineFnArgs fn args) (codeToBlock c (End Nothing) defaultNames)
actionToBlock (IfBlock (If cond c e)) names =
    Decision cond (codeToBlock c Next names) $ elseToBlock e names
actionToBlock (LoopW (While cond c)) (name:names) =
    LoopBlock (name ++ " While " ++ cond) . codeToLoop c name names
actionToBlock (LoopF (For var cond c)) (name:names) =
    LoopBlock (name ++ " For " ++ var ++ " in " ++ cond) . codeToLoop c name names
actionToBlock (Flow flAct) _ = flowActToBlock flAct
