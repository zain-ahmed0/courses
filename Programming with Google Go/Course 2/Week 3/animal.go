package main

import (
	"bufio"
	"fmt"
	"os"
)

type Animal struct {
	food       string
	locomotion string
	noise      string
}

func main() {

	var (
		ani Animal
	)

	for {
		scanner := bufio.NewScanner(os.Stdin)
		fmt.Printf("> ")
		scanner.Scan()
		input := scanner.Text()
		fmt.Printf("> ")
		scanner.Scan()
		input2 := scanner.Text()

		if input == "cow" {
			ani = Animal{"grass", "walk", "moo"}
		} else if input == "bird" {
			ani = Animal{"worms", "fly", "peep"}
		} else if input == "snake" {
			ani = Animal{"mice", "slither", "hsss"}
		} else {
			fmt.Println("Incorrect input. Try again")
		}

		if input2 == "eat" {
			ani.Eat()
		} else if input2 == "move" {
			ani.Move()
		} else if input2 == "speak" {
			ani.Speak()
		} else {
			fmt.Println("Incorrect input. Try again")
		}
	}
}

func (animal Animal) Eat() {
	fmt.Println("I eat", animal.food)
}
func (animal Animal) Move() {
	fmt.Println("I", animal.locomotion)
}

func (animal Animal) Speak() {
	fmt.Println("I", animal.noise)
}
