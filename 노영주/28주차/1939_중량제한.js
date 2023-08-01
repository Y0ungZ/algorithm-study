const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");

  const [N, M] = input[0].trim().split(" ").map(Number);
  const bridge = {};
  let low = 0,
    high = 0;

  for (let n = 1; n <= N; n++) {
    bridge[n] = new Map();
  }

  for (let m = 1; m <= M; m++) {
    const [a, b, c] = input[m].trim().split(" ").map(Number);
    high = Math.max(high, c);
    if (!bridge[a].get(b)) {
      bridge[a].set(b, c);
      bridge[b].set(a, c);
      continue;
    }

    const origin = bridge[a].get(b);
    if (origin > c) {
      continue;
    }
    bridge[a].set(b, c);
    bridge[b].set(a, c);
  }

  const [start, end] = input[1 + M].trim().split(" ").map(Number);

  const bfs = (cost) => {
    const queue = [];
    const visited = Array(N + 1).fill(false);
    queue.push(start);
    visited[start] = true;

    let idx = 0;
    while (queue.length - idx !== 0) {
      const currIsland = queue[idx++];

      if (currIsland === end) {
        return true;
      }

      const adjList = Array.from(bridge[currIsland]);
      for (let i = 0; i < adjList.length; i++) {
        const [nextIsland, nextCost] = adjList[i];
        if (visited[nextIsland]) continue;
        if (nextCost < cost) continue;
        queue.push(nextIsland);
        visited[nextIsland] = true;
      }
    }
    return false;
  };

  while (low <= high) {
    const mid = Math.floor((low + high) / 2);

    if (bfs(mid)) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  console.log(high);
})();
