class Solution {
public:
    int divide(int dividend, int divisor) {
        long long low = 1;
        long long high = abs(dividend);
        long long ans = 0;
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (abs(mid * divisor) == abs(dividend)) {
                ans = mid;
                break;
            } else if (abs(mid * divisor) < abs(dividend)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
            return (int)ans;
        } else {
            return (int)-ans;
        }
    }
};