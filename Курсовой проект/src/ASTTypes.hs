module ASTTypes where

data Programm =
    Programm Code
    deriving (Show, Eq)

data Code =
    Code [Action]
    deriving (Show, Eq)

type Name = String

type Expr = String

data Action
    = Assign Assignment
    | Call CallF
    | Def Function
    | IfBlock If
    | LoopW While
    | LoopF For
    | Flow FlowAct
    deriving (Show, Eq)

data FlowAct
    = Break
    | Continue
    | Return String
    | Yield String
    deriving (Show, Eq)

type Condition = String

data If =
    If Condition Code (Maybe Else)
    deriving (Show, Eq)

data Else =
    Else Code
    deriving (Show, Eq)

data While =
    While Condition Code
    deriving (Show, Eq)

type Variable = String

data For =
    For Variable Condition Code
    deriving (Show, Eq)

data Assignment =
    Assignment Name Expr
    deriving (Show, Eq)

type SourceName = String

type FunctionName = String

type Argument = String

data CallF =
    CallF (Maybe SourceName) FunctionName [Argument]
    deriving (Show, Eq)

data Function =
    Function FunctionName [Argument] Code
    deriving (Show, Eq)
