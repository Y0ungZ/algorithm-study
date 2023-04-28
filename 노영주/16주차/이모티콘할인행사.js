function solution(users, emoticons) {
  const discountRates = [10, 20, 30, 40];
  let maxUsers = 0;
  let maxPrices = 0;

  const perm = (idx, select) => {
    if (idx > emoticons.length) {
      return;
    }
    if (idx === emoticons.length) {
      let joinCount = 0;
      let priceSum = 0;

      users.forEach((user) => {
        const [wantRate, maxPriceSum] = user;
        let sum = 0;

        for (let s = 0; s < select.length; s++) {
          if (select[s] >= wantRate) {
            sum += emoticons[s] - emoticons[s] * (select[s] / 100);
          }
        }

        if (sum >= maxPriceSum) {
          joinCount++;
        } else {
          priceSum += sum;
        }
      });

      if (maxUsers < joinCount) {
        maxUsers = joinCount;
        maxPrices = priceSum;
      }

      if (maxUsers === joinCount) {
        maxPrices = Math.max(priceSum, maxPrices);
      }

      return;
    }

    for (let i = 0; i < discountRates.length; i++) {
      select[idx] = discountRates[i];
      perm(idx + 1, select);
    }
  };

  perm(0, Array(emoticons.length).fill(0));

  return [maxUsers, maxPrices];
}
