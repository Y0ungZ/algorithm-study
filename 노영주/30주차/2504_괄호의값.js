const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim();
  const bracketNumbers = { "(": 2, ")": 2, "[": 3, "]": 3 };
  const closeBrackets = [")", "]"];
  const pairBrackets = { ")": "(", "]": "[" };
  const stack = [];

  let answer = 0;
  let x = 1;

  for (let i = 0; i < input.length; i++) {
    if (closeBrackets.includes(input[i])) {
      if (stack.length === 0) {
        answer = 0;
        break;
      }
      if (stack[stack.length - 1] !== pairBrackets[input[i]]) {
        break;
      }

      stack.pop();

      if (input[i - 1] === pairBrackets[input[i]]) {
        answer += x;
      }
      x /= bracketNumbers[input[i]];
      continue;
    }

    x *= bracketNumbers[input[i]];
    stack.push(input[i]);
  }

  if (stack.length) {
    console.log(0);
  } else {
    console.log(answer);
  }
})();
