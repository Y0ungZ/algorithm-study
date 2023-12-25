function solution(n, left, right) {
  const answer = [];

  for (let i = left; i <= right; i++) {
    const row = Math.floor(i / n);
    const col = i % n;
    if (row >= col) {
      answer.push(row + 1);
    } else {
      answer.push(row + (col - row) + 1);
    }
  }

  return answer;
}
