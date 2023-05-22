const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const di = [-1, 1, 0, 0];
  const dj = [0, 0, -1, 1];
  const [N, Q] = input[0].trim().split(" ").map(Number);
  const POW_N = Math.pow(2, N);
  let lumpCount = 0;

  let map = [];
  for (let n = 1; n <= POW_N; n++) {
    map.push(input[n].trim().split(" ").map(Number));
  }

  const stages = input[POW_N + 1].trim().split(" ").map(Number);

  const divideMap = (l) => {
    const POW_L = Math.pow(2, l);
    const rotateMap = map.map((row) => row.slice());

    const rotateClockwise = (startI, startJ) => {
      for (let i = startI; i < startI + POW_L; i++) {
        for (let j = 0; j < POW_L; j++) {
          rotateMap[startI + j][startJ + POW_L - Math.abs(startI - i) - 1] = map[i][startJ + j];
        }
      }
    };

    for (let i = 0; i < POW_N; i += POW_L) {
      for (let j = 0; j < POW_N; j += POW_L) {
        rotateClockwise(i, j);
      }
    }

    map = rotateMap;
  };

  const subtractionCheck = () => {
    const subtractMap = map.map((row) => row.slice());

    for (let i = 0; i < POW_N; i++) {
      for (let j = 0; j < POW_N; j++) {
        if (map[i][j] === 0) {
          continue;
        }

        let count = 0;
        for (let d = 0; d < 4; d++) {
          const checkI = i + di[d];
          const checkJ = j + dj[d];

          if (checkI < 0 || checkI >= POW_N || checkJ < 0 || checkJ >= POW_N) {
            continue;
          }

          if (map[checkI][checkJ] !== 0) {
            count++;
          }
        }

        if (count < 3) {
          subtractMap[i][j]--;
        }
      }
    }

    map = subtractMap;
  };

  stages.forEach((stage) => {
    if (stage !== 0) {
      divideMap(stage);
    }
    subtractionCheck();
  });

  const visited = Array.from({ length: POW_N }, () => Array(POW_N).fill(false));

  const getSum = () => {
    let sum = 0;
    for (let i = 0; i < POW_N; i++) {
      for (let j = 0; j < POW_N; j++) {
        sum += map[i][j];
        if (map[i][j] !== 0 && !visited[i][j]) {
          lumpCount = Math.max(lumpCount, checkLump(i, j));
        }
      }
    }
    return sum;
  };

  const checkLump = (startI, startJ) => {
    const queue = [];
    queue.push([startI, startJ]);
    visited[startI][startJ] = true;
    let index = 0;

    while (queue.length - index !== 0) {
      const [currI, currJ] = queue[index++];

      for (let d = 0; d < 4; d++) {
        const nextI = currI + di[d];
        const nextJ = currJ + dj[d];

        if (nextI < 0 || nextI >= POW_N || nextJ < 0 || nextJ >= POW_N) {
          continue;
        }

        if (map[nextI][nextJ] === 0) {
          continue;
        }

        if (visited[nextI][nextJ]) {
          continue;
        }

        visited[nextI][nextJ] = true;
        queue.push([nextI, nextJ]);
      }
    }

    return queue.length;
  };

  console.log(getSum());
  console.log(lumpCount);
})();
