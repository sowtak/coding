main=do
  [xa,ya,xb,yb,xc,yc] <- map read.words <$> getLine
  let a = xb-xa
  let b = yb-ya
  let c = xc-xa
  let d = yc-ya
  --print$realToFrac  (abs(a*d-b*c))/2
  print$(abs(a*d-b*c))/2
