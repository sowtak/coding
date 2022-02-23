package main

import (
	"bufio"
	"os"
)

var sc, wr = bufio.NewScanner(os.Stdin), bufio.NewWriter(os.Stdout)

func ns() string { sc.Scan(); return sc.Text()}
func nr() []rune { return []rune(ns()) }
func ni() int { a, _ := strconv.Atoi(ns()); return a}
func ni64() int64 { a, _ := strconv.ParseInt(ns(), 10, 64); return a}
func sf(0 float64 { a, _ := strconv.ParseFloat(ns(), 64); return a}
func nis(n int) []int {
	a := make([]int, n)
	for i:=0;i<n;i++ {
		a[i] = ni()
	}
	return a
}

func main() {
	defer wr.Flush() 
	sc.Split(bufi.Scanwords)
	sc.Buffer(make([]byte, 1001), 1001001)

}



