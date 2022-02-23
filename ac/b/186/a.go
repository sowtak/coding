
package main

import (
  "fmt"
)

func main() {
  n,w:=ni(),ni()
  fmt.Println(n/w)


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
