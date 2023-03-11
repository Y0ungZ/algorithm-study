const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const di = [-1, 1, 0, 0];
  const dj = [0, 0, -1, 1];

  const [N, M] = input[0].trim().split(" ").map(Number);
  const arr = [];
  let answer = 0;

  for (let n = 0; n < N; n++) {
    arr.push(input[1 + n].trim().split(" ").map(Number));
  }

  const isSeparation = () => {
    const queue = [];
    const visited = Array.from({ length: N }, () => Array(M).fill(true));
    let firstI = 0,
      firstJ = 0;

    for (let n = 0; n < N; n++) {
      for (let m = 0; m < M; m++) {
        if (arr[n][m] !== 0) {
          visited[n][m] = false;
          firstI = n;
          firstJ = m;
        }
      }
    }

    queue.push([firstI, firstJ]);
    visited[firstI][firstJ] = true;
    let index = 0;

    while (queue.length - index !== 0) {
      const [currI, currJ] = queue[index++];

      for (let d = 0; d < 4; d++) {
        const nextI = currI + di[d];
        const nextJ = currJ + dj[d];

        if (nextI < 0 || nextI >= N || nextJ < 0 || nextJ >= M) {
          continue;
        }

        if (arr[nextI][nextJ] === 0) {
          continue;
        }

        if (visited[nextI][nextJ]) {
          continue;
        }

        visited[nextI][nextJ] = true;
        queue.push([nextI, nextJ]);
      }
    }

    for (let n = 0; n < N; n++) {
      for (let m = 0; m < M; m++) {
        if (!visited[n][m]) {
          return true;
        }
      }
    }

    return false;
  };

  while (!isSeparation()) {
    answer++;

    const icebergs = [];
    const meltingInfo = [];

    for (let n = 0; n < N; n++) {
      for (let m = 0; m < M; m++) {
        if (arr[n][m] !== 0) {
          icebergs.push([n, m]);
        }
      }
    }

    if (icebergs.length === 0) {
      break;
    }

    for (let i = 0; i < icebergs.length; i++) {
      const [currI, currJ] = icebergs[i];
      let contactCount = 0;
      for (let d = 0; d < 4; d++) {
        const nextI = currI + di[d];
        const nextJ = currJ + dj[d];

        if (arr[nextI][nextJ] === 0) {
          contactCount++;
        }
      }

      meltingInfo.push([currI, currJ, contactCount]);
    }

    for (let i = 0; i < meltingInfo.length; i++) {
      const [currI, currJ, cnt] = meltingInfo[i];
      const nextHeight = arr[currI][currJ] - cnt;

      arr[currI][currJ] = nextHeight < 0 ? 0 : nextHeight;
    }
  }

  console.log(isSeparation() ? answer : 0);
})();
