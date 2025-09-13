class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if (a > b) {
            swap(a, b);
        }
        if (b > c) {
            swap(b, c);
        }
        if (a > b) {
            swap(a, b);
        }

        int ld = b - a, rd = c - b;

        if (ld == 1 && rd == 1) {
            return {0, 0};
        }
        if (ld <= 2 || rd <= 2) {
            return {1, ld + rd - 2};
        }
        return {2, ld + rd - 2};
    }
};
