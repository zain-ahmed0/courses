const number = document.querySelectorAll(".number-button");
const operand = document.querySelectorAll(".operand-button");
const equals = document.querySelector(".equals-button");
const clear = document.querySelector(".clear-button");
const del = document.querySelector(".delete-button");
const output = document.querySelector(".calculator-box-answer");

let isEnteringFirstNumber = true;
let justCalculated = false;
let decimalAdded = false;
let currentValue = "";
let firstNumber = "";
let secondNumber = "";
let operator = "";

clear.addEventListener("click", (e) => {
	currentValue = "";
	firstNumber = "";
	secondNumber = "";
	operator = "";
	isEnteringFirstNumber = true;
	output.textContent = "";
	console.log("Calculator cleared");
});

del.addEventListener("click", (e) => {
	if (currentValue.length > 0) {
		currentValue = currentValue.slice(0, -1);
		output.textContent = currentValue;
	}
});

number.forEach((button) => {
	button.addEventListener("click", (e) => {
		if (justCalculated) {
			currentValue = e.target.value;

			if (e.target.value === ".") {
				if (currentValue.includes(".")) {
					currentValue = currentValue.replace(".", "");
				}
			}

			output.textContent = currentValue;
			justCalculated = false;
		} else {
			currentValue += e.target.value;
			output.textContent = currentValue;
		}

		console.log(`Button clicked: ${e.target.value}`);
		console.log(`Current number value: ${currentValue}`);
	});
});

const add = (num1, num2) => {
	return num1 + num2;
};

const subtract = (num1, num2) => {
	return num1 - num2;
};
const multiply = (num1, num2) => {
	return num1 * num2;
};

const divide = (num1, num2) => {
	if (num1 === 0 || num2 === 0) return "Error: Division by zero";
	return num1 / num2;
};

const operate = (firstNumber, secondNumber) => {
	if (operator === "+") {
		const result = add(Number(firstNumber), Number(secondNumber));
		output.textContent = result;
		return result;
	} else if (operator === "-") {
		const result = subtract(Number(firstNumber), Number(secondNumber));
		output.textContent = result;
		return result;
	} else if (operator === "*") {
		const result = multiply(Number(firstNumber), Number(secondNumber));
		output.textContent = result;
		return result;
	} else if (operator === "/") {
		const result = divide(Number(firstNumber), Number(secondNumber));
		output.textContent = result;
		return result;
	} else {
		console.error("Invalid operator");
		return "Error: Invalid operator";
	}
};

operand.forEach((button) => {
	button.addEventListener("click", (e) => {
		const value = e.target.value;

		if (value !== "=") {
			if (!justCalculated) {
				firstNumber = currentValue;
			}

			operator = value;
			currentValue = "";
			isEnteringFirstNumber = false;
		}
	});
});

equals.addEventListener("click", (e) => {
	if (operator && firstNumber !== "" && currentValue !== "") {
		secondNumber = currentValue;
		const result = operate(firstNumber, secondNumber);

		output.textContent = result;

		justCalculated = true;

		firstNumber = result;
		currentValue = "";
		secondNumber = "";
		operator = "";
	}
});

document.addEventListener("keydown", (e) => {
	if (e.key >= "0" && e.key <= "9") {
		const button = document.querySelector(
			`.number-button[value="${e.key}"]`
		);
		if (button) {
			button.click();
		}
	} else if (["+", "-", "*", "/"].includes(e.key)) {
		const button = document.querySelector(
			`.operand-button[value="${e.key}"]`
		);
		if (button) {
			button.click();
		}
	} else if (e.key === "=" || e.key === "Enter") {
		equals.click();
	} else if (e.key === "Escape") {
		clear.click();
	} else if (e.key === "Backspace") {
		del.click();
	}
});
