class Solution {
public:
        long long minEnd(int n, int x) {
        n--;
        long long arrlst = x, b;
        for (b = 1; n > 0; b <<= 1) {
            if ((b & x) == 0) {
                arrlst |= (n & 1) * b;
                n >>= 1;
            }
        }
        return arrlst;
    }
};