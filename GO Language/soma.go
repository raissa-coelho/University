package main

import "fmt"

var som int

const t = 10

func main() {
	x := 10
	som := soma(x)
	fmt.Println(som)
}

func soma(s int) int {
	return s + t
}
