class Solution {
public:
    long long minEnd(int n, int x) {
        long long arrlst = x;
        while (n > 1) {
            arrlst = (arrlst + 1) | x;
            n--;
        }
        return arrlst;
    }
};