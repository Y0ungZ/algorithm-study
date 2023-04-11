const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const N = +input[0];
  const parentRecord = {};
  const visited = Array(N + 1).fill(false);
  const [A, B] = input[1].trim().split(" ").map(Number);
  const M = +input[2];

  for (let n = 1; n <= N; n++) {
    parentRecord[n] = [];
  }

  for (let m = 3; m < M + 3; m++) {
    const [parents, child] = input[m].trim().split(" ").map(Number);
    parentRecord[child].push(parents);
    parentRecord[parents].push(child);
  }

  let answer = 0;
  let isFamily = false;

  const calcDegreeOfKinship = (curr, cnt, target) => {
    if (curr === target) {
      isFamily = true;
      answer = cnt;
      return;
    }
    if (visited[curr]) {
      return;
    }

    visited[curr] = true;

    for (let i = 0; i < parentRecord[curr].length; i++) {
      calcDegreeOfKinship(parentRecord[curr][i], cnt + 1, target);
    }
  };

  calcDegreeOfKinship(A, 0, B);
  isFamily ? console.log(answer) : console.log(-1);
})();
