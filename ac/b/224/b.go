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
 
  h,w:=ni(),ni()
  a:=make([][]int, h)
  for i:=0;i<h;i++ {
    a[i]=nis(w)
  }
  for i1:=0;i1<h;i1++ {
    for i2:=i1+1;i2<h;i2++ {
      for j1:=0;j1<w;j1++ {
        for j2:=j1+1;j2<w;j2++ {
          if !(a[i1][j1]+a[i2][j2] <= a[i2][j1]+a[i1][j2]) {
            fmt.Println("No")
            os.Exit(0)
          }
        }
      }
    }
  }
  fmt.Println("Yes")
}
