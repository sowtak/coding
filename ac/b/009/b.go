package main

import (
  "fmt"
  "sort"
)

func main() {
  var n int
  fmt.Scan(&n)
  a := make([]int, 0)
  m := make(map[int]int, n)
  for i:=0;i<n;i++ {
    var b int 
    fmt.Scan(&b)
    if m[b] == 0 {
      a=append(a, b)
      m[b]++
    }
  }
  sort.Ints(a)
  fmt.Println(a[len(a)-2])
}
