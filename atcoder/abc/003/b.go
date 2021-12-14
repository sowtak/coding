package main

import (
	"bufio"
	"os"
	"strconv"
  "fmt"
)

var sc, wr = bufio.NewScanner(os.Stdin), bufio.NewWriter(os.Stdout)

func ns() string { sc.Scan(); return sc.Text()}
func nr() []rune { return []rune(ns()) }
func ni() int { a, _ := strconv.Atoi(ns()); return a}
func ni64() int64 { a, _ := strconv.ParseInt(ns(), 10, 64); return a}
func nf() float64 { a, _ := strconv.ParseFloat(ns(), 64); return a}
func nis(n int) []int {a := make([]int, n);for i:=0;i<n;i++ {a[i] = ni()};return a}

func main() {
	defer wr.Flush()
	sc.Split(bufio.ScanWords)
	sc.Buffer(make([]byte, 1001), 1001001)
 
  s,t:=ns(),ns()
  if s==t {
    fmt.Println("You can win")
    os.Exit(0)
  }
  ac:=[]string{"a","t","c","o","d","e","r"}
  for i:=0;i<len(s);i++ {
    if s[i]!=t[i] {
      if s[i] != '@' && t[i] != '@' {
        fmt.Println("You will lose")
        os.Exit(0)
      } else if s[i] == '@' {
        for j:=0;j<7;j++ {
          if t[i:i+1] == ac[j] {
            break
          }
          if j==6 {
            fmt.Println("You will lose")
            os.Exit(0)
          }
        }
      } else if t[i] == '@' {
        for j:=0;j<7;j++ {
          if s[i:i+1] == ac[j] {
            break
          }
          if j==6 {
            fmt.Println("You will lose")
            os.Exit(0)
          }
        }
      }
    } 
  }
  fmt.Println("You can win")
}
