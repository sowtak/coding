import qualified Data.ByteString.Char8 as BS
import Data.Char
import Data.List
import Data.Array

main=do
  [h,w] <- map read.words <$> getLine
  hws <- map (map read.words) <$>  getContents

solve :: Int -> Int -> [[Int]] -> [[Int]]
solve h w hws =
  [[ri+cj-aij | (cj, aij) <- ]]   
  
  
