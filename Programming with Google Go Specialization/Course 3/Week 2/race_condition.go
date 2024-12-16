package main

import (
	"fmt"
)

/*
Race condition is when multiple threads are trying to access and manipulate the same variable.
In the code below, main, incrementByOne and decrementByOne are all accessing and are changing the value of x.
Due to the uncertainty of Goroutine scheduling mechanism, the results of the following program is unpredictable.
*/

func incrementByOne(pt *int) {
	(*pt)++
}

func decrementByOne(pt *int) {
	(*pt)--
}
func main() {

	fmt.Printf("Final value of i is nondeterministic due to Race Condition.\n")

	// Loops 10 times
	for demoTimes := 0; demoTimes < 10; demoTimes++ {

		i := 0

		// Launches two golang goroutine's and repeat's 100 times
		for repeat := 0; repeat < 100; repeat++ {

			// i = i + 1
			go incrementByOne(&i)

			// i = i - 1
			go decrementByOne(&i)

		}

		fmt.Printf("Final value of i: %d \n", i)
	}

	return
}
