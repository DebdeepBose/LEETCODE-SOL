class Solution {
public:
    long long minEnd(int n, int x) {
        long long arrlst = x;
        while (--n) {
            arrlst = (arrlst + 1) | x;
        }
        return arrlst;
    }
};