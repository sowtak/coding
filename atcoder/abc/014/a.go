
package main

import (
  "fmt"
  "os"
)

func main() {
  var a,b int
  fmt.Scan(&a,&b)
  for i:=1;i<=100;i++ {
    if a>b*i {
      continue
    }
    fmt.Println(b*i-a)
    os.Exit(0)
  }
}
