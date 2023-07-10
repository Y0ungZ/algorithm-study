const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const N = +input[0];
  const numbers = input
    .slice(1)
    .map(Number)
    .sort((a, b) => a - b);
  const answer = [];

  const GCD = (a, b) => {
    if (b === 0) {
      return a;
    }
    return GCD(b, a % b);
  };

  let gcd = numbers[1] - numbers[0];

  for (let i = 2; i < N; i++) {
    gcd = GCD(gcd, numbers[i] - numbers[i - 1]);
  }

  for (let i = 2; i <= Math.sqrt(gcd); i++) {
    if (i ** 2 === gcd) {
      answer.push(i);
      continue;
    }
    if (gcd % i === 0) {
      answer.push(i);
      answer.push(gcd / i);
    }
  }

  answer.push(gcd);
  console.log(answer.sort((a, b) => a - b).join(" "));
})();
