function solution(numbers) {
  const answer = [];
  const SUCCESS_NUM = 1,
    FAIL_NUM = 0;

  const isBinaryTree = str => {
    if (str.length === 1) {
      return true;
    }

    const mid = Math.floor(str.length / 2);
    const left = str.slice(0, mid);
    const right = str.slice(mid + 1);

    if (str[mid] === '0') {
      if (left.includes('1') || right.includes('1')) {
        return false;
      }
      return true;
    }

    return isBinaryTree(left) && isBinaryTree(right);
  };

  numbers.forEach(number => {
    let binaryString = number.toString(2);
    const len = binaryString.length;
    const perfectBinaryTreeCount =
      Math.pow(2, Math.floor(Math.log2(len)) + 1) - 1;

    binaryString = '0'.repeat(perfectBinaryTreeCount - len) + binaryString;

    const result = isBinaryTree(binaryString);
    if (result) {
      answer.push(SUCCESS_NUM);
    }
    if (!result) {
      answer.push(FAIL_NUM);
    }
  });

  return answer;
}
