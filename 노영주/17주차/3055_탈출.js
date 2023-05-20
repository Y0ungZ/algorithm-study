const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const [R, C] = input[0].trim().split(" ").map(Number);
  const FAIL_STR = "KAKTUS";
  const map = [];

  let startR = 0;
  let startC = 0;

  let answer = Infinity;

  for (let r = 1; r <= R; r++) {
    const line = input[r].trim().split("");
    for (let c = 0; c < C; c++) {
      if (line[c] === "S") {
        startR = r - 1;
        startC = c;
      }
    }
    map.push(line);
  }

  /**
   * 고슴도치 이동 bfs
   * @param {number[]} startRC - 시작 위치 [r,c]가 담겨있음.
   */
  const bfs = (startRC) => {
    const visited = Array.from({ length: R }, () => Array(C).fill(false));

    const dr = [-1, 1, 0, 0];
    const dc = [0, 0, -1, 1];

    const queue = [];
    let index = 0;
    let time = 0;

    let [startR, starC] = startRC;

    queue.push([startR, startC]);
    visited[startR][starC] = true;

    const floodMap = () => {
      const floodLands = [];
      for (let r = 0; r < R; r++) {
        for (let c = 0; c < C; c++) {
          if (map[r][c] === "*") {
            for (let d = 0; d < 4; d++) {
              const nextLandR = r + dr[d];
              const nextLandC = c + dc[d];

              if (nextLandR >= R || nextLandR < 0 || nextLandC >= C || nextLandC < 0) {
                continue;
              }

              if (map[nextLandR][nextLandC] === ".") {
                floodLands.push([nextLandR, nextLandC]);
              }
            }
          }
        }
      }

      for (const [r, c] of floodLands) {
        map[r][c] = "*";
      }
    };

    while (queue.length - index !== 0) {
      floodMap();
      const size = queue.length - index;

      for (let s = 0; s < size; s++) {
        const [currR, currC] = queue[index++];

        if (map[currR][currC] === "D") {
          answer = time;
          break;
        }

        for (let d = 0; d < 4; d++) {
          const nextR = currR + dr[d];
          const nextC = currC + dc[d];

          if (nextR >= R || nextR < 0 || nextC >= C || nextC < 0) {
            continue;
          }

          if (map[nextR][nextC] === "*" || map[nextR][nextC] === "X") {
            continue;
          }

          if (visited[nextR][nextC]) {
            continue;
          }

          queue.push([nextR, nextC]);
          visited[nextR][nextC] = true;
        }
      }
      time++;
    }
  };

  bfs([startR, startC]);

  answer === Infinity ? console.log(FAIL_STR) : console.log(answer);
})();
