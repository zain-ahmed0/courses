package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type Animal interface {
	Eat()
	Move()
	Speak()
}

type Cow struct {
	name string
}

func (c Cow) Eat() {
	fmt.Println("grass")
}

func (c Cow) Move() {
	fmt.Println("walk")
}

func (c Cow) Speak() {
	fmt.Println("moo")
}

type Bird struct {
	name string
}

func (b Bird) Eat() {
	fmt.Println("worms")
}

func (b Bird) Move() {
	fmt.Println("fly")
}

func (b Bird) Speak() {
	fmt.Println("peep")
}

type Snake struct {
	name string
}

func (s Snake) Eat() {
	fmt.Println("mice")
}

func (s Snake) Move() {
	fmt.Println("slither")
}

func (s Snake) Speak() {
	fmt.Println("hsss")
}

func createAnimal(animalType string, animalName string, animalMap map[string]Animal) {
	var animal Animal
	if animalType == "cow" {
		animal = Cow{animalName}
	} else if animalType == "bird" {
		animal = Bird{animalName}
	} else if animalType == "snake" {
		animal = Snake{animalName}
	} else {
		fmt.Println("Wrong animal type, must be cow, bird or snake!")
		return
	}
	animalMap[animalName] = animal
}

func query(animalName string, action string, animalMap map[string]Animal) {
	if action == "eat" {
		animalMap[animalName].Eat()
	} else if action == "move" {
		animalMap[animalName].Move()
	} else if action == "speak" {
		animalMap[animalName].Speak()
	} else {
		fmt.Println("Wrong animal action, must be eat, move or speak")
	}
}

func main() {

	animalMap := map[string]Animal{}

	scanner := bufio.NewScanner(os.Stdin)

	for true {
		fmt.Print("> ")
		scanner.Scan()
		input := scanner.Text()

		queryList := strings.Split(input, " ")
		if len(queryList) != 3 {
			fmt.Println("The valid cmd format should be (newanimal, the new animal name, type of new animal) try again!")
			continue
		}

		cmd := queryList[0]
		animalName := queryList[1]
		shareArg := queryList[2]

		if cmd == "newanimal" {
			createAnimal(shareArg, animalName, animalMap)
			fmt.Println("Created it!")
		} else if cmd == "query" {
			query(animalName, shareArg, animalMap)
		} else {
			fmt.Println("Wrong cmd, pls try again, valid cmd: newanimal & query")
		}
	}
}
