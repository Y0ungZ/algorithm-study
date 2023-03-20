const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const ironRods = fs.readFileSync(filePath).toString().trim().split("");
  let answer = 0;
  let openBracketCnt = 0;

  for (let i = 0; i < ironRods.length; i++) {
    switch (ironRods[i]) {
      case "(":
        if (ironRods[i + 1] === ")") {
          answer += openBracketCnt;
          i++;
        } else {
          openBracketCnt++;
        }
        break;
      case ")":
        openBracketCnt--;
        answer++;
        break;
      default:
        break;
    }
  }

  console.log(answer);
})();
