function solution(n, s) {
  const quot = Math.floor(s / n);

  if (quot === 0) {
    return [-1];
  }

  const ANSWER_LEN = n - Math.floor(s % n);
  const answer = Array(ANSWER_LEN).fill(quot);

  for (let len = ANSWER_LEN; len < n; len++) {
    answer.push(quot + 1);
  }
  return answer;
}
