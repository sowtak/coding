package main

import (
  "fmt"
)

func main() {
  n:=ni()
  var ans int
  if n%100 != 0 {
    ans=n/100+1
  } else {
    ans=n/100
  }
  fmt.Println(ans)
}

func ni() int {
  var n int
  fmt.Scan(&n)
  return n
}

func nis(n int) []int {
  a:=make([]int, n)
  for i:=0;i<n;i++ {
    fmt.Scan(&a[i])
  }
  return a
}
