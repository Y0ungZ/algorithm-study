// queue 출처 : https://gyyeom.tistory.com/112
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class Queue {
  constructor() {
    this.front = null;
    this.rear = null;
    this.size = 0;
  }

  isEmpty() {
    return this.size === 0;
  }

  enqueue(data) {
    const newNode = new Node(data);
    if (this.isEmpty()) {
      this.front = newNode;
    } else {
      this.rear.next = newNode;
    }
    this.rear = newNode;
    this.size += 1;
  }

  dequeue() {
    if (this.isEmpty()) return;
    const data = this.front.data;
    this.front = this.front.next;
    this.size--;
    return data;
  }
}

const main = (() => {
  const fs = require('fs');
  const filePath = process.platform === 'linux' ? '/dev/stdin' : 'input.txt';
  const input = fs.readFileSync(filePath).toString().trim().split('\n');
  const [N, M] = input[0].trim().split(' ').map(Number);
  const adjList = {};
  const indegree = Array(N + 1).fill(0);
  const answer = [];

  for (let n = 1; n <= N; n++) {
    adjList[n] = [];
  }

  for (let m = 1; m <= M; m++) {
    const [A, B] = input[m].trim().split(' ').map(Number);
    adjList[A].push(B);
    indegree[B] += 1;
  }

  const topologySort = () => {
    const queue = new Queue();

    for (let n = 1; n <= N; n++) {
      if (indegree[n] === 0) {
        queue.enqueue(n);
      }
    }

    while (!queue.isEmpty()) {
      const curr = queue.dequeue();
      answer.push(curr);
      const currAdjList = adjList[curr];

      for (const next of currAdjList) {
        indegree[next] -= 1;

        if (indegree[next] === 0) {
          queue.enqueue(next);
        }
      }
    }
  };

  topologySort();
  console.log(answer.join(' '));
})();
