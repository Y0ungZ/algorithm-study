const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const [N, K] = input[0].trim().split(" ").map(Number);
  const numbers = input[1].trim().split(" ").map(Number);
  const prefixSum = Array(numbers.length + 1).fill(0);
  const prefixMap = new Map();
  let answer = BigInt(0);

  for (let i = 1; i <= numbers.length; i++) {
    prefixSum[i] = prefixSum[i - 1] + numbers[i - 1];
    if (prefixSum[i] === K) answer += BigInt(1);
  }

  const convertUndefinedToZero = (value) => {
    return value === undefined ? BigInt(0) : BigInt(value);
  };

  for (let i = 1; i <= numbers.length; i++) {
    const value = convertUndefinedToZero(prefixMap.get(prefixSum[i] - K));
    answer += value;
    prefixMap.set(prefixSum[i], convertUndefinedToZero(prefixMap.get(prefixSum[i])) + BigInt(1));
  }

  console.log(answer.toString());
})();
