const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const A = input[1].trim().split(" ").map(Number);
  const lis = [];
  lis.push(A[0]);

  const binarySearch = (number) => {
    let left = 0,
      right = lis.length;

    while (left < right) {
      const middle = Math.floor((left + right) / 2);

      if (lis[middle] < number) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }

    return right;
  };

  for (let i = 1; i < A.length; i++) {
    if (lis[lis.length - 1] < A[i]) {
      lis.push(A[i]);
    } else {
      const index = binarySearch(A[i]);
      lis[index] = A[i];
    }
  }

  console.log(lis.length);
})();
