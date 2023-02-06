const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");

  const S = input[0].trim();
  const T = input[1].trim();

  let answer = 0;

  const reverseString = (str) => {
    let newStr = "";
    for (let i = str.length - 1; i >= 0; i--) {
      newStr += str[i];
    }
    return newStr;
  };

  const dfs = (str) => {
    if (answer || str.length < 1) {
      return;
    }

    if (str.length === S.length) {
      if (str === S) {
        answer = 1;
      }
      return;
    }

    if (str[str.length - 1] === "A") {
      dfs(str.slice(0, -1));
    }

    if (str[0] === "B") {
      dfs(reverseString(str.slice(1)));
    }
  };

  dfs(T);
  console.log(answer);
})();
