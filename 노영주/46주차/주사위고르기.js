function solution(dice) {
  const DICE_LENGTH = dice[0].length;
  let answer = [];
  let maxWinCount = 0;
  const diceIndexes = Array(dice.length)
    .fill(0)
    .map((_, idx) => idx);

  const getCombinations = (array, selectedNumber) => {
    const cases = [];
    if (selectedNumber === 1) {
      return array.map(el => [el]);
    }

    array.forEach((fixed, index, origin) => {
      const rest = array.slice(index + 1);
      const combinations = getCombinations(rest, selectedNumber - 1);
      const attached = combinations.map(el => [fixed, ...el]);
      cases.push(...attached);
    });

    return cases;
  };

  const getSumCases = (idx, sum, dices) => {
    const sums = [];
    if (idx === dices.length) {
      return [sum];
    }

    for (let i = 0; i < DICE_LENGTH; i++) {
      const currDice = dice[dices[idx]];
      const currSum = getSumCases(idx + 1, sum + currDice[i], dices);
      sums.push(...currSum);
    }
    return sums;
  };

  const getWinCount = (target, caseB) => {
    let left = 0,
      right = caseB.length - 1;

    while (left <= right) {
      const middle = Math.floor((left + right) / 2);

      if (caseB[middle] >= target) {
        right = middle - 1;
      } else {
        left = middle + 1;
      }
    }

    return left;
  };

  const casesA = getCombinations(diceIndexes, dice.length / 2);

  casesA.forEach(caseA => {
    const caseB = diceIndexes.filter(el => !caseA.includes(el));
    const sumsA = getSumCases(0, 0, caseA).sort((a, b) => a - b);
    const sumsB = getSumCases(0, 0, caseB).sort((a, b) => a - b);

    let currWinCount = 0;

    sumsA.forEach(A => {
      currWinCount += getWinCount(A, sumsB);
    });

    if (currWinCount > maxWinCount) {
      maxWinCount = currWinCount;
      answer = caseA.map(el => el + 1);
    }
  });

  return answer;
}
