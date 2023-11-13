function solution(n, stations, w) {
  const COVERAGE_RANGE = 2 * w + 1;
  let answer = 0;
  let leftIdx = 1;

  stations.forEach(station => {
    const [left, right] = [station - w, station + w];
    if (left > leftIdx) {
      answer += Math.ceil((left - leftIdx) / COVERAGE_RANGE);
    }
    leftIdx = right + 1;
  });

  //최종 기지국 '설치 완료' 영역을 알아내야 한다.
  leftIdx--;

  if (leftIdx < n) {
    answer += Math.ceil((n - leftIdx) / COVERAGE_RANGE);
  }

  return answer;
}
