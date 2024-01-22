const main = (() => {
  const fs = require('fs');
  const filePath = process.platform === 'linux' ? '/dev/stdin' : 'input.txt';
  const input = fs.readFileSync(filePath).toString().trim().split('\n');
  const N = +input[0];
  let answer = 0;
  let start = 0,
    end = 0;

  for (let n = 1; n <= N; n++) {
    const [x, y] = input[n].trim().split(' ').map(Number);
    if (n === 1) {
      start = x;
      end = y;
      answer += Math.abs(end - start);
      continue;
    }

    if (x <= end) {
      if (y <= end) {
        continue;
      }

      answer += Math.abs(y - end);
      end = y;
    } else {
      start = x;
      end = y;
      answer += Math.abs(end - start);
    }
  }

  console.log(answer);
})();
