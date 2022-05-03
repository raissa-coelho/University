/*  go run
go build <- creates an executible file
*/
package main

import "fmt"

func main() {
	var myName string = "Bianca"
	var oie = "OIE!" // can be used between function and be declared later
	x := 10.9        // cannot be used between function (local)

	fmt.Println("HELLO!")
	fmt.Println(myName)
	fmt.Println(oie)
	fmt.Println(x)
}
