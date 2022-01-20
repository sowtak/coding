package main
import "fmt"
func main () {
  var d,t,s float64
  fmt.Scan(&d,&t,&s)
  if d/s <= t {
    fmt.Println("Yes")
  } else {
    fmt.Println("No")
  }
}
