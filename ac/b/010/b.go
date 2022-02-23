package main
import "fmt"
func main() {
  var n int
  fmt.Scan(&n)
  ans:=0
  for i:=0;i<n;i++ {
    var a int
    fmt.Scan(&a) 
    for a%2==0 || a%3==2 {
      ans++
      a--
    }
  }
  fmt.Println(ans)
}

