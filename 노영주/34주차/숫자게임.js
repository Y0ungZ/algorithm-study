const solution = (A, B) => {
  let answer = 0;

  A.sort((a, b) => b - a);
  B.sort((a, b) => a - b);

  let idx = B.length - 1;

  A.forEach((member) => {
    if (member < B[idx]) {
      answer++;
      idx--;
      B.pop();
    }
  });

  return answer;
};
