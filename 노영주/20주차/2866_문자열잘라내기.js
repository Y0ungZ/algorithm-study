const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const [R, C] = input[0].trim().split(" ").map(Number);
  const table = [];

  for (let r = 1; r <= R; r++) {
    table.push(input[r].trim().split(""));
  }

  let left = 0,
    right = R;
  while (left <= right) {
    const middle = Math.floor((left + right) / 2);
    const recordObj = {};
    let flag = true;

    for (let c = 0; c < C; c++) {
      let str = "";
      for (let r = middle; r < R; r++) {
        str += table[r][c];
      }

      if (recordObj[str]) {
        flag = false;
        break;
      } else {
        recordObj[str] = 1;
      }
    }

    if (flag) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }

  console.log(left - 1);
})();
