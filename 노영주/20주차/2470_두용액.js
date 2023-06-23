const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const N = +input[0].trim();
  const solutions = input[1].trim().split(" ").map(Number);
  let min = Infinity;
  let answer;
  let left = 0,
    right = N - 1;

  solutions.sort((a, b) => a - b);

  while (left < right) {
    const mix = solutions[left] + solutions[right];

    if (min > Math.abs(mix - 0)) {
      min = Math.abs(mix - 0);
      answer = [solutions[left], solutions[right]];
    }

    if (mix < 0) {
      left++;
    } else {
      right--;
    }
  }

  console.log(answer.join(" "));
})();
