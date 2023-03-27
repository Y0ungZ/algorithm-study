class Queue {
  constructor() {
    this.items = [];
    this.front = 0;
    this.rear = 0;
  }

  size() {
    return this.rear - this.front;
  }

  enqueue(value) {
    this.items[this.rear] = value;
    this.rear++;
  }

  dequeue() {
    if (this.size <= 0) {
      return;
    }

    const value = this.items[this.front];
    delete this.items[this.front];
    this.front++;
    return value;
  }

  peek() {
    return this.items[this.rear - 1];
  }
}

const main = (() => {
  const fs = require("fs");
  const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
  const input = fs.readFileSync(filePath).toString().trim().split("\n");
  const [N, W, L] = input[0].trim().split(" ").map(Number);
  const trucks = input[1].trim().split(" ").map(Number);
  const queue = new Queue();
  let seconds = 1;
  let load = 0;
  let idx = 0;

  while (idx < trucks.length) {
    if (load + trucks[idx] <= L) {
      queue.enqueue([trucks[idx], seconds + W]);
      load += trucks[idx];
      seconds++;
      idx++;
    } else {
      const [currLoad, endTime] = queue.dequeue();
      seconds = Math.max(seconds, endTime);
      load -= currLoad;
    }
  }

  const [_, endTime] = queue.peek();
  console.log(endTime);
})();
