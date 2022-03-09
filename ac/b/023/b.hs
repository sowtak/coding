{-# LANGUAGE ScopedTypeVariables #-}
--{-# OPTIONS_GHC -Wall -Werror -fwarn-incomplete-patterns #-}

main :: IO ()
main=do
  n<-readLn 
  s <- getLine
  let (i,st) = solve n 1 "b"
  if s == st then print i else print$negate 1

solve :: Int -> Int -> String -> (Int, String)
solve n k s
  | length s >= n = (k-1, s)
  | mod k 3 == 1 = solve n (k+1) $ "a"++s++"c"
  | mod k 3 == 2 = solve n (k+1) $ "c"++s++"a"
  | mod k 3 == 0 = solve n (k+1) $ "b"++s++"b"
  
