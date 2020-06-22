module Main where

import           Blocks
import           HelperFunctions
import           PythonParser

import           DrawBlocks
import           Diagrams.Backend.SVG.CmdLine

import           Control.Applicative          ((<|>))
import           Data.Char
import           Text.ParserCombinators.ReadP

main :: IO ()
main = mainWith makeDiagram

makeDiagram :: FilePath -> IO (Diagram B)
makeDiagram file = do
    contents <- readFile file
    let result = parsePython contents
    case result of
        Left s -> putStrLn "Error\nUnread string:\n" >> putStrLn s >> return (mempty)
        Right p -> do
            putStrLn "Parsed"
            return $ convertCodeToDiagram p 

convertCodeToDiagram :: Programm -> Diagram B
convertCodeToDiagram p = blocksToDiagram blocks
  where
      blocks = programmToBlock left : (functionsToBlock right)
      left = fst $ readyProgramm p 
      right = snd $ readyProgramm p 
