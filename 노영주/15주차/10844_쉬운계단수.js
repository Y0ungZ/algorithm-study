const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const N = +fs.readFileSync(filePath).toString().trim();
  const dp = Array.from({ length: N + 1 }, () => Array(10).fill(0));
  const FIX_NUM = 1000000000;

  for (let i = 1; i < 10; i++) {
    dp[1][i] = 1;
  }

  for (let n = 2; n <= N; n++) {
    for (let i = 0; i < 10; i++) {
      if (i === 0) {
        dp[n][i] = dp[n - 1][1];
        continue;
      }
      if (i === 9) {
        dp[n][i] = dp[n - 1][8];
        continue;
      }
      dp[n][i] = (dp[n - 1][i - 1] + dp[n - 1][i + 1]) % FIX_NUM;
    }
  }

  const sum = dp[N].reduce((prev, curr) => prev + curr, 0);
  console.log(sum % FIX_NUM);
})();
