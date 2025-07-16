/**
 * @param {number[]} arr
 * @return {number}
 */
var findLucky = function(arr) {

    var freq = {};

    for (var i = 0; i < arr.length; i++) {
        var num = arr[i];

        if (freq[num] !== undefined) {
            freq[num] += 1;
        } else {
            freq[num] = 1;
        }
    }

    var result = -1;

    for (var key in freq) {
        var keyAsNumber = parseInt(key);
        var count = freq[key];

        if (keyAsNumber === count) {
            if (keyAsNumber > result) {
                result = keyAsNumber;
            }
        }
    }

    return result;
};
