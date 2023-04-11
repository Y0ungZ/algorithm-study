class Heap {
  constructor() {
    this.items = [];
  }

  swap(idx1, idx2) {
    [this.items[idx1], this.items[idx2]] = [this.items[idx2], this.items[idx1]];
  }

  findParentIdx(idx) {
    return Math.floor((idx - 1) / 2);
  }

  findLeftChildIdx(idx) {
    return idx * 2 + 1;
  }

  findRightChildIdx(idx) {
    return idx * 2 + 2;
  }

  findParent(idx) {
    return this.items[this.findParentIdx(idx)];
  }

  findLeftChild(idx) {
    return this.items[this.findLeftChildIdx(idx)];
  }

  findRightChild(idx) {
    return this.items[this.findRightChildIdx(idx)];
  }

  size() {
    return this.items.length;
  }
}

class MinHeap extends Heap {
  bubbleUp() {
    let index = this.items.length - 1;

    while (this.findParent(index) && this.findParent(index)[1] > this.items[index][1]) {
      this.swap(this.findParentIdx(index), index);
      index = this.findParentIdx(index);
    }
  }

  bubbleDown() {
    let index = 0;
    while (
      (this.findLeftChild(index) && this.findLeftChild(index)[1] < this.items[index][1]) ||
      (this.findRightChild(index) && this.findRightChild(index)[1] < this.items[index][1])
    ) {
      let smallerIndex = this.findLeftChildIdx(index);

      if (
        this.findRightChild(index) &&
        this.findRightChild(index)[1] < this.items[smallerIndex][1]
      ) {
        smallerIndex = this.findRightChildIdx(index);
      }

      this.swap(index, smallerIndex);
      index = smallerIndex;
    }
  }

  add(value) {
    this.items.push(value);
    this.bubbleUp();
  }

  poll() {
    if (this.items.length === 1) {
      return this.items.pop();
    }
    const value = this.items[0];
    this.items[0] = this.items.pop();
    this.bubbleDown();

    return value;
  }
}

const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const [N, E] = input[0].trim().split(" ").map(Number);
  const adjList = {};

  for (let n = 1; n <= N; n++) {
    adjList[n] = [];
  }

  for (let e = 1; e <= E; e++) {
    const [a, b, c] = input[e].trim().split(" ").map(Number);
    adjList[a].push([b, c]);
    adjList[b].push([a, c]);
  }

  const [v1, v2] = input[E + 1].trim().split(" ").map(Number);

  const dijkstra = (start) => {
    const minHeap = new MinHeap();
    const dist = Array(N + 1).fill(Infinity);
    dist[start] = 0;
    minHeap.add([start, 0]);

    while (minHeap.size()) {
      const [vertex, cost] = minHeap.poll();

      if (!adjList[vertex]) continue;
      if (dist[vertex] < cost) continue;

      for (let i = 0; i < adjList[vertex].length; i++) {
        const [nextVertex, nextCost] = adjList[vertex][i];

        if (dist[nextVertex] > cost + nextCost) {
          dist[nextVertex] = cost + nextCost;
          minHeap.add([nextVertex, dist[nextVertex]]);
        }
      }
    }

    return dist;
  };

  const V1toV2 = dijkstra(1)[v1] + dijkstra(v1)[v2] + dijkstra(v2)[N];
  const V2toV1 = dijkstra(1)[v2] + dijkstra(v2)[v1] + dijkstra(v1)[N];
    const answer = Math.min(V1toV2, V2toV1);

  answer === Infinity ? console.log(-1) : console.log(answer);
})();
