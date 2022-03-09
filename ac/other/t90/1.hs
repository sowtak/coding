main=do
  [n,l] <- map read.words <$> getLine
  k <- readLn
  ns <- map read.words <$> getLine
  print$solve l (k+1) ns

solve :: Int -> Int -> [Int] -> Int
solve l k ns = binSearch
