package main
import (
  "fmt"
  "reflect"
)
func main() {
  var c string
  fmt.Scan(&c)
  fmt.Println(c[0]-'A'+1)
}
