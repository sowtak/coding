import Data.List (sortBy)
main=do
  l <- map read.words <$> getLine
  print$solve l

solve :: [Int] -> Int
solve l = (!!2)$sortBy maximum$combSum l

combSum :: [Int] -> [Int]
combSum [] = []
combSum 
