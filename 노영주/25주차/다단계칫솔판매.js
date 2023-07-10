function solution(enroll, referral, seller, amount) {
  const group = {};
  const profit = {};

  enroll.forEach((name) => {
    group[name] = [];
    profit[name] = 0;
  });

  referral.forEach((name, idx) => {
    group[enroll[idx]].push(name);
  });

  const distributionProfit = (name, price) => {
    if (price === 0) {
      return;
    }
    if (name === "-") {
      return;
    }

    const distribution = Math.floor(price * 0.1);
    profit[name] += price - distribution;
    distributionProfit(group[name], distribution);
  };

  seller.forEach((name, idx) => {
    const price = amount[idx] * 100;
    distributionProfit(name, price);
  });

  return Array.from(enroll.map((name) => profit[name]));
}
