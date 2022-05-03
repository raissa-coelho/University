package main

import "fmt"

var som int

const t = 10

func main() {
	x := 10 // declaration
	som = soma(x) // assignment
	fmt.Println(som)
}

func soma(s int) int {
	return s + t
}
