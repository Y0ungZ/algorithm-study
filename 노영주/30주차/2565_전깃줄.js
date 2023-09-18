const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const N = +input[0];
  const wires = [];

  for (let n = 1; n <= N; n++) {
    wires.push(input[n].trim().split(" ").map(Number));
  }

  wires.sort((a, b) => a[0] - b[0]);

  let maxCnt = 0;
  const dp = Array(N).fill(1);

  for (let i = 1; i < N; i++) {
    for (let j = 0; j < i; j++) {
      if (wires[i][1] > wires[j][1]) {
        dp[i] = Math.max(dp[i], dp[j] + 1);
      }
    }
    maxCnt = Math.max(maxCnt, dp[i]);
  }

  console.log(N - maxCnt);
})();
