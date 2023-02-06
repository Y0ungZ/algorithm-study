const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim();
  const answer = [];
  const tempStr = Array(input.length).fill("");

  const getMinIdx = (startIdx, endIdx) => {
    let minIdx = startIdx;
    for (let i = startIdx; i <= endIdx; i++) {
      if (input[minIdx] > input[i]) {
        minIdx = i;
      }
    }
    return minIdx;
  };

  const zoac = (startIdx, endIdx) => {
    if (startIdx > endIdx) {
      return;
    }

    const currentIdx = getMinIdx(startIdx, endIdx);
    tempStr[currentIdx] = input[currentIdx];
    answer.push(tempStr.join(""));

    zoac(currentIdx + 1, endIdx);
    zoac(startIdx, currentIdx - 1);
  };

  zoac(0, input.length - 1);
  console.log(answer.join("\n"));
})();
