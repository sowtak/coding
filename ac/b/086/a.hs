main=do
  [a,b] <- map read.words <$> getLine 
  putStrLn$solve a b where
    solve :: Int -> Int -> String
    solve a b 
      | even (a*b) = "Even"
      | otherwise = "Odd"
