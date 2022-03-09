--import qualified Data.ByteString.Char8 as BS
main=do
  [n,m] <- map read.words <$> getLine
  ls <- map (map read.words) <$> replicateM r getLine
  print$maximum.map length.filter (\x -> all )
  
