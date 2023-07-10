function solution(n, m, x, y, r, c, k) {
  const IMPOSSIBLE_MSG = "impossible";
  const calcDistancetoRC = (inputR, inputC) => {
    return Math.abs(r - inputR) + Math.abs(c - inputC);
  };

  let answer = "";
  const count = { d: 0, l: 0, r: 0, u: 0 };
  let remainK = k - calcDistancetoRC(x, y);

  if (remainK >= 0 && remainK % 2 === 0) {
    if (x > r) {
      count["u"] += x - r;
    } else {
      count["d"] += r - x;
    }

    if (y > c) {
      count["l"] += y - c;
    } else {
      count["r"] += c - y;
    }

    // answer에는 "d" -> "l" -> "rl"("rr"보다 우선순위 높) -> r" -> "u"순으로 합쳐줘야함.
    // d
    let remainMove = Math.min(Math.floor(remainK / 2), n - (x + count["d"]));
    count["d"] += remainMove;
    count["u"] += remainMove;
    answer += "d".repeat(count["d"]);
    remainK -= 2 * remainMove;

    // l
    remainMove = Math.min(Math.floor(remainK / 2), y - count["l"] - 1);
    count["l"] += remainMove;
    count["r"] += remainMove;
    answer += "l".repeat(count["l"]);
    remainK -= 2 * remainMove;

    //rl
    remainMove = Math.floor(remainK / 2);
    answer += "rl".repeat(remainMove);
    remainK -= 2 * remainMove;

    // r
    answer += "r".repeat(count["r"]);

    // u
    answer += "u".repeat(count["u"]);
  }

  return answer === "" ? IMPOSSIBLE_MSG : answer;
}
