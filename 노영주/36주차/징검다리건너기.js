function solution(stones, k) {
  const N = stones.length;
  const MIN_NUM = 1,
    MAX_NUM = 200000000;
  let answer = 0;

  const isOK = num => {
    let sum = 0;
    for (let n = 0; n < N; n++) {
      if (stones[n] < num) {
        sum += 1;
        if (sum === k) {
          return false;
        }
      } else {
        sum = 0;
      }
    }
    return true;
  };

  const binarySearch = () => {
    let left = MIN_NUM,
      right = MAX_NUM;
    while (left <= right) {
      const middle = Math.floor((left + right) / 2);
      const flag = isOK(middle);

      if (flag) {
        answer = middle;
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }
  };

  binarySearch();

  return answer;
}
