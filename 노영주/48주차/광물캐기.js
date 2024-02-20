function solution(picks, minerals) {
  const mineralIdxObject = {
    diamond: 0,
    iron: 1,
    stone: 2,
    0: 'diamond',
    1: 'iron',
    2: 'stone',
  };

  const fatigabilityObject = {
    diamond: {
      diamond: 1,
      iron: 1,
      stone: 1,
    },
    iron: {
      diamond: 5,
      iron: 1,
      stone: 1,
    },
    stone: {
      diamond: 25,
      iron: 5,
      stone: 1,
    },
  };

  const calcFatigability = (pickIdx, weight) => {
    let fatigability = 0;
    const pickType = mineralIdxObject[String(pickIdx)];

    for (let i = 0; i < picks.length; i++) {
      const mineralType = mineralIdxObject[String(i)];
      for (let j = 0; j < weight[i]; j++) {
        fatigability += fatigabilityObject[pickType][mineralType];
      }
    }

    return fatigability;
  };

  const getMineralWeights = () => {
    const MAX_COUNT = picks.reduce((acc, cur) => acc + cur * 5, 0);
    const mineralWeights = [];

    for (let i = 0; i < minerals.length; i += 5) {
      const weight = [0, 0, 0];
      for (let j = 0; j < 5; j++) {
        if (MAX_COUNT <= (i + j)) {
          // 곡괭이 횟수가 부족하다면
          break;
        }
        if (minerals.length <= (i + j)) {
          // 모든 광물을 캤다면
          break;
        }
        weight[mineralIdxObject[minerals[i + j]]] += 1;
      }
      mineralWeights.push(weight);
    }

    return mineralWeights;
  };

  let answer = 0;
  const mineralWeights = getMineralWeights();

  mineralWeights.sort((a, b) => b[0] - a[0] || b[1] - a[1] || b[2] - a[2]);

  for (let i = 0; i < mineralWeights.length; i++) {
    const weight = mineralWeights[i];

    if (picks[mineralIdxObject['diamond']]) {
      answer += calcFatigability(mineralIdxObject['diamond'], weight);
      picks[mineralIdxObject['diamond']] -= 1;
      continue;
    }

    if (picks[mineralIdxObject['iron']]) {
      answer += calcFatigability(mineralIdxObject['iron'], weight);
      picks[mineralIdxObject['iron']] -= 1;
      continue;
    }

    if (picks[mineralIdxObject['stone']]) {
      answer += calcFatigability(mineralIdxObject['stone'], weight);
      picks[mineralIdxObject['stone']] -= 1;
      continue;
    }

    // picks = [0,0,0], 사용 가능한 곡괭이가 없다.
    break;
  }

  return answer;
}
