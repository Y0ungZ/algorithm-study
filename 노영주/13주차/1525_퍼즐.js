const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const GOAL = "123456780";
  let puzzle = "";
  const visited = new Map();

  input.forEach((row) => {
    puzzle += row.replace(/\s/g, "");
  });

  const bfs = () => {
    const queue = [];
    queue.push(puzzle);
    visited.set(puzzle, 0);

    const visitedLogic = (currPuzzle, nextPuzzle) => {
      if (!visited.has(nextPuzzle)) {
        queue.push(nextPuzzle);
        visited.set(nextPuzzle, visited.get(currPuzzle) + 1);
      }
    };

    let idx = 0;
    while (queue.length - idx !== 0) {
      const currPuzzle = queue[idx++];

      if (currPuzzle === GOAL) {
        answer = visited.get(currPuzzle);
        break;
      }

      const zeroIdx = currPuzzle.indexOf("0");

      if (zeroIdx % 3 === 0 || zeroIdx % 3 === 1) {
        const nextPuzzle = currPuzzle.split("");
        nextPuzzle[zeroIdx] = currPuzzle[zeroIdx + 1];
        nextPuzzle[zeroIdx + 1] = "0";

        visitedLogic(currPuzzle, nextPuzzle.join(""));
      }

      if (zeroIdx < 6) {
        const nextPuzzle = currPuzzle.split("");
        nextPuzzle[zeroIdx] = currPuzzle[zeroIdx + 3];
        nextPuzzle[zeroIdx + 3] = "0";

        visitedLogic(currPuzzle, nextPuzzle.join(""));
      }

      if (zeroIdx % 3 === 2 || zeroIdx % 3 === 1) {
        const nextPuzzle = currPuzzle.split("");
        nextPuzzle[zeroIdx] = currPuzzle[zeroIdx - 1];
        nextPuzzle[zeroIdx - 1] = "0";

        visitedLogic(currPuzzle, nextPuzzle.join(""));
      }

      if (zeroIdx > 2) {
        const nextPuzzle = currPuzzle.split("");
        nextPuzzle[zeroIdx] = currPuzzle[zeroIdx - 3];
        nextPuzzle[zeroIdx - 3] = "0";

        visitedLogic(currPuzzle, nextPuzzle.join(""));
      }
    }
  };

  let answer = -1;
  bfs();
  console.log(answer);
})();
