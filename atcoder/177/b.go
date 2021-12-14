package main
import (
  "fmt"
)
func main() {
  var s,t string
  fmt.Scan(&s,&t)
  ans := len(t)
  for i:=0;i+len(t)<=len(s);i++ {
    cnt:=0
    for j:=0;j<len(t);j++ {
      if s[i+j]!=t[j] {
        cnt++
      }
    }
    if ans>cnt {
      ans = cnt
    }
  }
  fmt.Println(ans)
}
