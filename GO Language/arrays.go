package main

import (
	"fmt"
)

func main() {
	var temp [2]int
	temp[0] = 1
	fmt.Print(temp)

	fmt.Println()

	var oie [7]string
	oie[0] = "Oie !!"
	fmt.Print(oie)

	fmt.Println()

	var runes []rune

	for _, r := range "OIE meu nome é BIANCA" {
		runes = append(runes, r)
	}
	fmt.Printf("%q\n", runes)

}
