function solution(board) {
  let isOk = true;
  let countO = 0,
    countX = 0;
  let winO = false,
    winX = false;

  for (let r = 0; r < board.length; r++) {
    let rowO = 0,
      colO = 0;
    let rowX = 0,
      colX = 0;
    for (let c = 0; c < board[0].length; c++) {
      if (board[r][c] === "X") {
        countX++;
        rowX++;
      }

      if (board[c][r] === "X") {
        colX++;
      }

      if (board[r][c] === "O") {
        countO++;
        rowO++;
      }

      if (board[c][r] === "O") {
        colO++;
      }
    }

    if (rowO === 3 || colO === 3) {
      winO = true;
    }
    if (rowX === 3 || colX === 3) {
      winX = true;
    }
  }

  let crossOL = 0,
    crossOR = 0;
  let crossXL = 0,
    crossXR = 0;
  for (let c = 0; c < board[0].length; c++) {
    if (board[c][c] === "O") {
      crossOL++;
    }
    if (board[c][c] === "X") {
      crossXL++;
    }
    if (board[c][board.length - c - 1] === "O") {
      crossOR++;
    }
    if (board[c][board.length - c - 1] === "X") {
      crossXR++;
    }
  }

  if (crossOL === 3 || crossOR === 3) {
    winO = true;
  }

  if (crossXL === 3 || crossXR === 3) {
    winX = true;
  }

  if (winO && winX) {
    isOk = false;
  }

  if (countX > countO) {
    isOk = false;
  }

  if (countO > countX) {
    if (countO !== countX + 1) {
      isOk = false;
    }
  }

  if (winO) {
    if (countO === countX) {
      isOk = false;
    }
  }

  if (winX) {
    if (countO !== countX) {
      isOk = false;
    }
  }

  return isOk === true ? 1 : 0;
}
