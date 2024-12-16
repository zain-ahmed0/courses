package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type name struct {
	fname string
	lname string
}

func main() {

	var allNames []name

	scanner := bufio.NewScanner(os.Stdin)
	fmt.Printf("Enter file name: ")
	scanner.Scan()
	fileName := scanner.Text()

	file, err := os.Open(fileName)
	if err != nil {
		fmt.Println(err.Error())
	}

	scanner = bufio.NewScanner(file)
	for scanner.Scan() {
		fullName := strings.Split(scanner.Text(), " ")
		allNames = append(allNames, name{
			fname: fullName[0],
			lname: fullName[1],
		})
		for _, value := range allNames {
			fmt.Printf("First name: %s, Last Name: %s\n", value.fname, value.lname)
		}
	}
}
