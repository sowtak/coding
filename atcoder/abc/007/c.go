package main

import (
	"fmt"
	"strings"
)
var (
  dx [4]int = [4]int{1, 0,-1,0}
  dy [4]int = [4]int{0,1,0,-1}
)

type p struct {
  first, second int
}

func main() {
	var R,C,sx,sy,gx,gy int
	fmt.Scan(&R,&C,&sx,&sy,&gx,&gy)
  grid := make([][]string, R)
  for i:=0;i<C;i++ {
		var s string
		fmt.Scan(&s)
    grid[i]=strings.Split(s, "")
  }

	var dist [50][50]int
	var vis [50][50]bool

  q := make([]p,0)
  q = append(q, p{first: sx, second: sy})
  dist[sx][sy]=0
	vis[sx][sy]=true
  
  for len(q)>0 {
			cur:=q[0]
			q=q[1:]
			x, y := cur.first, cur.second
			vis[x][y]=true
    for i:=0;i<4;i++ {
			nx,ny := x+dx[i], y+dy[i]
			if (nx<0 || nx>=C || ny<0 || ny>=R) {
				continue
			}
			if(grid[nx][ny]=="#" || vis[nx][ny]) {
				continue
			}
			dist[nx][ny]=dist[x][y]+1
			vis[nx][ny]=true
			q=append(q, p{first:nx, second:ny})
		}
	}
  fmt.Println(dist[gx][gy])
}
