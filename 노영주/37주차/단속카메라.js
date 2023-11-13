function solution(routes) {
  routes.sort((a, b) => a[0] - b[0] || a[1] - b[1]);

  let answer = 1;
  let coordinate = routes[0][1];

  for (let index = 1; index < routes.length; index += 1) {
    const [entry, exit] = routes[index];
    if (entry > coordinate) {
      answer += 1;
      coordinate = exit;
    } else {
      coordinate = Math.min(coordinate, exit);
    }
  }

  return answer;
}
