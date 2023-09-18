function solution(targets) {
  targets.sort((a, b) => a[0] - b[0] || a[1] - b[1]);

  let answer = 1;
  let currE = targets[0][1];

  for (let i = 1; i < targets.length; i++) {
    const [s, e] = targets[i];

    if (s >= currE) {
      answer++;
      currE = e;
    } else {
      currE = Math.min(currE, e);
    }
  }

  return answer;
}
