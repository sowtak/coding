{-# OPTIONS_GHC -O2 #-}
--{-# LANGUAGE StandaloneDeriving #-}
--{-# LANGUAGE BangPatterns #-}
--{-# LANGUAGE Strict #-}
--{-# LANGUAGE TupleSections #-}
--{-# LANGUAGE FlexibleContexts #-}
--{-# LANGUAGE FlexibleInstances #-}
--{-# LANGUAGE UndecidableInstances #-}
--{-# LANGUAGE GeneralizedNewtypeDeriving #-}
--{-# LANGUAGE DerivingStrategies #-}
--{-# LANGUAGE DerivingVia #-}
--{-# LANGUAGE DeriveGeneric #-}
--{-# LANGUAGE MultiParamTypeClasses #-}
--{-# LANGUAGE TypeFamilies #-}
--{-# LANGUAGE KindSignatures #-}
--{-# LANGUAGE MagicHash #-}
--{-# LANGUAGE PatternSynonyms #-}
--{-# LANGUAGE UnboxedTuples #-}
--{-# LANGUAGE DataKinds #-}
--{-# LANGUAGE TypeApplications #-}
--{-# LANGUAGE RankNTypes #-}
--{-# LANGUAGE ScopedTypeVariables #-}
--{-# LANGUAGE TypeOperators #-}
--{-# LANGUAGE NoStarIsType #-}

module Main where

import Debug.Trace
--import Data.Bits
--import Data.List
--import Data.Char
--import Data.Maybe
--import Data.Function
--import Data.Ratio
--import Data.Bifunctor
--import Data.Foldable
--import Data.Tuple
--import Data.Complex
--import Numeric
--import Data.Int
--import Data.Proxy
--import Data.Semigroup
--import Data.STRef
import Data.Array.ST
--import qualified Data.Array as A
--import qualified Data.Array.Unboxed as AU
--import qualified Data.Vector as V
--import qualified Data.Vector.Mutable as VM
--import qualified Data.Vector.Unboxing as VU
--import qualified Data.Vector.Unboxing.Mutable as VUM
--import qualified Data.Vector.Generic as VG
--import qualified Data.Vector.Generic.Mutable as VGM
--import qualified Data.Vector.Algorithms.Intro as VAI
--import qualified Data.Vector.Algorithms.Search as VAS
import Control.Monad
import Control.Monad.ST
--import qualified Data.ByteString.Char8 as BS
--import qualified Data.Set as S
--import qualified Data.IntSet as IS
--import qualified Data.Map.Strict as M
--import qualified Data.IntMap.Strict as IM
--import qualified Data.Sequence as SQ
--import qualified Data.IntPSQ as IPSQ
--import qualified Data.Heap as H
--import System.IO
--import GHC.Generics
--import GHC.Exts
--import GHC.TypeLits

main :: IO ()
main = do
  m <- readLn
  

modulo :: Int
modulo = 998244353

modAdd :: Int -> Int -> Int -> Int
modAdd m a b = if a + b >= m then a + b - m else a + b

modifyArray' :: (MArray a e m, Ix i) => a i e -> i -> (e -> e) -> m ()
modifyArray' ary i f = do
  v <- readArray ary i
  let v' = f v
  v' `seq` writeArray ary i v'

calc :: [Int] -> Int -> Int
calc as m = runST $ do
  table <- newArray ((0, 0), (m, m - 1)) 0 :: ST s (STUArray s (Int, Int) Int)
  writeArray table (0, 0) 1

  forM_ (map (`mod` m) as) $ \a -> do
    forM_ [m - 1, m - 2..0] $ \i -> do
      forM_ [0..m - 1] $ \j -> do
        v <- readArray table (i, j)
        when (v /= 0) $ do
          modifyArray' table (i + 1, modAdd m a j) (modAdd modulo v)

  readArray table (m, 0)

