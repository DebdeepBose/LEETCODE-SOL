class Solution {
public:
    bool isPalindrome(int x) {
        if (x == INT_MIN) {
            return false;
        }
        long long n = 0LL;
        int c = x;
        bool pos = true;
        if (x < 0) {
            pos = false;
            x *= -1;
        }
        while (x > 0) {
            n *= 10;
            n += (x % 10);
            x /= 10;
        }
        return n == c;
    }
};