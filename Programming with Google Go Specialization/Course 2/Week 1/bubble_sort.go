package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {

	numbers := []int{}
	for i := 0; i < 10; i++ {
		scanner := bufio.NewScanner(os.Stdin)
		fmt.Printf("Enter 10 integers: ")
		scanner.Scan()
		input := scanner.Text()
		num, _ := strconv.Atoi(input)
		numbers = append(numbers, num)

	}

	fmt.Println(BubbleSort(numbers))

}

func BubbleSort(numbers []int) []int {
	for i := 0; i < len(numbers)-1; i++ {
		for j := 0; j < len(numbers)-i-1; j++ {
			if numbers[j] > numbers[j+1] {
				Swap(numbers, i, j)
			}
		}
	}
	return numbers
}

func Swap(numbers []int, i int, j int) {
	numbers[j], numbers[j+1] = numbers[j+1], numbers[j]
}
