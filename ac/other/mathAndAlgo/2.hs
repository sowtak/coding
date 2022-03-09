main=do
  a <- map read.words <$> getLine
  print$sum a
