function solution(n, weak, dist) {
  const expandWeak = Array(weak.length * 2 - 1).fill(0);
  dist.sort((a, b) => a - b);

  for (let len = 0; len < weak.length * 2 - 1; len++) {
    expandWeak[len] =
      len < weak.length ? weak[len] : weak[len - weak.length] + n;
  }

  const getPerm = (arr, selectedNumber) => {
    const result = [];
    if (selectedNumber === 1) {
      return arr.map(el => [el]);
    }
    arr.forEach((fixed, idx, origin) => {
      const rest = [...origin.slice(0, idx), ...origin.slice(idx + 1)];
      const perms = getPerm(rest, selectedNumber - 1);
      const attached = perms.map(perm => [fixed, ...perm]);
      result.push(...attached);
    });

    return result;
  };

  for (let count = 1; count <= dist.length; count++) {
    const perms = getPerm(dist, count);

    for (let idx = 0; idx < perms.length; idx++) {
      for (let i = 0; i < weak.length; i++) {
        let point = expandWeak.slice(i, weak.length + i);
        for (let j = 0; j < perms[idx].length; j++) {
          point = point.filter(el => el > point[0] + perms[idx][j]);
          if (!point.length) return count;
        }
      }
    }
  }
  return -1;
}
