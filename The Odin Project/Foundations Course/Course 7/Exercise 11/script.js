const container = document.querySelector("#container");

const content = document.createElement("div");
content.classList.add("content");
content.textContent = "This is the glorious text-content!";
container.appendChild(content);

const pinkBox = document.createElement("div");
const paragraph2 = document.createElement("p");
const header1 = document.createElement("h1");

pinkBox.style.border = "1px solid black";
pinkBox.style.backgroundColor = "pink";
header1.textContent = "I'm a header!";
paragraph2.textContent = "ME TOO!";

container.appendChild(pinkBox);
pinkBox.appendChild(header1);
pinkBox.appendChild(paragraph2);

const paragraph = document.createElement("p");
paragraph.textContent = "Hey I'm red!";
paragraph.style.color = "red";
container.appendChild(paragraph);

const header3 = document.createElement("h3");
header3.textContent = "I'm a blue h3!";
header3.style.color = "blue";
container.appendChild(header3);

const alertFunction = () => {
	alert("YAY! YOU DID IT!");
};

const btn = document.querySelector("#btn");

btn.addEventListener("click", function (e) {
	console.log(e);
	alertFunction();
    e.target.style.background = "blue";
});
