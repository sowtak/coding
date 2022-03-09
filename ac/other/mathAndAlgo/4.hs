prod :: [Int] -> Int
prod [] = 1
prod (x:xs) = foldl (*) x xs

main=do
  a <- map read.words <$> getLine :: IO [Int]
  print$prod a
  
