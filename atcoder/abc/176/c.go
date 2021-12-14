package main

import (
  "fmt"
)

func main() {
  var n int
  fmt.Scan(&n)
  max:=0
  ans:=0
  var h int
  for i:=0;i<n;i++ {
    fmt.Scan(&h)
    if h < max {
      ans+=max-h
    }
    if max < h {
      max = h
    }
  }
  fmt.Println(ans)
}
