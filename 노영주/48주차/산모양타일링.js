function solution(n, tops) {
  const MOD_NUMBER = 10007;
  const tiltedLeftRhombusDP = Array(n + 1).fill(0);
  const exceptTiltedLeftRhombusDP = Array(n + 1).fill(0);

  tiltedLeftRhombusDP[0] = 0;
  exceptTiltedLeftRhombusDP[0] = 1;

  for (let upperSide = 1; upperSide <= n; upperSide++) {
    tiltedLeftRhombusDP[upperSide] =
      (tiltedLeftRhombusDP[upperSide - 1] +
        exceptTiltedLeftRhombusDP[upperSide - 1]) %
      MOD_NUMBER;

    if (tops[upperSide - 1]) {
      exceptTiltedLeftRhombusDP[upperSide] =
        (tiltedLeftRhombusDP[upperSide - 1] * 2 +
          exceptTiltedLeftRhombusDP[upperSide - 1] * 3) %
        MOD_NUMBER;
    } else {
      exceptTiltedLeftRhombusDP[upperSide] =
        (tiltedLeftRhombusDP[upperSide - 1] +
          exceptTiltedLeftRhombusDP[upperSide - 1] * 2) %
        MOD_NUMBER;
    }
  }

  return (tiltedLeftRhombusDP[n] + exceptTiltedLeftRhombusDP[n]) % MOD_NUMBER;
}
