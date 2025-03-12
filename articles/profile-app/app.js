const express = require("express");
const fs = require("fs");

const app = express();
const PORT = process.env.PORT || 3001;

// Read the mounted config file
const CONFIG_PATH = "./config/config.json";
let config = { name: "Noel Bansikah", role: "DevOps Engineer", nameColor: "black", roleColor: "gray", environment: "development" };

// Check if the config file exists
if (fs.existsSync(CONFIG_PATH)) {
  config = JSON.parse(fs.readFileSync(CONFIG_PATH, "utf-8"));
}

// Define a color map for meaningful colors
const colorMap = {
  black: "#000000",
  gray: "#6c757d",
  blue: "#007BFF",
  yellow: "#FFC107",
  red: "#DC3545",
  green: "#28A745"
};

// Get the colors from the config or default to black and gray
const nameColor = colorMap[config.nameColor] || colorMap.black;
const roleColor = colorMap[config.roleColor] || colorMap.gray;

app.get("/", (req, res) => {
  res.send(`
    <html>
      <body style="background-color: white; text-align: center; padding: 50px;">
        <h1 style="color: ${nameColor};">Hello, I am ${config.name} 🚀</h1>
        <h2 style="color: ${roleColor};">Role: ${config.role}</h2>
        <h3>Environment: ${config.environment}</h3>
        <p>GitHub: <a href="https://github.com/bansikah22">bansikah22</a></p>
        <p>GitLab: <a href="https://gitlab.com/tandapnoelbansikah">bansikah22</a></p>
        <p>LinkedIn: <a href="https://linkedin.com/in/tandapnoelbansikah">bansikah22</a></p>
      </body>
    </html>
  `);
});

app.listen(PORT, () => console.log(`Server running on port ${PORT}...`));