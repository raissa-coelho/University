package main

import (
	"fmt"
)

func fib(num int) int {
	x, y := 0, 1
	for i := 0; i < num; i++ {
		x, y = y, x+y
	}
	return x
}
func main() {
	var t int

	fmt.Print("Enter number: ")
	fmt.Scan(&t)
	fmt.Printf("Número : %d", fib(t))
}
