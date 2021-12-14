package main

import (
  "fmt"
)

func main() {
  var a,b,c int
  fmt.Scan(&a,&b)
  if a>b {
    a,b=b,a
  }
  c=b-a
  rs:=[10]int{0,1,2,3,2,1,2,3,3,2}
  fmt.Println(c/10+rs[c%10])
}


