const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const dr = [1, 0];
  const dc = [0, -1];

  const N = +input[0].trim();
  const board = [];
  let answer = 0;

  for (let n = 1; n <= N; n++) {
    board.push(input[n].trim().split(""));
  }

  const countMaxCandy = (inputBoard) => {
    let max = 0;
    for (let r = 0; r < N; r++) {
      let count = 1;
      for (let c = 0; c < N - 1; c++) {
        if (inputBoard[r][c] === inputBoard[r][c + 1]) {
          count++;
        } else {
          count = 1;
        }
        max = Math.max(max, count);
      }
    }

    for (let c = 0; c < N; c++) {
      let count = 1;
      for (let r = 0; r < N - 1; r++) {
        if (inputBoard[r][c] === inputBoard[r + 1][c]) {
          count++;
        } else {
          count = 1;
        }
        max = Math.max(max, count);
      }
    }
    answer = Math.max(answer, max);
  };

  countMaxCandy(board);

  for (let r = 0; r < N; r++) {
    for (let c = 0; c < N; c++) {
      for (let d = 0; d < 2; d++) {
        const nextR = r + dr[d];
        const nextC = c + dc[d];

        if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N) {
          continue;
        }

        if (board[r][c] === board[nextR][nextC]) {
          continue;
        }

        const copyMap = board.map((row) => row.slice());
        [copyMap[r][c], copyMap[nextR][nextC]] = [copyMap[nextR][nextC], copyMap[r][c]];
        countMaxCandy(copyMap);
      }
    }
  }

  console.log(answer);
})();
