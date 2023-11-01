function solution(n, costs) {
  const parent = Array(n)
    .fill(0)
    .map((_, idx) => idx);
  let answer = 0;

  const find = (x) => {
    if (parent[x] === x) {
      return x;
    }
    const currentParent = find(parent[x], parent);
    parent[x] = currentParent;

    return currentParent;
  };

  const union = (A, B) => {
    const rootA = find(A, parent);
    const rootB = find(B, parent);

    if (rootA === rootB) {
      return false;
    }

    rootA < rootB ? (parent[rootB] = rootA) : (parent[rootA] = rootB);
    return true;
  };

  costs.sort((a, b) => a[2] - b[2]);

  costs.forEach((curr) => {
    const [a, b, cost] = curr;
    if (union(a, b)) {
      answer += cost;
    }
  });

  return answer;
}
