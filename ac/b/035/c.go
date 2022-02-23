package main

import (
  "fmt"
  "strconv"
  "os"
  "bufio"
)


var sc=bufio.NewScanner(os.Stdin)
func main() {
  var n,q int
  fmt.Scan(&n,&q)
  var a,b int
  
  m:=make(map[int]int)

  sc.Split(bufio.ScanWords)
  for i:=0;i<q;i++ {
    a, b = ni(), ni()
    m[a-1]++
    m[b]--
  }
  sum:=0
  for i:=0;i<n;i++ {
    sum += m[i]
    fmt.Print(sum%2)
  }
  fmt.Println()
}



func ni() int {
  sc.Scan()
  i, _ := strconv.Atoi(sc.Text())
  return i
}
