package main

import (
  "fmt"
)

func main() {
  var n int
  fmt.Scan(&n)
  dif:=2025-n
  if dif == 1 {
    fmt.Println("1 x 1\n")
  } else {
    for i:=1;i<=9;i++ {
      for j:=1;j<=9;j++ {
        if i*j == dif {
          fmt.Printf("%d x %d\n", i, j)
        }
      }
    }
  }
}
