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
      this.size -= 1;
      return data;
    }
  }
  
  const main = (() => {
    const fs = require('fs');
    const filePath = process.platform === 'linux' ? '/dev/stdin' : 'input.txt';
    const input = fs
      .readFileSync(filePath)
      .toString()
      .trim()
      .split('\n')
      .map(el => el.trim());
    const T = Number(input[0]);
    let line = 1;
    const answer = [];
  
    const topologySort = (indegree, adjList, timeMap) => {
      const resultMap = new Map();
      const queue = new Queue();
  
      for (let n = 1; n < indegree.length; n++) {
        if (indegree[n] === 0) {
          queue.enqueue(n);
        }
        resultMap.set(n, timeMap.get(n));
      }
  
      while (!queue.isEmpty()) {
        const curr = queue.dequeue();
        const currAdjList = adjList[curr];
  
        for (const next of currAdjList) {
          indegree[next] -= 1;
          resultMap.set(
            next,
            Math.max(
              resultMap.get(next),
              timeMap.get(next) + resultMap.get(curr),
            ),
          );
  
          if (indegree[next] === 0) {
            queue.enqueue(next);
          }
        }
      }
      return resultMap;
    };
  
    for (let t = 1; t <= T; t++) {
      const [N, K] = input[line++].split(' ').map(Number);
      const indegree = Array(N + 1).fill(0);
      const adjList = {};
  
      for (let n = 1; n <= N; n++) {
        adjList[n] = [];
      }
  
      const constructionTimeMap = new Map();
      const constructionTimeInfo = input[line++].split(' ').map(Number);
  
      constructionTimeInfo.forEach((time, idx) =>
        constructionTimeMap.set(idx + 1, time),
      );
  
      for (let k = 0; k < K; k++) {
        const [X, Y] = input[line++].split(' ').map(Number);
        adjList[X].push(Y);
        indegree[Y] += 1;
      }
  
      const W = Number(input[line]);
      const resultMap = topologySort(indegree, adjList, constructionTimeMap);
  
      answer.push(resultMap.get(W));
  
      if (t < T) {
        line += 1;
      }
    }
  
    console.log(answer.join('\n'));
  })();