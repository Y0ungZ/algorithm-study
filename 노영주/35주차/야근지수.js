class MaxHeap {
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

  bubbleUp() {
    let index = this.items.length - 1;

    while (
      this.items[this.findParentIdx(index)] &&
      this.items[index] > this.items[this.findParentIdx(index)]
    ) {
      this.swap(index, this.findParentIdx(index));
      index = this.findParentIdx(index);
    }
  }

  bubbleDown() {
    let index = 0;

    while (
      (this.items[this.findLeftChildIdx(index)] &&
        this.items[this.findLeftChildIdx(index)] > this.items[index]) ||
      (this.items[this.findRightChildIdx(index)] &&
        this.items[this.findRightChildIdx(index)] > this.items[index])
    ) {
      let biggerIndex = this.findLeftChildIdx(index);

      if (this.items[this.findRightChildIdx(index)] > this.items[biggerIndex]) {
        biggerIndex = this.findRightChildIdx(index);
      }

      this.swap(index, biggerIndex);
      index = biggerIndex;
    }
  }

  add(value) {
    this.items.push(value);
    this.bubbleUp();
  }

  poll() {
    const value = this.items[0];
    this.items[0] = this.items.pop();
    this.bubbleDown();

    return value;
  }
}

function solution(n, works) {
  const maxHeap = new MaxHeap();

  works.forEach((work) => {
    maxHeap.add(work);
  });

  while (n !== 0) {
    const maxValue = maxHeap.poll();
    if (maxValue === 0) break;
    maxHeap.add(maxValue - 1);
    n--;
  }

  return maxHeap.items.reduce((acc, cur) => acc + Math.pow(cur, 2), 0);
}
