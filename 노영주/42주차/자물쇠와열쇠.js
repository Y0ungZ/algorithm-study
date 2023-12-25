function solution(key, lock) {
  const M = key.length;
  const N = lock.length;
  const expandN = N + M * 2;
  let answer = false;

  const copyLock = () => {
    const newLock = Array.from({ length: expandN }, () =>
      Array(expandN).fill(0),
    );

    for (let row = 0; row < N; row++) {
      for (let col = 0; col < N; col++) {
        newLock[row + M][col + M] = lock[row][col];
      }
    }
    return newLock;
  };

  const rotateKey = key => {
    const newKey = [];
    for (let col = 0; col < M; col++) {
      const temp = [];
      for (let row = M - 1; row >= 0; row--) {
        temp.push(key[row][col]);
      }
      newKey.push(temp);
    }
    return newKey;
  };

  const match = (startR, startC, lock, key) => {
    for (let row = 0; row < M; row++) {
      for (let col = 0; col < M; col++) {
        lock[startR + row][startC + col] += key[row][col];
      }
    }
  };

  const restore = (startR, startC, lock, key) => {
    for (let row = 0; row < M; row++) {
      for (let col = 0; col < M; col++) {
        lock[startR + row][startC + col] -= key[row][col];
      }
    }
  };

  const isAllMatch = lock => {
    for (let row = 0; row < N; row++) {
      for (let col = 0; col < N; col++) {
        if (lock[row + M][col + M] !== 1) {
          return false;
        }
      }
    }
    return true;
  };

  for (let i = 0; i < 4; i++) {
    const newLock = copyLock();

    for (let row = 0; row < N + M; row++) {
      for (let col = 0; col < N + M; col++) {
        match(row, col, newLock, key);
        if (isAllMatch(newLock)) {
          answer = true;
          break;
        }
        restore(row, col, newLock, key);
      }
    }

    key = rotateKey(key);
  }

  return answer;
}
