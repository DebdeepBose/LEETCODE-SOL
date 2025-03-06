/**
 * @param {number[][]} grid
 * @return {number[]}
 */
var findMissingAndRepeatedValues = function(grid) {
    let v = grid.flat(); 
    let n = v.length;
    let freq = new Map();
    let duplicate, missing;

    for (let num of v) {
        freq.set(num, (freq.get(num) || 0) + 1);
    }

    for (let i = 1; i <= n; i++) {
        if (freq.get(i) === 2) {
            duplicate = i;
        }
        if (!freq.has(i)) {
            missing = i;
        }
    }

    return [duplicate, missing];
};
