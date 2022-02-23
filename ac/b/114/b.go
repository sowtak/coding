
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
 
  s:=ns()
  ans:=1145151919810
  for i:=0;i<len(s)-2;i++ {
    n,_:=strconv.Atoi(s[i:i+3])
    if  abs(n-753) < ans {
      ans = abs(n-753)
    }
  }
  fmt.Println(ans)
}

func abs(x int) int {
  if x < 0 {
    x = -x
  }
  return x
}
