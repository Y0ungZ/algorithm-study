const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const N = +input[0].trim();
  const numbers = input[1].trim().split(" ").map(Number);
  let answer = -1000;
  let sum = 0;

  numbers.forEach((number) => {
    sum += number;
    answer = Math.max(sum, answer);
    if (sum < 0) {
      sum = 0;
    }
  });

  console.log(answer);
})();
