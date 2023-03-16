const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");

  const dn = [-1, 1, 0, 0];
  const dm = [0, 0, -1, 1];

  const [N, M] = input[0].trim().split(" ").map(Number);
  const maze = [];
  let answer = Infinity;

  for (let n = 0; n < N; n++) {
    maze.push(input[1 + n].trim().split(""));
  }

  /**
   * 미로 탈출 bfs
   * @param {number[]} startInfo - 시작 위치 n,m이 담겨 있음.
   */
  const bfs = (startInfo) => {
    const queue = [];
    const visited = Array.from({ length: 1 << 6 }, () =>
      Array.from({ length: N }, () => Array(M).fill(false))
    );

    queue.push([0, ...startInfo]);
    visited[0][startInfo[0]][startInfo[1]] = true;

    let idx = 0;
    let moveCnt = 0;

    while (queue.length - idx !== 0) {
      const size = queue.length - idx;

      for (let s = 0; s < size; s++) {
        const [keyInfo, currN, currM] = queue[idx++];

        if (maze[currN][currM] === "1") {
          answer = moveCnt;
          break;
        }

        for (let d = 0; d < 4; d++) {
          const nextN = currN + dn[d];
          const nextM = currM + dm[d];

          if (nextN < 0 || nextN >= N || nextM < 0 || nextM >= M) {
            continue;
          }

          if (maze[nextN][nextM] === "#") {
            continue;
          }

          if (visited[keyInfo][nextN][nextM]) {
            continue;
          }

          let updateKeyInfo = 0;

          if (maze[nextN][nextM].match(new RegExp(/^[A-F]/)) !== null) {
            if (!(keyInfo & (1 << (maze[nextN][nextM].charCodeAt(0) - 65)))) {
              continue;
            }
          } else if (maze[nextN][nextM].match(new RegExp(/^[a-f]/)) !== null) {
            if (!(keyInfo & (1 << (maze[nextN][nextM].charCodeAt(0) - 97)))) {
              updateKeyInfo = keyInfo | (1 << (maze[nextN][nextM].charCodeAt(0) - 97));
            }
          }

          visited[keyInfo][nextN][nextM] = true;
          if (updateKeyInfo) {
            queue.push([updateKeyInfo, nextN, nextM]);
          } else {
            queue.push([keyInfo, nextN, nextM]);
          }
        }
      }

      if (answer !== Infinity) {
        break;
      }

      moveCnt++;
    }
  };

  let startN = 0,
    startM = 0;

  for (let n = 0; n < N; n++) {
    if (startN !== 0 || startM !== 0) {
      break;
    }
    for (let m = 0; m < M; m++) {
      if (maze[n][m] === "0") {
        startN = n;
        startM = m;
      }
    }
  }

  maze[startN][startM] = ".";
  bfs([startN, startM]);

  console.log(answer === Infinity ? -1 : answer);
})();
