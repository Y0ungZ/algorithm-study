const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const [N, M] = input[0].trim().split(" ").map(Number);
  const lectures = input[1].trim().split(" ").map(Number);
  let left = Math.max(...lectures);
  let right = lectures.reduce((prev, curr) => prev + curr, 0);

  while (left <= right) {
    const middle = Math.floor((left + right) / 2);

    let sum = 0,
      cnt = 0;

    for (let n = 0; n < N; n++) {
      if (sum + lectures[n] > middle) {
        sum = 0;
        cnt++;
      }
      sum += lectures[n];
    }

    if (sum > 0) {
      cnt++;
    }

    if (cnt <= M) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }

  console.log(left);
})();
