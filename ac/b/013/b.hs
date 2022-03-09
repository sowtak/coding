main=do
  a <- readLn
  b <- readLn
  let ans = abs (a-b)
  if ans > 5 then print$10-ans
  else print ans
