class Solution {
public:
    bool checkPerfectNumber(int n) {
        if (n == 1) {
            return false;
        }
        int s = 0;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                s += i;
                if (i != n / i) {
                    s += n / i;
                }
            }
        }
        s++;
        return s == n;
    }
};