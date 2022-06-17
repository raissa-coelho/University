package main

import (
	"fmt"
)

//With mapping

func main() {
	var cell = make(map[string]int)
	cell["Bianca"] = 32215002

	fmt.Println(cell["Bianca"])
}
