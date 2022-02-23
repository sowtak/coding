package main

import (
	"fmt"
)

func main() {
	var a, b, c, d, e, f float64

	fmt.Scan(&a, &b, &c, &d, &e, &f)

	fmt.Printf("%.1f\n", abs((c-a)*(f-b)-(d-b)*(e-a))/2)
}

func abs(a float64) float64 {
	if a < 0 {
		a = -a
	}
	return a
}
