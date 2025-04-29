let humanScore = 0;
let computerScore = 0;

const getComputerChoice = () => {
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

const getHumanChoice = () => {
	const answer = prompt("Enter your choice: ");
	const result = answer.toLowerCase();
	return result;
};

const playRound = (humanChoice, computerChoice) => {
	if (humanChoice === computerChoice) {
		console.log(`It's a tie! You both chose ${humanChoice}`);
	} else if (humanChoice === "rock" && computerChoice === "scissors") {
		console.log(
			`You win! You chose ${humanChoice}, computer chose ${computerChoice}. Rock crushes scissors.`
		);
		humanScore++;
	} else if (humanChoice === "rock" && computerChoice === "paper") {
		console.log(
			`Computer wins! You chose ${humanChoice}, computer chose ${computerChoice}. Paper covers rock.`
		);
		computerScore++;
	} else if (humanChoice === "scissors" && computerChoice === "rock") {
		console.log(
			`Computer wins! You chose ${humanChoice}, computer chose ${computerChoice}. Rock crushes scissors.`
		);
		computerScore++;
	} else if (humanChoice === "scissors" && computerChoice === "paper") {
		console.log(
			`You win! You chose ${humanChoice}, computer chose ${computerChoice}. Scissors cuts paper.`
		);
		humanScore++;
	} else if (humanChoice === "paper" && computerChoice === "rock") {
		console.log(
			`You win! You chose ${humanChoice}, computer chose ${computerChoice}. Paper covers rock.`
		);
		humanScore++;
	} else if (humanChoice === "paper" && computerChoice === "scissors") {
		console.log(
			`Computer wins! You chose ${humanChoice}, computer chose ${computerChoice}. Scissors cuts paper.`
		);
		computerScore++;
	} else {
		console.log(
			`Invalid choice: "${humanChoice}". Please choose rock, paper, or scissors.`
		);
	}
	console.log(
		`Current Score - You: ${humanScore}, Computer: ${computerScore}`
	);
};

const playGame = () => {
	const humanSelection = getHumanChoice();
	const computerSelection = "paper";

	playRound(humanSelection, computerSelection);
};

playGame();
