package main

import (
	"fmt"
	"os"
)

func main() {
	var n int
	fmt.Scan(&n)
	i:=n
  m := make(map[int]int)
	var a,b int
	for i>1 {
		i--
		fmt.Scan(&a,&b)
		m[a]++
    m[b]++
  }
  for i:=1;i<=n;i++ {
    if m[i]==n-1 {
      fmt.Println("Yes")
      os.Exit(0)
    }
  }
  fmt.Println("No")
}
