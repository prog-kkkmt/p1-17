{-# LANGUAGE FlexibleContexts #-}

module DrawBlocks
    ( blocksToDiagram
    , Diagram
    , B
    ) where

import           Blocks
import           HelperFunctions

import           Data.List
import           Diagrams.Backend.SVG
import           Diagrams.Backend.SVG.CmdLine
import           Diagrams.Prelude
import           Diagrams.Trail
import           Diagrams.TwoD.Layout.Grid
import           Diagrams.TwoD.Text

branchYes b = cat unit_X [b, textLeft]

branchYesElse b = cat unitX [branchYes b, textRight]

branchYesNo b = cat unit_Y [branchYes b, textBottom]

textRight :: Diagram B -- a text placed to the right of a block
textRight = alignBL $ text "No" # fontSize (local 0.5) <> pha
  where
    pha = setTrace emptyTrace $ phantom (rect 1.5 0.7 :: Diagram B)
    emptyTrace = getTrace $ (strutX 1 :: Diagram B)

textBottom :: Diagram B -- a text placed to the bottom of a block
textBottom = alignTL $ text "No" # fontSize (local 0.5) <> pha
  where
    pha = setTrace emptyTrace $ phantom (rect 1.5 0.7 :: Diagram B)
    emptyTrace = getTrace $ (strutY 1 :: Diagram B)

textLeft :: Diagram B -- a text placed to the left of a block
textLeft = alignBR $ text "Yes" # fontSize (local 0.5) <> pha
  where
    pha = setTrace emptyTrace $ phantom (rect 1.5 0.7 :: Diagram B)
    emptyTrace = getTrace $ (strutX 1 :: Diagram B)

blocksToDiagram :: [Block] -> Diagram B -- converts blocks to diagram with horizontally placed schemes. the only exported function
blocksToDiagram bs = hcat $ intersperse (strutX 10) ds # lwL 0.05
  where
    ds = map (\x -> blockToDiagram x 1 "M") bs

blockToDiagram :: Block -> Int -> String -> Diagram B -- converts and connects blocks into a diagram. takes level and names
blockToDiagram b level s = vcatConnect (blockToDiagrams b level) level s

blockToDiagrams :: Block -> Int -> [Diagram B] -- converts a block into a list of diagrams
blockToDiagrams (Blocks.Start (Just s) next) _ =
    (terminator "Start" # comment s) : blockToDiagrams next 1
blockToDiagrams (Blocks.Start (Nothing) next) _ = (terminator "Start") : blockToDiagrams next 1
blockToDiagrams (IOBlock s next) level = (ioScheme s) : blockToDiagrams next level
blockToDiagrams (AssignBlock s next) level = (anyAction s) : blockToDiagrams next level
blockToDiagrams (Procedure s next) level = (callBlock s) : blockToDiagrams next level
blockToDiagrams (LoopBlock s next) level = (loopStart s) : blockToDiagrams next level
blockToDiagrams (LoopEnd s next) level = (loopEnd s) : blockToDiagrams next level
blockToDiagrams (Next) _ = []
blockToDiagrams (Blocks.End (Just s)) _ = (terminator s) : []
blockToDiagrams (Blocks.End (Nothing)) _ = (terminator "End") : []
blockToDiagrams (Decision s left (Just right) next) level =
    (combWithElse
         level
         (branchYesElse $ branchBlock s)
         (blockToDiagram left (level + 1) "L")
         (blockToDiagram right (level + 1) "R")) :
    blockToDiagrams next level
blockToDiagrams (Decision s left (Nothing) next) level =
    (comb level (branchYesNo $ branchBlock s) (blockToDiagram left (level + 1) "L")) :
    blockToDiagrams next level

combWithElse :: Int -> Diagram B -> Diagram B -> Diagram B -> Diagram B -- makes an "if" construction with "else"
combWithElse level top left right =
    comb'' # connect90deg True (level, "top") (level, "leftBottom") #
    connect90deg False (level, "leftBottom") (level, "dot") #
    connect90deg True (level, "top") (level, "rightBottom") #
    connect90deg False (level, "rightBottom") (level, "dot")
  where
    comb'' = cat (r2 (0, -1)) [comb', strut (r2 (0, -1)), circle 0.01 # named (level, "dot")]
    leftAndRight =
        centerX $
        cat
            (unitX)
            [left # named (level, "leftBottom"), strutX 4, right # named (level, "rightBottom")]
    comb' = cat (r2 (0, -1)) [top # named (level, "top"), strutY 1, leftAndRight]

comb :: Int -> Diagram B -> Diagram B -> Diagram B -- makes an "if" construction without "else"
comb level top left =
    comb'' # connect90deg True (level, "top") (level, "leftBottom") #
    connect90deg False (level, "leftBottom") (level, "dot") #
    connectOutsideL (level, "top") (level, "dot")
  where
    comb'' = cat (r2 (0, -1)) [comb', strut (r2 (0, -1)), circle 0.01 # named (level, "dot")]
    comb' =
        cat
            (r2 (-1, -1))
            [ top # named (level, "top")
            , strut (r2 (-1, -1))
            , alignR $ left # named (level, "leftBottom")
            ]

comment :: String -> Diagram B -> Diagram B -- makes a comment block
comment s d =
    cat (r2 (1, 0))
        [ d
        , hrule 0.5 # dashingL (replicate 5 0.1) 0
        , commentPart <> alignedTextC s
        , phantom ((rect 2.8 1) :: Diagram B)
        ]
  where
    alignedTextC s = fontSize (local (3 / fromIntegral (length (s)))) $ alignedText 0 0.5 s
    commentPart =
        centerXY $ stroke $ lineFromVertices [0.2 ^& 0, 0 ^& 0, 0 ^& 0.5, 0 ^& 1, 0.2 ^& 1]

textC :: String -> (Double, Diagram B) -- makes a text with line wrap
textC s = (modifier, diagram)
  where
    modifier = fromIntegral (length ls) * 0.5
    ls = lines $ lineWrap s
    diagram = centerXY $ vcat $ map f ls
    f s = txt s <> pha
    pha = setTrace emptyTrace $ phantom (rect 3 0.5 :: Diagram B)
    txt = fontSizeL (0.2) . text
    emptyTrace = getTrace $ (strutY 1 :: Diagram B)

textC' :: Int -> String -> (Double, Diagram B) -- makes a text with line wrap. also takes max line length
textC' n s = (modifier, diagram)
  where
    modifier = fromIntegral (length ls) * 0.5
    ls = lines $ lineWrap' n s
    diagram = centerXY $ vcat $ map f ls
    f s = txt s <> pha
    pha = setTrace emptyTrace $ phantom (rect 3 0.5 :: Diagram B)
    txt = fontSizeL (0.2) . text
    emptyTrace = getTrace $ (strutY 1 :: Diagram B)

terminator :: String -> Diagram B -- terminator block
terminator s = roundedRect 3 m 0.5 <> d
  where
    d = snd $ textC s
    m = max (fst $ textC s) 1

ioScheme :: String -> Diagram B -- block for IO
ioScheme s = rect 3 m # shearX 0.3 <> d
  where
    d = snd $ textC s
    m = max (fst $ textC s) 1

anyAction :: String -> Diagram B -- block for general actions
anyAction s = rect 3 m <> d
  where
    d = snd $ textC s
    m = max (fst $ textC s) 1

branchBlock :: String -> Diagram B -- "if" block
branchBlock s = square 1 # rotate (45 @@ deg) # scaleX mX # scaleY m <> d
  where
    d = snd $ textC' 15 s
    mX = 2 + (m * 0.2)
    m = max (fst $ textC' 15 s) 1

callBlock :: String -> Diagram B -- block for function calls
callBlock s = rect 3 m <> rect 3 m # scaleX 0.9 <> d
  where
    d = snd $ textC s
    m = max (fst $ textC s) 1

loopStart :: String -> Diagram B -- starting loop block
loopStart s = loopForm # scaleY m <> d
  where
    d = snd $ textC s
    m = max (fst $ textC s) 1

loopForm :: Diagram B -- loop block shape
loopForm =
    centerXY $
    stroke $ closeLine $ lineFromVertices [0 ^& 0, 0 ^& 0.8, 0.2 ^& 1, 2.8 ^& 1, 3 ^& 0.8, 3 ^& 0]

loopEnd :: String -> Diagram B -- block for loops end
loopEnd s = loopForm # reflectY # scaleY m <> d
  where
    d = snd $ textC s
    m = max (fst $ textC s) 1

-- True for connecting above
-- False for connecting belove
-- connect two blocks with a 90 degree angle
connect90deg ::
       (TypeableFloat n, Renderable (Path V2 n) b, IsName n1, IsName n2)
    => Bool
    -> n1
    -> n2
    -> QDiagram b V2 n Any
    -> QDiagram b V2 n Any
connect90deg b n1 n2 d =
    case intPoint of
        Just p ->
            (d <> intPoint' p) # connectOutsideL' (with & arrowHead .~ lineHead) n1 "intPoint" #
            connectOutsideL "intPoint" n2
        Nothing -> d
  where
    intPoint =
        if b
            then getIntersectionPoint n2 n1 d
            else getIntersectionPoint n1 n2 d
    intPoint' x = position [(x, circle 0.001 # named "intPoint")]

connect90deg' :: -- connect two blocks with a 90 degree angle. also takes arrow options
       (TypeableFloat n, Renderable (Path V2 n) b, IsName n1, IsName n2)
    => ArrowOpts n
    -> Bool
    -> n1
    -> n2
    -> QDiagram b V2 n Any
    -> QDiagram b V2 n Any
connect90deg' opts b n1 n2 d =
    case intPoint of
        Just p ->
            (d <> intPoint' p) # connectOutsideL' (opts & arrowHead .~ lineHead) n1 "intPoint" #
            connectOutsideL' opts "intPoint" n2
        Nothing -> d
  where
    intPoint =
        if b
            then getIntersectionPoint n2 n1 d
            else getIntersectionPoint n1 n2 d
    intPoint' x = position [(x, circle 0.001 # applyStyle (_shaftStyle opts) # named "intPoint")]

-- names
defaultNames = map (\c -> c : []) ['A' .. 'Z']

-- combines a list of diagrams and a list of names
zipName :: (IsName nm1, IsName nm2) => [Diagram B] -> [nm1] -> nm2 -> [Diagram B]
zipName ds nms lastName = go ds nms
  where
    go [] _          = []
    go (x:[]) _      = named lastName x : []
    go _ []          = []
    go (x:xs) (y:ys) = named y x : go xs ys

-- connects outside  edges in a list of diagrams to eachover
connectOutsideList :: (IsName nm1, IsName nm2) => Int -> [nm1] -> nm2 -> Diagram B -> Diagram B
connectOutsideList 1 _ _ d = d
connectOutsideList 2 (n1:_) lastName d = connectOutsideL n1 lastName $ d
connectOutsideList _ [] _ d = d
connectOutsideList _ (_:[]) _ d = d
connectOutsideList n (n1:n2:ns) lastName d =
    connectOutsideL n1 n2 $ connectOutsideList (n - 1) (n2 : ns) lastName d

-- connects and combines a list of diagrams into one diagram. takes a levelName and a name for the last block in the list
vcatConnect :: (IsName nm1, IsName nm2) => [Diagram B] -> nm1 -> nm2 -> Diagram B
vcatConnect ds levelName lastName =
    vcat (intersperse (strutY 1) namedDs) #
    connectOutsideList (length ds) namesList (levelName, lastName)
  where
    namedDs = zipName ds namesList (levelName, lastName)
    namesList = map (\x -> (levelName, x)) [1 :: Int,2 ..]

connectOutsideL ::
       (TypeableFloat n, Renderable (Path V2 n) b, IsName n1, IsName n2)
    => n1
    -> n2
    -> QDiagram b V2 n Any
    -> QDiagram b V2 n Any -- same as connectOutside but with modified line width
connectOutsideL = connectOutside' (with & headLength .~ (local 0.4))

connectOutsideL' ::
       (TypeableFloat n, Renderable (Path V2 n) b, IsName n1, IsName n2)
    => ArrowOpts n
    -> n1
    -> n2
    -> QDiagram b V2 n Any
    -> QDiagram b V2 n Any -- same as connectOutside' but with modified line width
connectOutsideL' opts = connectOutside' (opts & headLength .~ (local 0.4))

getPointX (P (V2 x _)) = x

getPointY (P (V2 _ y)) = y

getIntersectionPoint :: -- returns an intersection point between two diagrams. 
       (Semigroup m, Floating a, Ord a, IsName n1, IsName n2)
    => n1
    -> n2
    -> QDiagram b V2 a m
    -> Maybe (Point V2 a)
getIntersectionPoint nameX nameY d =
    (\x y -> P $ V2 x y) <$> (fmap getPointX point1) <*> (fmap getPointY point2)
  where
    points = names d
    point1 =
        case lookup (toName nameX) points of
            Just (p:ps) -> (Just p)
            Nothing     -> Nothing
    point2 =
        case lookup (toName nameY) points of
            Just (p:ps) -> (Just p)
            Nothing     -> Nothing
