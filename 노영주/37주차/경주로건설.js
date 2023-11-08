function solution(board) {
  const N = board.length;
  const CORNER_PRICE = 500;
  const LINE_PRICE = 100;
  const direction = [
    [0, -1],
    [0, 1],
    [1, 0],
    [-1, 0],
  ];
  //priceDP[x][y][방향] = 최소비용 기록
  const priceDP = Array.from({ length: N }, () =>
    Array.from({ length: N }, () => Array(4).fill(10000000)),
  );

  const isIn = (x, y) => {
    if (x < 0 || x >= N) {
      return false;
    }
    if (y < 0 || y >= N) {
      return false;
    }
    return true;
  };

  const bfs = () => {
    const queue = [];
    let idx = 0;

    //[x,y,방향];
    queue.push([0, 0, 0]);

    while (queue.length - idx !== 0) {
      const [x, y] = queue[idx++];
      let dir = queue[idx - 1][2];

      if (x === N - 1 && y === N - 1) {
        continue;
      }

      for (let index = 0; index < 4; index += 1) {
        const nextX = x + direction[index][0];
        const nextY = y + direction[index][1];

        if (!isIn(nextX, nextY)) {
          continue;
        }

        if (board[nextX][nextY] === 1) {
          continue;
        }

        let nextPrice = priceDP[x][y][dir];

        if (x === 0 && y === 0) {
          nextPrice = 0;
          priceDP[x][y][dir] = 0;
          dir = index;
        }

        if (dir !== index) {
          nextPrice += CORNER_PRICE + LINE_PRICE;
        } else {
          nextPrice += LINE_PRICE;
        }

        if (nextPrice > priceDP[nextX][nextY][index]) {
          continue;
        }

        priceDP[nextX][nextY][index] = nextPrice;
        queue.push([nextX, nextY, index]);
      }
    }
  };

  bfs();
  return Math.min(...priceDP[N - 1][N - 1]);
}
