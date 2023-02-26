const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const N = +input[0];
  const K = +input[1];
  let answer = 0;
  let left = 1,
    right = K;

  while (left <= right) {
    let cnt = 0;
    let middle = Math.floor((left + right) / 2);
    for (let i = 1; i <= N; i++) {
      cnt += Math.min(Math.floor(middle / i), N);
    }

    if (cnt >= K) {
      answer = middle;
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }

  console.log(answer);
})();
