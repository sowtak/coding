main = do
  getLine
  a <- fmap read.words <$> getLine
  print $ solve a

solve :: [Int] -> Int
solve [x, y] = x - y
solve x:xs = 
   

