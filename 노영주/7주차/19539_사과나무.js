const main = (() => {
  const SUCCESS_MSG = "YES";
  const FAIL_MSG = "NO";

  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const N = +input[0];
  const trees = input[1].split(" ").map(Number);
  let flag = false;
  let sum = 0,
    twoCnt = 0;

  trees.forEach((tree) => {
    const quotient = Math.floor(tree / 2);
    twoCnt += quotient;
    sum += tree;
  });

  if (sum % 3 === 0 && Math.floor(sum / 3) <= twoCnt) {
    flag = true;
  }

  if (flag) {
    console.log(SUCCESS_MSG);
  } else {
    console.log(FAIL_MSG);
  }
})();
