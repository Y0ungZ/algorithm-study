function solution(n, t, m, timetable) {
  const convertMinute = str => {
    const [hh, mm] = str.split(':').map(Number);
    return hh * 60 + mm;
  };

  const convertTimeFormatString = minute => {
    let hh = String(Math.floor(minute / 60));
    minute -= hh * 60;
    let mm = String(minute);
    if (hh.length === 1) {
      hh = '0' + hh;
    }
    if (mm.length === 1) {
      mm = '0' + mm;
    }
    return `${hh}:${mm}`;
  };

  let answer = 0;
  const convertTimeTable = timetable
    .map(el => convertMinute(el))
    .sort((a, b) => a - b);
  const START_TIME = convertMinute('09:00');
  let idx = 0;

  for (let i = 0; i < n; i++) {
    const currentTime = START_TIME + t * i;
    if (i === n - 1) {
      if (idx + m > convertTimeTable.length) {
        answer = currentTime;
        break;
      }
    }
    for (let j = 0; j < m; j++) {
      if (convertTimeTable[idx] > currentTime) {
        answer = currentTime;
        break;
      }
      if (idx + j <= convertTimeTable.length) {
        answer = convertTimeTable[idx] - 1;
        idx++;
      }
    }
  }

  return convertTimeFormatString(answer);
}
