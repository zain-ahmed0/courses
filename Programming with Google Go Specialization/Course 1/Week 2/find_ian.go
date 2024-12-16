package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var s string

	fmt.Printf("Enter a string: ")
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s = scanner.Text()
	s = strings.TrimSpace(strings.ToLower((s)))

	startsWithI := s[0]
	endsWithN := s[len(s)-1]

	if startsWithI == 'i' && endsWithN == 'n' && strings.ContainsAny(s, "a") {
		fmt.Println("Found!")
	} else {
		fmt.Println("Not Found!")
	}
}
