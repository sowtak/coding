func longestCommonPrefix(str []string) string {
  l:=201
  sample:=""
  for _,v:=range str {
    if l > len(v) {
      l=len(v)
      sample=v
    }
  }
  max:=0
  ans:=""
  for i:=0;i<len(sample);i++ {
    prefix:=sample[:i+1]
    ok:=true
    for _,v := range str { 
      if !strings.HasPrefix(v, prefix) {
        ok=false
      }
    }
    if ok {
      if max < len(prefix) {
        max=len(prefix)
        ans=prefix
      }
    }
  }
  return ans
}
