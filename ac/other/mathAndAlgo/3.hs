main=do
  n <- getLine
  a <- map read.words <$> getLine
  print$sum a
