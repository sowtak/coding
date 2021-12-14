package main

import (
  "fmt"
)

func main() {
  var s string
  fmt.Scan(&s)
  if string(s[len(s)-1])=="r" {
    fmt.Println("er")
  } else {
    fmt.Println("ist")
  }
}
