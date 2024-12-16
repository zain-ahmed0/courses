package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	s := make([]int, 0, 3)
	for true {
		scanner := bufio.NewScanner(os.Stdin)
		fmt.Printf("Enter a number or 'X' to quit: ")
		scanner.Scan()
		input := scanner.Text()
		if input != "X" {
			input, _ := strconv.Atoi(scanner.Text())
			s = append(s, input)
			sort.Ints(s)
			fmt.Println(s)
		} else {
			break
		}
	}
}
