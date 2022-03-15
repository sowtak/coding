{-# LANGUAGE ScopedTypeVariables #-}
--{-# OPTIONS_GHC -Wall -Werror -fwarn-incomplete-patterns #-}

main=do
  n<-readLn
  putStrLn$solve n where
    solve :: Int -> String
    solve n
      | n <= 59 = "Bad"
      | n >= 60 && n <= 89 = "Good"
      | n >= 90 && n <= 99 = "Great"
      | otherwise = "Perfect"
