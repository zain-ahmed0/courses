package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
)

func main() {

	scanner := bufio.NewScanner(os.Stdin)
	fmt.Printf("Enter a name: ")
	scanner.Scan()
	name := scanner.Text()

	scanner = bufio.NewScanner(os.Stdin)
	fmt.Printf("Enter an address: ")
	scanner.Scan()
	address := scanner.Text()

	person, _ := json.Marshal(map[string]string{"name": name, "address": address})

	fmt.Printf(string(person))

}
