module Blocks
    ( Block(..)
    , programmToBlock
    , functionsToBlock
    ) where

import           ASTTypes
import           Data.List

type Comment = String

data Block
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

defaultNames = map (\c -> c : []) ['A' .. 'Z']

isIOAction :: String -> Bool
isIOAction s = s `elem` ioActions
  where
    ioActions = ["print", "input"]

isExitAction :: String -> Bool
isExitAction s = s `elem` exitActions
  where
    exitActions = ["exit"]

functionsToBlock :: [Action] -> [Block]
functionsToBlock as = map (\a -> actionsToBlock [a] (End Nothing) defaultNames) as

programmToBlock :: Programm -> Block
programmToBlock (Programm c) = Start Nothing $ codeToBlock c (End Nothing) defaultNames

codeToBlock :: Code -> Block -> [String] -> Block
codeToBlock (Code as) = actionsToBlock as

actionsToBlock :: [Action] -> Block -> [String] -> Block
actionsToBlock [] lastB _         = lastB
actionsToBlock (a:as) lastB names = actionToBlock a names $ actionsToBlock as lastB names

combineSnFnArgs :: Maybe String -> String -> [String] -> String
combineSnFnArgs Nothing fn args   = combineFnArgs fn args
combineSnFnArgs (Just sn) fn args = sn ++ '.' : (combineFnArgs fn args)

combineFnArgs :: String -> [String] -> String
combineFnArgs fn args = fn ++ ('(' : combArgs ++ ")")
  where
    combArgs = (intercalate ", " args)

combineNE :: String -> String -> String
combineNE s1 s2 = s1 ++ " = " ++ s2

elseToBlock :: Maybe Else -> [String] -> Maybe Block
elseToBlock Nothing _             = Nothing
elseToBlock (Just (Else c)) names = Just (codeToBlock c Next names)

codeToLoop :: Code -> String -> [String] -> Block -> Block
codeToLoop c s names b = codeToBlock c (LoopEnd s b) names

flowActToBlock :: FlowAct -> Block -> Block
flowActToBlock Break _      = Next
flowActToBlock Continue _   = Next
flowActToBlock (Return s) _ = End (Just s)
flowActToBlock (Yield s) _  = End (Just s)

actionToBlock :: Action -> [String] -> Block -> Block
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
