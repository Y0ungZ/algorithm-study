function solution(friends, gifts) {
  let answer = 0;
  const giftHistoryMap = new Map();
  const giftFactor = {};

  const getFromToHistory = (from, to) => {
    return `${from} ${to}`;
  };

  const isAGreaterThanB = (A, B, factor) => {
    const pointA = factor[A].sent - factor[A].received;
    const pointB = factor[B].sent - factor[B].received;

    if (pointA > pointB) {
      return true;
    }

    return false;
  };

  friends.forEach(friend => (giftFactor[friend] = { sent: 0, received: 0 }));

  gifts.forEach(history => {
    const [from, to] = history.split(' ');
    if (giftHistoryMap.has(history)) {
      giftHistoryMap.set(history, giftHistoryMap.get(history) + 1);
    } else {
      giftHistoryMap.set(history, 1);
    }

    giftFactor[from].sent++;
    giftFactor[to].received++;
  });

  for (let i = 0; i < friends.length; i++) {
    const friend = friends[i];
    let nextMonthGiftCount = 0;

    for (let j = 0; j < friends.length; j++) {
      if (i === j) {
        continue;
      }
      const compareFriend = friends[j];
      const sentCount = giftHistoryMap.get(
        getFromToHistory(friend, compareFriend),
      );
      const receivedCount = giftHistoryMap.get(
        getFromToHistory(compareFriend, friend),
      );

      if (!sentCount && !receivedCount) {
        if (isAGreaterThanB(friend, compareFriend, giftFactor)) {
          nextMonthGiftCount++;
        }
        continue;
      }

      if (sentCount === receivedCount) {
        if (isAGreaterThanB(friend, compareFriend, giftFactor)) {
          nextMonthGiftCount++;
        }
        continue;
      }

      if (sentCount) {
        if (!receivedCount || (receivedCount && sentCount > receivedCount)) {
          nextMonthGiftCount++;
        }
      }
    }
    answer = Math.max(answer, nextMonthGiftCount);
  }

  return answer;
}
