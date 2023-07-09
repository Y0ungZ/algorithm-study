const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const [N, M] = input[0].trim().split(" ").map(Number);
  const adjList = {};

  for (let n = 1; n <= N; n++) {
    adjList[n] = [];
  }

  for (let m = 1; m <= M; m++) {
    const [A, B] = input[m].trim().split(" ").map(Number);
    adjList[B].push(A);
  }

  let max = 0;
  let answer = [];

  const bfs = (start, visited) => {
    const queue = [];
    queue.push(start);
    visited[start] = true;
    let idx = 0;
    let count = 0;

    while (queue.length - idx !== 0) {
      const current = queue[idx++];
      count++;
      const nextComputers = adjList[current];

      for (let i = 0; i < nextComputers.length; i++) {
        if (!visited[nextComputers[i]]) {
          visited[nextComputers[i]] = true;
          queue.push(nextComputers[i]);
        }
      }
    }

    if (max > count) {
      return;
    }

    if (max === count) {
      answer.push(start);
    }

    if (max < count) {
      max = count;
      answer = [];
      answer.push(start);
    }
  };

  for (let n = 1; n <= N; n++) {
    const visited = Array(N + 1).fill(false);
    bfs(n, visited);
  }

  console.log(answer.join(" "));
})();
