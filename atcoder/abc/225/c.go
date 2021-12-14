package main

import (
  "fmt"
  "os"
)

func main() {
  var n,m int
  fmt.Scan(&n,&m)
  B := make([][]int, n)
  for i:=0;i<n;i++ {
    B[i] = make([]int, m)
    for j:=0;j<m;j++ {
      fmt.Scan(&B[i][j])
    }
  }
  // 入力行列の(1,1)を特定
  var J,I int
  for j:=1;j<=7;j++ {
    if (B[0][0]-j)%7 == 0 {
      J = j
      I = B[0][j-1]/7+1
      break
    }
  }
  fmt.Println(I,J)
  for i:=I;i<n;i++ {
    for j:=J;j<J+m;j++ {
      if (B[i-1][j-1]-j)/7 == i-1 {
        continue
      } else {
        fmt.Println("No")
        os.Exit(0)
      }
    }
  }
  fmt.Println("Yes")
}
