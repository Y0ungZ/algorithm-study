const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const [N, L, R] = input[0].trim().split(" ").map(Number);
  const di = [-1, 0, 1, 0];
  const dj = [0, -1, 0, 1];
  const map = [];
  let answer = 0;

  for (let n = 0; n < N; n++) {
    map.push(input[n + 1].trim().split(" ").map(Number));
  }

  const bfs = (i, j, visitMap) => {
    const queue = [];
    queue.push([i, j]);
    visitMap[i][j] = true;

    let index = 0;

    //자기 자신(i,j) count
    let sumPeople = map[i][j];
    let unionCount = 1;

    while (queue.length - index !== 0) {
      const [currI, currJ] = queue[index++];

      for (let d = 0; d < 4; d++) {
        const nextI = currI + di[d];
        const nextJ = currJ + dj[d];

        if (nextI < 0 || nextI >= N || nextJ < 0 || nextJ >= N) {
          continue;
        }

        if (visitMap[nextI][nextJ]) {
          continue;
        }

        const difference = Math.abs(map[nextI][nextJ] - map[currI][currJ]);

        if (difference >= L && difference <= R) {
          sumPeople += map[nextI][nextJ];
          unionCount++;
          visitMap[nextI][nextJ] = true;
          queue.push([nextI, nextJ]);
        }
      }
    }

    const unionResult = Math.floor(sumPeople / unionCount);

    if (queue.length === 1) {
      //연합국가가 존재하지 않음.
      return [null, null];
    }

    //[연합국가 좌표정보 queue, 연합 인구수 결과]
    return [queue, unionResult];
  };

  while (true) {
    let isOpen = false;

    const visitMap = Array.from({ length: N }, () => Array(N).fill(false));

    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        if (visitMap[i][j]) {
          continue;
        }

        const [queue, unionResult] = bfs(i, j, visitMap);

        if (queue === null) {
          continue;
        }

        for (let q = 0; q < queue.length; q++) {
          const [currI, currJ] = queue[q];
          isOpen = true;
          map[currI][currJ] = unionResult;
        }
      }
    }

    if (!isOpen) {
      //연합국가가 존재하지 않음.
      break;
    }

    //인구이동이 무사히 일어났고, 다음 인구이동을 준비함(처음으로).
    answer++;
  }

  console.log(answer);
})();
