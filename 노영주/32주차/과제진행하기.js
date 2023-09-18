function solution(plans) {
  const answer = [];
  const timeLine = [];

  const conversionToMin = ([h, m]) => {
    return +h * 60 + +m;
  };

  for (let i = 0; i < plans.length; i++) {
    plans[i][1] = conversionToMin(plans[i][1].split(":"));
    plans[i][2] = +plans[i][2];
  }

  plans.sort((a, b) => a[1] - b[1]);

  for (let i = 0; i < plans.length; i++) {
    const [name, start, playtime] = plans[i];

    if (i === plans.length - 1) {
      timeLine.push([name, 0]);
      continue;
    }

    if (start + playtime > plans[i + 1][1]) {
      timeLine.push([name, start + playtime - plans[i + 1][1]]);
    } else {
      answer.push(name);
      let remainMin = plans[i + 1][1] - (start + playtime);
      while (remainMin > 0 && timeLine.length !== 0) {
        const [lastName, lastMin] = timeLine.pop();
        if (remainMin >= lastMin) {
          answer.push(lastName);
        } else {
          timeLine.push([lastName, lastMin - remainMin]);
        }
        remainMin -= lastMin;
      }
    }
  }

  for (let i = timeLine.length - 1; i >= 0; i--) {
    answer.push(timeLine[i][0]);
  }

  return answer;
}
