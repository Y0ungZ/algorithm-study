function solution(bandage, health, attacks) {
  let answer = health;
  let currentTime = 1;
  const [castingTime, perSecondRecovery, plusRecovery] = bandage;

  attacks.every(attack => {
    const [attackTime, demage] = attack;
    const remainTime = attackTime - currentTime;
    const plusPoint = Math.floor(remainTime / castingTime);

    answer += remainTime * perSecondRecovery;
    answer += plusPoint * plusRecovery;

    if (answer > health) answer = health;

    answer -= demage;

    if (answer <= 0) {
      answer = -1;
      return false;
    }

    currentTime = attackTime + 1;
    return true;
  });

  return answer;
}
