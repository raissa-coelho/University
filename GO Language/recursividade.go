package main

import (
	"fmt"
)

var i int

func comer() {
	fmt.Print("Comendo...")
	for i < 2 {
		i++
		comer()
	}
}

func main() {
	comer()
}
