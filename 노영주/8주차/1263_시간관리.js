const main = (() => {
    const fs = require('fs');
    const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
    const input = fs.readFileSync(filePath).toString().trim().split('\n');
    const N = +input[0];
    const tasks = [];

    for (let n = 1; n <= N; n++){
        tasks.push(input[n].trim().split(' ').map(Number));
    }

    tasks.sort((a, b) => b[1] - a[1] || a[1] - b[1]);
    let time = tasks[0][1] - tasks[0][0];

    for (let n = 1; n < N; n++){
        const [t, s] = tasks[n];

        if (s >= time) {
            time = time - t;
        } else {
            time = s - t;
        }
    }

    if (time < 0) {
        console.log(-1);
    } else {
        console.log(time);
    }
})()