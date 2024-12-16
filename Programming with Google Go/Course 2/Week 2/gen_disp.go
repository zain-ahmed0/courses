package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	fmt.Printf("Enter the acceleration: ")
	scanner.Scan()
	input := scanner.Text()
	a, _ := strconv.ParseFloat(input, 64)

	scanner = bufio.NewScanner(os.Stdin)
	fmt.Printf("Enter the initial velocity:: ")
	scanner.Scan()
	input = scanner.Text()
	v0, _ := strconv.ParseFloat(input, 64)

	scanner = bufio.NewScanner(os.Stdin)
	fmt.Printf("Enter the initial displacement: ")
	scanner.Scan()
	input = scanner.Text()
	s0, _ := strconv.ParseFloat(input, 64)

	fn := GenDisplaceFn(a, v0, s0)

	scanner = bufio.NewScanner(os.Stdin)
	fmt.Printf("Enter the time: ")
	scanner.Scan()
	input = scanner.Text()
	t, _ := strconv.ParseFloat(input, 64)

	fmt.Println("Displacement:", fn(t))

}

func GenDisplaceFn(a, v0, s0 float64) func(float64) float64 {
	return func(t float64) float64 {
		return ((0.5) * a * t * t) + (v0 * t) + s0
	}

}
