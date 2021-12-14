package main

import (
  "fmt"
)

func main() {
  var a,b int
  fmt.Scan(&a,&b)
  c:=b-a
  if c<0 {
    c = -c
  }
  if c > 6 {
    fmt.Println(10-c)
  } else {
    fmt.Println(c)
  }
}
