
package main

import (
  "fmt"
  "sort"
)

func main() {
  var n int
  fmt.Scan(&n)
  a:=make([]int,n)
  m:=make(map[int]int,n)
  for i:=0;i<n;i++ {
    fmt.Scan(&a[i])
    m[a[i]]=i+1
  }
  sort.Ints(a)
  fmt.Println(m[a[len(a)-2]])
}
