package main

import "fmt"

func main() {
	var deg, dis, i int
	N := [...]string{"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"}
	P := [...]int{15, 93, 201, 327, 477, 645, 831, 1029, 1245, 1467, 1707, 1959, 12000}
	fmt.Scan(&deg, &dis)
	for {
		if dis < P[i] {
			break
		}
		i++
	}
	if i == 0 {
		fmt.Println("C 0")
	} else {
		fmt.Printf("%s %d\n", N[((deg*10+1125)/2250)%16], i)
	}
}

