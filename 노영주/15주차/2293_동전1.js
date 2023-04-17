const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const [N, K] = input[0].trim().split(" ").map(Number);
  const dp = Array(K + 1).fill(0);
  const coins = [];

  for (let n = 1; n <= N; n++) {
    coins.push(+input[n]);
  }

  for (let n = 0; n < N; n++) {
    dp[coins[n]]++;
    for (let k = 1; k <= K; k++) {
      if (k - coins[n] > 0) {
        dp[k] += dp[k - coins[n]];
      }
    }
  }

  console.log(dp[K]);
})();
