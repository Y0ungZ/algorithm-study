const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const N = +input[0];
  const cards = input[1].trim().split(" ").map(Number);
  const prefixSum = Array(N).fill(0);
  let prefixOdd = 0;
  let prefixEven = 0;
  let maxPrefix = 0;

  for (let i = 0; i < N / 2; i++) {
    prefixEven += cards[i * 2];
    prefixSum[i * 2] = prefixEven;
    prefixOdd += cards[i * 2 + 1];
    prefixSum[i * 2 + 1] = prefixOdd;
  }

  for (let i = 0; i < N; i++) {
    const preset = i - 1 < 0 ? 0 : prefixSum[Math.floor((i - 1) / 2) * 2];
    let rightSum;
    let leftSum;
    if (i % 2 === 0) {
      rightSum = N - 1 < 0 ? 0 : prefixSum[N - 1];
      leftSum = i - 1 < 0 ? 0 : prefixSum[i - 1];
    } else {
      rightSum = N - 3 < 0 ? 0 : prefixSum[N - 3];
      leftSum = i - 2 < 0 ? 0 : prefixSum[i - 2];
    }
    maxPrefix = Math.max(maxPrefix, preset + rightSum - leftSum);
  }

  console.log(maxPrefix);
})();
