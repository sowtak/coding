package main

import (
  "fmt"
)

func main() {
  var n int
  var s string
  fmt.Scan(&n,&s)
  cnt:=make([]int,5)
  for _,i := range s {
    cnt[i-'0']++
  }
  max,min:=0,100
  for i:=1;i<=4;i++ {
    if max < cnt[i] {
      max = cnt[i]
    }
    if min > cnt[i] {
      min = cnt[i]
    }
  }
  fmt.Println(max,min)
}
