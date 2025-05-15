const grid = document.querySelector(".grid");

const enterSizeButton = document.querySelector(".enterSize");
const clearGridButton = document.querySelector(".clearGrid");

const changeColour = document.querySelector(".grid");

const enterSize = () => {
	let value = prompt("Enter a number between 1 and 100: ");

	if (value > 100) {
		alert("Error: Enter a number between 1 and 100");
	} else {
		return value;
	}
};

const makeGrid = (gridSize) => {
	let area = gridSize * gridSize;
	let height = 640 / gridSize;
	let width = 640 / gridSize;

	for (let i = 0; i < area; i++) {
		const div = document.createElement("div");

		div.classList.add("square");
		div.style.height = `${height}px`;
		div.style.width = `${width}px`;

		grid.appendChild(div);
	}
};

changeColour.addEventListener("mouseover", (e) => {
	if (e.target.classList.contains("square")) {
		e.target.style.backgroundColor = "aqua";
	}
});

enterSizeButton.addEventListener("click", (e) => {
	let newGridSize = enterSize();
	grid.innerHTML = "";
	makeGrid(newGridSize);
});

clearGridButton.addEventListener("click", (e) => {
	for (let div of grid.children) {
		div.style.backgroundColor = "white";
	}
});

makeGrid(16);
