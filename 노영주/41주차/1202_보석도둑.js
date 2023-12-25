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

  peek() {
    return this.items[0];
  }

  size() {
    return this.items.length;
  }
}

class MaxHeap extends Heap {
  bubbleUp() {
    let idx = this.items.length - 1;

    while (this.findParent(idx) && this.findParent(idx) < this.items[idx]) {
      this.swap(idx, this.findParentIdx(idx));
      idx = this.findParentIdx(idx);
    }
  }

  bubbleDown() {
    let idx = 0;

    while (
      (this.findLeftChild(idx) && this.findLeftChild(idx) > this.items[idx]) ||
      (this.findRightChild(idx) && this.findRightChild(idx) > this.items[idx])
    ) {
      let biggerIndex = this.findLeftChildIdx(idx);

      if (
        this.findRightChild(idx) &&
        this.findRightChild(idx) > this.items[biggerIndex]
      ) {
        biggerIndex = this.findRightChildIdx(idx);
      }

      this.swap(idx, biggerIndex);
      idx = biggerIndex;
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
  const fs = require('fs');
  const filePath = process.platform === 'linux' ? '/dev/stdin' : 'input.txt';
  const input = fs.readFileSync(filePath).toString().trim().split('\n');
  const [N, K] = input[0].trim().split(' ').map(Number);
  const jewels = [];
  const bags = [];
  let answer = BigInt(0);

  for (let line = 1; line <= N; line++) {
    jewels.push(input[line].split(' ').map(Number));
  }

  for (let line = N + 1; line <= N + K; line++) {
    bags.push(Number(input[line].trim()));
  }

  jewels.sort((a, b) => a[0] - b[0] || b[1] - a[1]);
  bags.sort((a, b) => a - b);

  const maxHeap = new MaxHeap();

  let startJewelIndex = 0;
  bags.forEach(bag => {
    while (
      startJewelIndex < jewels.length &&
      jewels[startJewelIndex][0] <= bag
    ) {
      maxHeap.add(jewels[startJewelIndex++][1]);
    }
    if (maxHeap.size()) {
      answer += BigInt(maxHeap.poll());
    }
  });

  console.log(answer.toString());
})();
