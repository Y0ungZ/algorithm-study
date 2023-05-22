const makeStrArr = (str) => {
  const array = [];

  for (let i = 0; i < str.length - 1; i++) {
    const lowerStr = str.slice(i, i + 2).toLowerCase();
    const REGEX = /[a-z]{2}/;

    REGEX.test(lowerStr) && array.push(lowerStr);
  }

  return array;
};

const solution = (str1, str2) => {
  const MAL_VALUE = 65536;
  const arr1 = makeStrArr(str1);
  const arr2 = makeStrArr(str2);

  if (!arr1.length && !arr2.length) {
    return MAL_VALUE;
  }

  const intersection = [];
  const visitArr1 = Array(arr1.length).fill(false);
  const visitArr2 = Array(arr2.length).fill(false);

  arr1.forEach((element1, idx1) => {
    arr2.forEach((element2, idx2) => {
      if (element1 === element2 && !visitArr1[idx1] && !visitArr2[idx2]) {
        intersection.push(element1);
        visitArr1[idx1] = true;
        visitArr2[idx2] = true;
      }
    });
  });

  return Math.floor(
    (intersection.length / (arr1.length + arr2.length - intersection.length)) * MAL_VALUE
  );
};
