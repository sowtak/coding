
package main

import (
  "fmt"
)

func main() {
  n:=ni()
  cnt:=0
  a:=make([]int,0)
  if n==1 {
    fmt.Println("1\n1")
  } else if n==2{
    fmt.Println("1\n2")
  } else {
    if n%2==1 {
      a=append(a,1)
      cnt++
    }
    g:=n/2
    for g>0 {
      g--
      cnt++
      a=append(a,2)
    }
    fmt.Println(cnt)
    for i:=0;i<len(a);i++ {
      fmt.Println(a[i])
    }
  }
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
