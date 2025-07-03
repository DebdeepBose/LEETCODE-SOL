class Solution {
public:
    char find(int k, char start, int len) {

        if (len == 1) {
            return start;
        }

        int half = len / 2;
        if (k <= half) {
            // Left part: same character sequence
            return find(k, start, half);
        } else {
            // Right part: incremented characters
            return find(k - half, start + 1, half);
        }
    }

    char kthCharacter(int k) {
        int len = 1;
        while (len < k) {
            len *= 2;
        } // Find smallest power of 2 >= k
        return find(k, 'a', len);
    }
};
