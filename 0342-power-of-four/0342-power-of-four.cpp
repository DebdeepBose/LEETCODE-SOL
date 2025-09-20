class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1) {
            return true;
        }
        if (n % 2 == 1 || n % 3 == 0 || n == 0) {
            return false;
        }
        return isPowerOfFour(n / 4);
    }
};