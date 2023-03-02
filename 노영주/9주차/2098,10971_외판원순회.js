const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const N = +input[0];
  const FINISHED = (1 << N) - 1;
  const costs = [];
  const dp = Array.from({ length: N }, () => Array(1 << N).fill(0));

  for (let n = 0; n < N; n++) {
    costs.push(input[1 + n].trim().split(" ").map(Number));
  }

  const TSP = (curr, visited) => {
    if (visited === FINISHED) {
      if (costs[curr][0] !== 0) {
        return costs[curr][0];
      }
      return Infinity;
    }

    if (dp[curr][visited] !== 0) {
      return dp[curr][visited];
    }

    dp[curr][visited] = Infinity;

    for (let n = 0; n < N; n++) {
      if (costs[curr][n] === 0) {
        //갈 수 없는 도시.
        continue;
      }
      if (visited & (1 << n)) {
        //이미 방문한 도시.
        continue;
      }

      //n번 도시 방문 처리 후 최소 비용 계산.
      const nextCosts = TSP(n, visited | (1 << n));
      dp[curr][visited] = Math.min(dp[curr][visited], costs[curr][n] + nextCosts);
    }

    return dp[curr][visited];
  };

  console.log(TSP(0, 1));
})();
