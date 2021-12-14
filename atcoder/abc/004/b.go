package main

import (
	"fmt"
)

func main() {
	s := make([]string, 16)
	for i:=range s {
		fmt.Scan(&s[i])
	}
	for i:=15;i>=0;i-- {
		fmt.Printf("%s ", s[i])
		if i%4==0 {
			fmt.Println()
		}
	}
}

  
