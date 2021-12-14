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
  

  a,b,c:=ni(),ni(),ni()
  aa,bb,cc:=1,1,1
  if a>b {
    bb++
  }
  if a>c {
    cc++
  }
  if b>a {
    aa++
  }
  if b>c {
    cc++
  }
  if c>a {
    aa++
  }
  if c>b {
    bb++
  }
  fmt.Println(aa)
  fmt.Println(bb)
  fmt.Println(cc)
}
