package main

import "fmt"
func main()  {
  var a,x int
  fmt.Scan(&a)
  switch {
  case a<100:
    x = 0
  case a<=5000:
    x = a/100
  case a<=30000:
    x = a/1000 + 50
  case a<=70000:
    x = (a/1000 - 30)/5 + 80
  default:
    x = 89
  }
  fmt.Printf("%02d\n", x)
}
