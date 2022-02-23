package main

import (
  "fmt"
)

func main() {
  var n int
  fmt.Scan(&n)
  a := make([]int ,n)
  for i:=0;i<n;i++ {
    fmt.Scan(&a[i])
  }
  ans:=100000000
  for i:=-100;i<=100;i++ {
    cost :=0
    for _, v:= range a {
      cost+=(v-i)*(v-i)
    }
    if ans > cost {
      ans = cost
    }
  }
  fmt.Println(ans)
}
