package main

import (
	"fmt"
	"os"
)

func main() {
	var s string
	fmt.Scan(&s)
	if s[0] == s[1] && s[1] == s[2] {
		fmt.Println(1)
		os.Exit(0)
	} else if s[0] == s[1] || s[0] == s[2] || s[1] == s[2] {
		fmt.Println(3)
		os.Exit(0)
	} else {
		fmt.Println(6)
		os.Exit(0)
	}
}
