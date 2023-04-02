const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const [N, D] = input[0].trim().split(" ").map(Number);
  const dp = Array(D + 1)
    .fill(0)
    .map((_, idx) => idx);
  const shortCuts = [];

  for (let n = 1; n <= N; n++) {
    shortCuts.push(input[n].trim().split(" ").map(Number));
  }

  for (let i = 1; i <= D; i++) {
    dp[i] = Math.min(dp[i], dp[i - 1] + 1);

    for (let j = 0; j < shortCuts.length; j++) {
      const [start, end, length] = shortCuts[j];
      if (i === end) {
        dp[i] = Math.min(dp[i], dp[start] + length);
      }
    }
  }

  console.log(dp[D]);
})();
