class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) {
            return false;
        }
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    bool isThree(int n) {

        if (n == 1) {
            return false;
        }

        int sqr = sqrt(n);
        if (sqr * sqr != n) {
            return false;
        }

        return isPrime(sqr);
    }
};