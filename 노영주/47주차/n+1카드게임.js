function solution(coin, cards) {
  let round = 1;
  const N = cards.length;
  const haveCards = Array(N + 1).fill(false);
  const needCoinCards = Array(N + 1).fill(false);
  let idx = N / 3;

  for (let i = 0; i < idx; i++) {
    haveCards[cards[i]] = true;
  }

  const isNotNeedCoin = haveCards => {
    for (let i = 1; i <= N / 2; i++) {
      if (haveCards[i] && haveCards[N + 1 - i]) {
        haveCards[i] = false;
        haveCards[N + 1 - i] = false;
        return true;
      }
    }
    return false;
  };

  const isNeedOneCoin = (haveCards, needCoinCards) => {
    for (let i = 1; i <= N / 2; i++) {
      if (haveCards[i] && needCoinCards[N + 1 - i]) {
        haveCards[i] = false;
        needCoinCards[N + 1 - i] = false;
        return true;
      }
      if (haveCards[N + 1 - i] && needCoinCards[i]) {
        haveCards[N + 1 - i] = false;
        needCoinCards[i] = false;
        return true;
      }
    }
    return false;
  };

  const isNeedTwoCoin = (needCoinCards) => {
    for (let i = 1; i <= N / 2; i++) {
      if (needCoinCards[i] && needCoinCards[N + 1 - i]) {
        needCoinCards[i] = false;
        needCoinCards[N + 1 - i] = false;
        return true;
      }
    }
    return false;
  };

  while (idx < N) {
    let isSubmit = false;

    needCoinCards[cards[idx++]] = true;
    needCoinCards[cards[idx++]] = true;

    if (isNotNeedCoin(haveCards)) {
      isSubmit = true;
    }
    if (!isSubmit && isNeedOneCoin(haveCards, needCoinCards)) {
      coin -= 1;
      isSubmit = true;
    }
    if (!isSubmit && isNeedTwoCoin(needCoinCards)) {
      coin -= 2;
      isSubmit = true;
    }

    if (coin < 0) {
      break;
    }

    if (!isSubmit) {
      break;
    }

    round++;
  }

  return round;
}
