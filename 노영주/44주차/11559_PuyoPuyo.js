const main = (() => {
  const fs = require('fs');
  const filePath = process.platform === 'linux' ? '/dev/stdin' : 'input.txt';
  const input = fs.readFileSync(filePath).toString().trim().split('\n');
  const ROW = 12,
    COL = 6;
  const direction = {
    LEFT: [0, -1],
    RIGHT: [0, 1],
    DOWN: [1, 0],
    UP: [-1, 0],
  };
  const EMPTY_SPACE = '.';
  let chainCount = 0;
  const map = [];

  const dfs = (check, visited, r, c, depth) => {
    visited[r][c] = true;

    if (depth >= 4) {
      for (let r = 0; r < ROW; r++) {
        for (let c = 0; c < COL; c++) {
          if (visited[r][c]) {
            check[r][c] = true;
          }
        }
      }
    }

    for (let key in direction) {
      const [addR, addC] = direction[key];
      const nextR = r + addR;
      const nextC = c + addC;

      if (nextR < 0 || nextR >= ROW || nextC < 0 || nextC >= COL) {
        continue;
      }

      if (visited[nextR][nextC]) {
        continue;
      }

      if (map[r][c] !== map[nextR][nextC]) {
        continue;
      }

      depth += 1;
      dfs(check, visited, nextR, nextC, depth);
    }
  };

  const markGroup = map => {
    const check = Array.from({ length: ROW }, () => Array(COL).fill(false));

    for (let r = 0; r < ROW; r++) {
      for (let c = 0; c < COL; c++) {
        if (map[r][c] !== '.' && !check[r][c]) {
          const visited = Array.from({ length: ROW }, () =>
            Array(COL).fill(false),
          );
          dfs(check, visited, r, c, 1);
        }
      }
    }

    return check;
  };

  const explodedPuyo = checkMap => {
    let isExploded = false;
    for (let r = 0; r < ROW; r++) {
      for (let c = 0; c < COL; c++) {
        if (checkMap[r][c]) {
          map[r][c] = EMPTY_SPACE;
          isExploded = true;
        }
      }
    }
    return isExploded;
  };

  const downPuyo = () => {
    for (let col = 0; col < COL; col++) {
      for (let row = ROW - 1; row >= 0; row--) {
        if (map[row][col] !== '.') {
          continue;
        }
        for (let upRow = row - 1; upRow >= 0; upRow--) {
          if (map[upRow][col] !== '.') {
            map[row][col] = map[upRow][col];
            map[upRow][col] = '.';
            break;
          }
        }
      }
    }
  };

  const play = () => {
    const checkExploded = markGroup(map);
    const isExploded = explodedPuyo(checkExploded);
    
    downPuyo();

    if (isExploded) {
      chainCount++;
      play();
    }
  };

  for (let r = 0; r < ROW; r++) {
    const line = input[r].trim().split('');
    map.push(line);
  }

  play();
  console.log(chainCount);
})();
