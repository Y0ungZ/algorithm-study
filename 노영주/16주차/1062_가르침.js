const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const [N, K] = input[0].trim().split(" ").map(Number);
  const defaultArr = ["a", "n", "t", "i", "c"];
  const MAX = 26;
  const words = [];
  let DEFAULT_BIT = 0;
  let answer = 0;

  for (let n = 1; n <= N; n++) {
    words.push(input[n].trim().slice(4, -4));
  }

  for (let i = 0; i < defaultArr.length; i++) {
    DEFAULT_BIT = DEFAULT_BIT | (1 << (defaultArr[i].charCodeAt() - 97));
  }

  const Kcombination = (idx, select, currBit) => {
    if (idx > MAX) {
      return;
    }
    if (select === K) {
      let count = 0;
      for (let n = 0; n < N; n++) {
        const currWord = words[n];
        if (currWord === "") {
          count++;
          continue;
        }
        let flag = true;
        for (let ws = 0; ws < currWord.length; ws++) {
          const toIdx = 1 << (currWord[ws].charCodeAt() - 97);
          if ((DEFAULT_BIT & toIdx) === 0 && (currBit & toIdx) === 0) {
            flag = false;
            break;
          }
        }
        if (flag) {
          count++;
        }
      }
      answer = Math.max(count, answer);
      return;
    }

    if (!(DEFAULT_BIT & (1 << idx))) {
      const selectBit = currBit | (1 << idx);
      Kcombination(idx + 1, select + 1, selectBit);
    }
    Kcombination(idx + 1, select, currBit);
  };

  if (K < 5) {
    console.log(0);
  } else {
    Kcombination(0, 5, 0);
    console.log(answer);
  }
})();
