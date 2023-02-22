/**
 * https://www.acmicpc.net/status?problem_id=2023&user_id=&language_id=17&result_id=-1&from_problem=1
 * [2023-02-19 기준] node.js 메모리 제한으로 해결한 사람 없음.
 * - 1<=N<=8 까지 정답 출력되는 것을 확인한 코드.
 */

const main = (() => {
    const fs = require('fs');
    const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
    const N = +fs.readFileSync(filePath).toString().trim();
    const answer = [];

    const isPrime = (number) => {
        if (number <= 1) {
            return false;
        }

        if (number % 2 === 0) {
            return number === 2 ? true : false;
        }

        for (let i = 3; i <= Math.sqrt(number); i += 2){
            if (number % i === 0) {
                return false;
            }
        }
        return true;
    }

    const numbers = [1, 2, 3, 5, 7, 9];
    
    const findWeirdPrime = (array) => {
        if (array.length === N) {
            if (isPrime(+array.join(''))){
                answer.push(array.join(''));
            }
            return;
        }

        for (let i = 0; i < numbers.length; i++){
            const nextPrime = array.join('') + numbers[i];
            if (isPrime(+nextPrime)) { findWeirdPrime([...array, numbers[i]]) };
        }
        
    }

    findWeirdPrime([]);

    console.log(answer.join('\n'));
})()