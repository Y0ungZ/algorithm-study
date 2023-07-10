const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");

  const SUCCESS_MSG = "YES";
  const FAIL_MSG = "NO";

  const T = +input[0];
  let line = 1;
  const answer = [];

  for (let t = 0; t < T; t++) {
    let isConsist = true;
    const N = +input[line];
    const phoneNumbers = [];

    for (let i = line + 1; i <= line + N; i++) {
      phoneNumbers.push(input[i].trim());
    }

    phoneNumbers.sort();
    let prevLen = 0;

    for (let i = 0; i < phoneNumbers.length; i++) {
      if (phoneNumbers[i].slice(0, prevLen) === phoneNumbers[i - 1]) {
        isConsist = false;
        break;
      }
      prevLen = phoneNumbers[i].length;
    }

    if (isConsist) {
      answer.push(SUCCESS_MSG);
    } else {
      answer.push(FAIL_MSG);
    }
    line += N + 1;
  }

  console.log(answer.join("\n"));
})();
