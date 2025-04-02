// Toggle dark mode on and off
document.getElementById("darkToggle").addEventListener("click", () =>
{
	document.body.classList.toggle("dark-mode");
});

// Handle game settings form
document.querySelector(".settings-form").addEventListener("submit", (e) =>
{
	e.preventDefault();

	const paddleColor = document.getElementById("paddleColor").value;
	const ballSpeed = document.getElementById("ballSpeed").value;
	const theme = document.getElementById("theme").value;

	console.log("🎨 Paddle Color:", paddleColor);
	console.log("⚡ Ball Speed:", ballSpeed);
	console.log("🎭 Theme:", theme);

	alert("Settings applied! (check the browser console)");
});
