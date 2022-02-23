package main
import (
  "fmt"
  "os"
)
const mod = 10007
func main() {
  var n int
  fmt.Scan(&n)
  a,b,c := 0, 0, 1
  if n <= 2 {
    fmt.Println(0)
    os.Exit(0)
  } else if n == 3 {
    fmt.Println(1)
    os.Exit(0)
  }
  var ans int
  for i:=n;i-3>0;i-- {
    ans=(a+b+c)%mod
    a,b,c=b,c,ans
  }
  fmt.Println(ans%mod)
}
