function solution(cap, n, deliveries, pickups) {
  let answer = 0;
  let nextDeliveryCap = 0;
  let nextPickupCap = 0;

  for (let i = n - 1; i >= 0; i--) {
    let count = 0;

    deliveries[i] += nextDeliveryCap;
    pickups[i] += nextPickupCap;

    while (deliveries[i] > 0 || pickups[i] > 0) {
      deliveries[i] -= cap;
      pickups[i] -= cap;
      count++;
    }

    nextDeliveryCap = deliveries[i];
    nextPickupCap = pickups[i];

    if (count !== 0) {
      answer += 2 * (i + 1) * count;
    }
  }

  return answer;
}
