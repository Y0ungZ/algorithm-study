const main = (() => {
  const SUCCESS_MSG = "PPAP";
  const FAIL_MSG = "NP";

  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim();
  let pCnt = 0;

  for (let i = 0; i < input.length; i++) {
    if (input[i] === "P") {
      pCnt++;
      continue;
    }
    if (pCnt >= 2 && input[i + 1] === "P") {
      pCnt--;
      i++;
    } else {
      pCnt = -1;
      break;
    }
  }

  if (pCnt === 1) {
    console.log(SUCCESS_MSG);
  } else {
    console.log(FAIL_MSG);
  }
})();
