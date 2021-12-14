package main

import (
  "fmt"
  "sort"
  "os"
)

func main() {
	var n,k int
  fmt.Scan(&n,&k)
  r:=make([]float64, n+1)
  for i:=1;i<=n;i++ {
    fmt.Scan(&r[i])
  }
  sort.Float64s(r)
  if k == 1 {
    fmt.Println(r[len(r)-1]/2)
    os.Exit(0)
  }
  ans:=0.0
  for i:=n-k+1;i<=n;i++ {
    ans = (ans+r[i])/2
  }
  fmt.Printf("%.9f\n", ans)
}
