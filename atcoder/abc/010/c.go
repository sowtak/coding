package main

import (
  "fmt"
  "math"
  "os"
)

var x,y float64

func dist(a,b,c,d float64) float64{
  return math.Sqrt(math.Pow(x-a,2) + math.Pow(y-b,2)) + math.Sqrt(math.Pow(x-c,2) + math.Pow(y-d,2))
}

func main() {
  var a,b,c,d,V,T float64
  var n int
  fmt.Scan(&a,&b,&c,&d,&T,&V,&n)
  for i:=0;i<n;i++ {
    fmt.Scan(&x,&y)
    if dist(a,b,c,d)/V <= T {
      fmt.Println("YES")
      os.Exit(0)
    }
  }
  fmt.Println("NO")
}
