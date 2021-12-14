
package main

import (
  "fmt"
)

func main() {
  var n int
  fmt.Scan(&n)
  x:=make([]int, n)
  y:=make([]int, n)
  for i:=0;i<n;i++ {
    fmt.Scan(&x[i], &y[i])
  }
  ans:=0
  for i:=0;i<n;i++ {
    for j:=i+1;j<n;j++ {
      for k:=j+1;k<n;k++ {
        if abs((x[j]-x[i])*(y[k]-y[i])-(y[j]-y[i])*(x[k]-x[i])) > 0 {
          ans++
        }
      }
    }
  }
  fmt.Println(ans)
}

func abs (x int) int {
  if x < 0 {
    x = -x
  } 
  return x
}
