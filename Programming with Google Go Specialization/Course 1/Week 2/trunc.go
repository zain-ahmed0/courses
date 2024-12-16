package main

import "fmt"

func main() {
	var num float64

	fmt.Printf("Enter a floating point number: ")
	fmt.Scanln(&num)
	truncNum := int(num)

	fmt.Println(truncNum)
}
