main=do
  s <- getLine
  print$length[c | c <- s, c == '1']
