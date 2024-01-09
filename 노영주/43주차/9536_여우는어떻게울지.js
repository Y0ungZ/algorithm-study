const main = (() => {
  const fs = require('fs');
  const filePath = process.platform === 'linux' ? '/dev/stdin' : 'input.txt';
  const input = fs
    .readFileSync(filePath)
    .toString()
    .trim()
    .split('\n')
    .map(el => el.trim());
  const FINISH_QUESTION = 'what does the fox say?';
  const SPLIT_STRING = ' goes ';
  const answer = [];
  const indexs = [0];

  for (let i = 0; i < input.length; i++) {
    if (input[i] === FINISH_QUESTION) {
      indexs.push(i);
    }
  }

  for (let t = 1; t < indexs.length; t++) {
    const set = new Set();
    let findString;
    const foxSound = [];
    for (let i = indexs[t - 1]; i < indexs[t]; i++) {
      if (i === indexs[t - 1] + 1) {
        findString = input[i].split(' ');
        continue;
      }

      const [animal, sound] = input[i].split(SPLIT_STRING);
      set.add(sound);
    }

    for (let i = 0; i < findString.length; i++) {
      if (!set.has(findString[i])) {
        foxSound.push(findString[i]);
      }
    }

    answer.push(foxSound.join(' '));
  }
  console.log(answer.join('\n'));
})();
