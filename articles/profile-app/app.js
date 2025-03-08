const express = require("express");
const fs = require("fs");
const { text } = require("stream/consumers");

const app = express();
const PORT = process.env.PORT || 3001;

// Read the mounted config file
const CONFIG_PATH = "./config/config.json";
let config = { name: "Noel Bansikah", role: "DevOps Engineer", color: "white"};

// Check if the config file exists
if (fs.existsSync(CONFIG_PATH)) {
  config = JSON.parse(fs.readFileSync(CONFIG_PATH, "utf-8"));
}

app.get("/", (req, res) => {
  res.send(`
    <html>
      <body style="background-color: ${config.color}; text-align: center; padding: 50px;">
        <h1>Hello, I am ${config.name} 🚀</h1>
        <h2>Role: ${config.role}</h2>
        <p>GitHub: <a href="https://github.com/bansikah22">bansikah22</a></p>
        <p>GitLab: <a href="https://gitlab.com/tandapnoelbansikah">bansikah22</a></p>
        <p>LinkedIn: <a href="https://linkedin.com/in/tandapnoelbansikah">bansikah22</a></p>
      </body>
    </html>
  `);
});

app.listen(PORT, () => console.log(`Server running on port ${PORT}...`));
