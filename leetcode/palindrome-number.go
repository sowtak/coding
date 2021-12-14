func isPalindrome(x int) bool {
  xs:=strconv.Itoa(x)
  n:=len(xs)
  ok:=true
  for l,r:=0,n-1;l<r;l,r=l+1,r-1 {
    if xs[l]!=xs[r] {
      ok=false
    }
  }
  if ok {
    return true
  } else {
    return false
  }
}
