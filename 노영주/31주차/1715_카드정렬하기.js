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

    while (this.findParent(index) && this.findParent(index) > this.items[index]) {
      this.swap(this.findParentIdx(index), index);
      index = this.findParentIdx(index);
    }
  }

  bubbleDown() {
    let index = 0;
    while (
      (this.findLeftChild(index) && this.findLeftChild(index) < this.items[index]) ||
      (this.findRightChild(index) && this.findRightChild(index) < this.items[index])
    ) {
      let smallerIndex = this.findLeftChildIdx(index);

      if (this.findRightChild(index) && this.findRightChild(index) < this.items[smallerIndex]) {
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
  const N = +input[0];
  const minHeap = new MinHeap();

  for (let i = 1; i <= N; i++) {
    minHeap.add(+input[i]);
  }

  let answer = 0;
  for (let n = 0; n < N - 1; n++) {
    const prev = minHeap.poll();
    const curr = minHeap.poll();

    answer += prev + curr;
    minHeap.add(prev + curr);
  }

  console.log(answer);
})();
