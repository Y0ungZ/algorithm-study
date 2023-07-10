const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const SUCCESS_MSG = "YES";
  const FAIL_MSG = "NO";
  const N = +input[0];
  const M = +input[1];
  const cityConnectInfo = {};

  for (let n = 1; n <= N; n++) {
    cityConnectInfo[n] = [];
  }

  for (let i = 2; i < 2 + N; i++) {
    const currCityConnectInfo = input[i].trim().split(" ").map(Number);
    for (let j = 0; j < N; j++) {
      if (i - 1 === j + 1) {
        continue;
      }
      if (currCityConnectInfo[j] === 1) {
        cityConnectInfo[i - 1].push(j + 1);
      }
    }
  }

  const bfs = (start, end) => {
    const visited = Array(N + 1).fill(false);
    let isOK = false;
    const queue = [];
    queue.push(start);
    visited[start] = true;

    let idx = 0;

    while (queue.length - idx !== 0) {
      const currCity = queue[idx++];

      if (currCity === end) {
        isOK = true;
        break;
      }

      const nextCitys = cityConnectInfo[currCity];
      for (let i = 0; i < nextCitys.length; i++) {
        if (visited[nextCitys[i]]) {
          continue;
        }
        queue.push(nextCitys[i]);
        visited[nextCitys[i]] = true;
      }
    }

    return isOK;
  };

  const plan = input[2 + N].trim().split(" ").map(Number);
  let isOK = true;

  for (let i = 0; i < plan.length - 1; i++) {
    if (!bfs(plan[i], plan[i + 1])) {
      isOK = false;
      break;
    }
  }

  isOK ? console.log(SUCCESS_MSG) : console.log(FAIL_MSG);
})();
