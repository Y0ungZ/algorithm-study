function solution(m, musicinfos) {
  const convertTime = (hh, mm) => {
    return hh * 60 + mm;
  };

  const convertSheet = sheet => {
    Object.keys(replaceObj).forEach(key => {
      sheet = sheet.replaceAll(key, replaceObj[key]);
    });
    return sheet;
  };

  let answer = '';
  let maxTime = 0;
  const EMPTY_TXT = '(None)';
  const replaceObj = { 'A#': 'H', 'C#': 'I', 'D#': 'J', 'F#': 'K', 'G#': 'L' };

  m = convertSheet(m);

  musicinfos.forEach(music => {
    const [start, end, name, originSheet] = music.split(',');
    const [startH, startM] = start.split(':').map(Number);
    const [endH, endM] = end.split(':').map(Number);
    const time = convertTime(endH, endM) - convertTime(startH, startM);
    const replaceSheet = convertSheet(originSheet);
    let matchSheet = replaceSheet.repeat(
      Math.round(time / replaceSheet.length),
    );
    matchSheet += replaceSheet.substring(0, (time % replaceSheet.length) + 1);
    matchSheet = matchSheet.slice(0, time);

    if (matchSheet.includes(m) && maxTime < time) {
      maxTime = time;
      answer = name;
    }
  });

  return answer === '' ? EMPTY_TXT : answer;
}
