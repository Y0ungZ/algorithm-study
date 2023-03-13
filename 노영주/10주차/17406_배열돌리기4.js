const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const [N, M, K] = input[0].trim().split(" ").map(Number);
  const A = [];
  const calculations = [];
  let answer = 5000;

  for (let n = 0; n < N; n++) {
    A.push(input[1 + n].trim().split(" ").map(Number));
  }

  for (let k = N; k < N + K; k++) {
    calculations.push(input[1 + k].trim().split(" ").map(Number));
  }

  const getMinRow = (arr) => {
    let minSum = 5000;

    for (let n = 0; n < N; n++) {
      let sum = 0;
      for (let m = 0; m < M; m++) {
        sum += arr[n][m];
      }

      minSum = Math.min(minSum, sum);
    }
    return minSum;
  };

  const getRotateArr = (r, c, s, arr) => {
    const copyArr = arr.map((row) => row.slice());

    let startRow = r - s - 1;
    let startCol = c - s - 1;
    let currS = s;

    while (currS > 0) {
      let tempRow = copyArr[startRow][startCol + currS * 2];

      for (let m = startCol + currS * 2; m > startCol; m--) {
        copyArr[startRow][m] = copyArr[startRow][m - 1];
      }

      let tempCol = copyArr[startRow + currS * 2][startCol + currS * 2];

      for (let n = startRow + currS * 2; n > startRow + 1; n--) {
        copyArr[n][startCol + currS * 2] = copyArr[n - 1][startCol + currS * 2];
      }

      copyArr[startRow + 1][startCol + currS * 2] = tempRow;
      tempRow = copyArr[startRow + currS * 2][startCol];

      for (let m = startCol; m < startCol + currS * 2 - 1; m++) {
        copyArr[startRow + currS * 2][m] = copyArr[startRow + currS * 2][m + 1];
      }

      copyArr[startRow + currS * 2][startCol + currS * 2 - 1] = tempCol;

      for (let n = startRow; n < startRow + currS * 2 - 1; n++) {
        copyArr[n][startCol] = copyArr[n + 1][startCol];
      }

      copyArr[startRow + currS * 2 - 1][startCol] = tempRow;

      startRow++;
      startCol++;
      currS--;
    }

    return copyArr;
  };

  const getPerm = (depth, order, visited) => {
    if (depth === K) {
      let currArr = A.map((row) => row.slice());
      for (let i = 0; i < K; i++) {
        const [r, c, s] = calculations[order[i]];
        currArr = getRotateArr(r, c, s, currArr);
      }
      answer = Math.min(answer, getMinRow(currArr));
      return;
    }

    for (let i = 0; i < K; i++) {
      if (!visited[i]) {
        visited[i] = true;
        order[depth] = i;
        getPerm(depth + 1, order, visited);
        visited[i] = false;
      }
    }
  };

  getPerm(0, Array(K).fill(0), Array(K).fill(false));
  console.log(answer);
})();
