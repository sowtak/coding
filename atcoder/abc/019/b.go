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
  pre:=s[0:1]
  ans:=s[0:1]
  cnt:=1
  for i:=1;i<len(s);i++ {
    if s[i:i+1]==pre {
      cnt++
    } else {
      ans+=strconv.Itoa(cnt)
      ans+=s[i:i+1]
      pre=s[i:i+1]
      cnt=1
    }
  }
  if !(ans[len(ans)-1] >= '1' && ans[len(ans)-1] <= '9') {
    ans+=strconv.Itoa(cnt)
  }
  fmt.Println(ans)
}
