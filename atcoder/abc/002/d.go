package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc, wr = bufio.NewScanner(os.Stdin), bufio.NewWriter(os.Stdout)

func ns() string { sc.Scan(); return sc.Text()}
func nr() []rune { return []rune(ns()) }
func ni() int { a, _ := strconv.Atoi(ns()); return a}
func ni64() int64 { a, _ := strconv.ParseInt(ns(), 10, 64); return a}
func sf() float64 { a, _ := strconv.ParseFloat(ns(), 64); return a}
func nis(n int) []int {
	a := make([]int, n)
	for i:=0;i<n;i++ {
		a[i] = ni()
	}
	return a
}

func main() {
	defer wr.Flush() 
	sc.Split(bufio.ScanWords)
	sc.Buffer(make([]byte, 1001), 1001001)

	N,M := ni(), ni()

	// vector<vector<int>(N)> G(N) 
	G := make([][]int, N)
	for i:=0;i<N;i++ {
		G[i]=make([]int, N)
	}
	
	var x,y int
	//debug := 0
	for i:=0;i<M;i++ {
		x,y = ni(), ni()
		x--
		y--
		G[x][y]=1
	}
	ans := 0
	for i:=1;i<1<<N;i++ {
		a := []int{}
		for j:=0;j<N;j++ {
			// ハマった 
			if((i&(1<<j))!=0) {a=append(a,j)}
		}
		ok := true
		for j:=0;j<len(a);j++ {
			for k:=j+1;k<len(a);k++ {
				if G[a[j]][a[k]]==0 {
					ok=false
				}
			}
		}
		if ok {
			if ans < len(a) {
				ans = len(a)
			}
		}
		//debug=len(a)
	}
		//fmt.Println(debug)
		fmt.Println(ans)
}


