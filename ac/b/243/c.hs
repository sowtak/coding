{-# LANGUAGE ScopedTypeVariables #-}
--{-# OPTIONS_GHC -Wall -Werror -fwarn-incomplete-patterns #-}

main=do
  n<-readLn
  xy<-replicateM n$do
    [x,y]<-map read.words <$> getLine

