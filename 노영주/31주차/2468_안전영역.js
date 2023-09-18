const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");

  const N = +input[0];
  const map = [];
  let h = Infinity;

  for (let n = 1; n <= N; n++) {
    const line = input[n].trim().split(" ").map(Number);
    for (let m = 0; m < N; m++) {
      h = Math.min(line[m], h);
    }
    map.push(line);
  }

  let max = 1;
  const isSink = Array.from({ length: N }, () => Array(N).fill(false));

  const rainOfHeight = (height) => {
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        if (height >= map[i][j]) {
          isSink[i][j] = true;
        }
      }
    }
  };

  const checkSafeArea = (i, j, visited) => {
    const di = [-1, 1, 0, 0];
    const dj = [0, 0, -1, 1];

    const queue = [];
    queue.push([i, j]);
    visited[i][j] = true;

    let idx = 0;

    while (queue.length - idx !== 0) {
      const curr = queue[idx++];

      for (let d = 0; d < 4; d++) {
        const nextI = curr[0] + di[d];
        const nextJ = curr[1] + dj[d];

        if (nextI < 0 || nextI >= N || nextJ < 0 || nextJ >= N) {
          continue;
        }

        if (visited[nextI][nextJ]) {
          continue;
        }

        if (isSink[nextI][nextJ]) {
          continue;
        }

        queue.push([nextI, nextJ]);
        visited[nextI][nextJ] = true;
      }
    }
  };

  while (true) {
    const visited = Array.from({ length: N }, () => Array(N).fill(false));
    rainOfHeight(h);

    let count = 0;

    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        if (!isSink[i][j]) {
          if (visited[i][j]) {
            continue;
          }
          count++;
          checkSafeArea(i, j, visited);
        }
      }
    }

    if (count === 0) {
      break;
    }

    if (count > max) {
      max = count;
    }

    h++;
  }

  console.log(max);
})();
