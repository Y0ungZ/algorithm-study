function solution(edges) {
  const edgesInfo = {};

  edges.forEach(edge => {
    const [a, b] = edge;
    if (!edgesInfo[a]) {
      edgesInfo[a] = { sent: 0, received: 0 };
    }
    if (!edgesInfo[b]) {
      edgesInfo[b] = { sent: 0, received: 0 };
    }

    edgesInfo[a].sent++;
    edgesInfo[b].received++;
  });

  let startVertex = 0;
  let totalGraphCount = 0;
  let stickGraphCount = 0;
  let figure8GraphCount = 0;

  for (const edge in edgesInfo) {
    const info = edgesInfo[edge];
    if (info.sent >= 2 && info.received === 0) {
      startVertex = +edge;
      totalGraphCount = info.sent;
    }

    if (info.sent === 0) {
      stickGraphCount++;
    }

    if (info.sent >= 2 && info.received >= 2) {
      figure8GraphCount++;
    }
  }

  const donutGraphCount =
    totalGraphCount - (stickGraphCount + figure8GraphCount);

  return [startVertex, donutGraphCount, stickGraphCount, figure8GraphCount];
}
