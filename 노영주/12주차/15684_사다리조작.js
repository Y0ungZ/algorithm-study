const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const [N, M, H] = input[0].trim().split(" ").map(Number);
  const isConnected = Array.from({ length: H }, () => Array(N - 1).fill(false));

  for (let m = 1; m <= M; m++) {
    const [a, b] = input[m].trim().split(" ").map(Number);
    isConnected[a - 1][b - 1] = true;
  }

  const isOperationSuccess = (arr) => {
    for (let n = 0; n < N; n++) {
      let currResult = n;
      for (let h = 0; h < H; h++) {
        if (arr[h][currResult]) {
          currResult++;
          continue;
        }
        if (currResult !== 0 && arr[h][currResult - 1]) {
          currResult--;
        }
      }

      if (currResult !== n) {
        return false;
      }
    }
    return true;
  };

  let answer = Infinity;

  const getComb = (r, R, copyArr) => {
    if (r === 0) {
      if (isOperationSuccess(copyArr)) {
        answer = R;
      }
      return;
    }

    if (answer !== Infinity) {
      return;
    }

    for (let n = 0; n < N - 1; n++) {
      for (let h = 0; h < H; h++) {
        if (copyArr[h][n] || copyArr[h][n + 1]) {
          continue;
        }

        copyArr[h][n] = true;
        getComb(r - 1, R, copyArr);
        copyArr[h][n] = false;

        //사다리를 놓을 수 있을 때까지 현재 n(세로줄)에 대한 h를 찾음.
        while (h < H && !copyArr[h][n - 1] && !copyArr[h][n + 1]) {
          h++;
        }
      }
    }
  };
  for (let r = 0; r <= 3; r++) {
    getComb(
      r,
      r,
      isConnected.map((row) => row.slice())
    );
  }

  answer === Infinity ? console.log(-1) : console.log(answer);
})();
