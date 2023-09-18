const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const N = +input[0];
  const numbers = input[1].trim().split(" ").map(Number);
  const M = +input[2];

  // dp[i][j] => i(시작 인덱스) ~ j(종료 인덱스)까지의 팰린드롬 여부(boolean) 기록
  const dp = Array.from({ length: N }, () => Array(N).fill(false));
  const answer = [];

  // E-S = 1, 모두 팰린드롬이다.
  for (let i = 0; i < N; i++) {
    dp[i][i] = true;
  }

  // E-S = 2, 바로 다음수가 같다면 팰린드롬이다.
  for (let i = 0; i < N - 1; i++) {
    if (numbers[i] === numbers[i + 1]) {
      dp[i][i + 1] = true;
    }
  }

  // E-S = 3 ~
  for (let i = 1; i < N; i++) {
    for (let j = 0; j < N - i; j++) {
      if (numbers[j] === numbers[j + i] && dp[j + 1][j + i - 1]) {
        dp[j][j + i] = true;
      }
    }
  }

  for (let m = 0; m < M; m++) {
    const [S, E] = input[3 + m].trim().split(" ").map(Number);
    dp[S - 1][E - 1] ? answer.push(1) : answer.push(0);
  }

  console.log(answer.join("\n"));
})();
