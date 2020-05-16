const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();
let data = input.split("\n");
let N, M, K;
let map = new Map();
let keys = [];

data.forEach((item, idx) => {
    if (idx === 0) {
        let header = item.split(" ").map((str) => parseInt(str));
        (N = header[0]), (M = header[1]), (K = header[2]);
    } else if (0 < idx && idx <= N) {
        let element = item.split(" ").map((str) => parseInt(str));
        map.set(element[0], element[1]);
    } else {
        let command = item.split(" ").map((str) => parseInt(str));
        if (command[0] === 1) {
            // key value 추가
            map.set(command[1], command[2]);
        } else if (command[0] === 2) {
            // key value 로 변경, 없으면 무시
            let targetKey = command[1],
                targetVal = command[2];
            if (map.has(targetKey)) map.set(targetKey, targetVal);
            else {
                let ii = lower_bound(targetKey);
                if (ii >= map.size) ii = map.size - 1;
                // console.log("2: ", targetKey, ii);
                let dist1 = Infinity;
                if (ii > 0) dist1 = Math.abs(targetKey - keys[ii - 1]);
                let dist2 = Math.abs(targetKey - keys[ii]);
                if (!(dist1 > K && dist2 > K)) {
                    if (dist1 > K) dist1 = Infinity;
                    if (dist2 > K) dist2 = Infinity;
                    if (dist1 !== dist2) {
                        if (dist1 < dist2) {
                            map.set(keys[ii - 1], targetVal);
                        } else {
                            map.set(keys[ii], targetVal);
                        }
                    }
                }
            }
        } else {
            // key 로 검색한 데이터 출력, 없으면 -1 출력, 두 개 이상 존재하면 ?출력, 개행 포함
            // 잘못된 키를 입력하더라도 그 잘못된 키와 제일 근접한 키를 찾아준다. 차이가 K보다 크면 인정 안한다.
            let targetKey = command[1];
            if (map.has(targetKey)) console.log(map.get(targetKey));
            else {
                let ii = lower_bound(targetKey);
                if (ii >= map.size) ii = map.size - 1;
                // console.log("3: ", targetKey, ii);
                let dist1 = Infinity;
                if (ii > 0) dist1 = Math.abs(targetKey - keys[ii - 1]);
                let dist2 = Math.abs(targetKey - keys[ii]);
                if (dist1 > K && dist2 > K) {
                    console.log(-1);
                } else {
                    if (dist1 > K) dist1 = Infinity;
                    if (dist2 > K) dist2 = Infinity;
                    if (dist1 === dist2) console.log("?");
                    else {
                        if (dist1 < dist2) {
                            console.log(map.get(keys[ii - 1]));
                        } else {
                            console.log(map.get(keys[ii]));
                        }
                    }
                }
            }
        }
    }
});

// target보다 큰 원소 중 가장 작은 값의 index, target이 가장 크면 end 반환
function lower_bound(target) {
    keys = Array.from(map.keys());
    let left = 0,
        right = keys.length,
        mid = Math.floor((left + right) / 2);
    while (left < right) {
        mid = Math.floor((left + right) / 2);

        if (keys[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return mid + 1;
}
