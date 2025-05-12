const rock = document.querySelector("#rock");
const paper = document.querySelector("#paper");
const scissors = document.querySelector("#scissors");

const result = document.querySelector("body");
const resultDiv = document.createElement("div");

const score = document.querySelector("body");
const scoreDiv = document.createElement("div");

let humanScore = 0;
let computerScore = 0;

const getComputerSelection = () => {
	const result = Math.round(Math.random() * 2);
	// 0 = rock, 1 = paper, 2 = scissors
	if (result === 0) {
		return "rock";
	} else if (result === 1) {
		return "paper";
	} else {
		return "scissors";
	}
};

const playRound = (humanChoice, computerChoice) => {
	if (humanScore != 5 && computerScore != 5) {
		if (humanChoice === computerChoice) {
			resultDiv.textContent = `It's a tie! You both chose ${humanChoice}`;
			result.appendChild(resultDiv);
		} else if (humanChoice === "rock" && computerChoice === "scissors") {
			resultDiv.textContent = `You win! You chose ${humanChoice}, computer chose ${computerChoice}. Rock crushes scissors.`;
			result.appendChild(resultDiv);
			humanScore++;
		} else if (humanChoice === "rock" && computerChoice === "paper") {
			resultDiv.textContent = `Computer wins! You chose ${humanChoice}, computer chose ${computerChoice}. Paper covers rock.`;
			result.appendChild(resultDiv);
			computerScore++;
		} else if (humanChoice === "scissors" && computerChoice === "rock") {
			resultDiv.textContent = `Computer wins! You chose ${humanChoice}, computer chose ${computerChoice}. Rock crushes scissors.`;
			result.appendChild(resultDiv);
			computerScore++;
		} else if (humanChoice === "scissors" && computerChoice === "paper") {
			resultDiv.textContent = `You win! You chose ${humanChoice}, computer chose ${computerChoice}. Scissors cuts paper.`;
			result.appendChild(resultDiv);
			humanScore++;
		} else if (humanChoice === "paper" && computerChoice === "rock") {
			resultDiv.textContent = `You win! You chose ${humanChoice}, computer chose ${computerChoice}. Paper covers rock.`;
			result.appendChild(resultDiv);
			humanScore++;
		} else if (humanChoice === "paper" && computerChoice === "scissors") {
			resultDiv.textContent = `Computer wins! You chose ${humanChoice}, computer chose ${computerChoice}. Scissors cuts paper.`;
			result.appendChild(resultDiv);
			computerScore++;
		} else {
			resultDiv.textContent = `Invalid choice: "${humanChoice}". Please choose rock, paper, or scissors.`;
			result.appendChild(resultDiv);
		}
			scoreDiv.textContent = `Current Score - You: ${humanScore}, Computer: ${computerScore}`;
			score.appendChild(scoreDiv);
	} else {
		resultDiv.textContent = `Game over!`;
		result.appendChild(resultDiv);
	}
};

rock.addEventListener("click", () => {
	const humanSelection = "rock";
	const computerSelection = getComputerSelection();

	playRound(humanSelection, computerSelection);	
});

paper.addEventListener("click", () => {
	const humanSelection = "paper";
	const computerSelection = getComputerSelection();

	playRound(humanSelection, computerSelection);
});

scissors.addEventListener("click", () => {
	const humanSelection = "scissors";
	const computerSelection = getComputerSelection();

	playRound(humanSelection, computerSelection);
});
