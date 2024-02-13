function solution(land) {
  let answer = 0;

  const N = land.length;
  const M = land[0].length;
  const oilMap = new Map();

  const getUndefinedLand = () => {
    return Array.from({ length: N }, () => Array(M).fill(undefined));
  };

  const extractOil = ([startN, startM], extractedLand, type) => {
    const directions = [
      [0, 1],
      [1, 0],
      [0, -1],
      [-1, 0],
    ];

    const queue = [];
    let idx = 0;

    queue.push([startN, startM]);
    extractedLand[startN][startM] = type;

    while (queue.length - idx !== 0) {
      const [currN, currM] = queue[idx++];

      for (let d = 0; d < 4; d++) {
        const nextN = currN + directions[d][0];
        const nextM = currM + directions[d][1];

        if (nextN < 0 || nextN >= N || nextM < 0 || nextM >= M) {
          continue;
        }

        if (extractedLand[nextN][nextM] === type) {
          continue;
        }

        if (land[nextN][nextM] === 0) {
          continue;
        }

        queue.push([nextN, nextM]);
        extractedLand[nextN][nextM] = type;
      }
    }

    return queue.length;
  };

  const extractedLand = getUndefinedLand();
  let type = 1;

  for (let m = 0; m < M; m++) {
    for (let n = 0; n < N; n++) {
      if (land[n][m] !== 0 && !extractedLand[n][m]) {
        const oil = extractOil([n, m], extractedLand, type);
        oilMap.set(type++, oil);
      }
    }
  }

  for (let m = 0; m < M; m++) {
    const typeSet = new Set();
    let oil = 0;
    for (let n = 0; n < N; n++) {
      const type = extractedLand[n][m];
      if (type) {
        if (!typeSet.has(type)) {
          oil += oilMap.get(type);
          typeSet.add(type);
        }
      }
    }
    answer = Math.max(oil, answer);
  }

  return answer;
}
