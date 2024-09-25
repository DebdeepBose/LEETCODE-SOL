class Solution {
public:
    int divide(int div, int dis) {
        long long low = 1;
        long long high = abs(div);
        long long ans = 0;
        if (div == INT_MIN && dis == -1) {
            return INT_MAX;
        }
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (abs(mid * dis) == abs(div)) {
                ans = mid;
                break;
            } else if (abs(mid * dis) < abs(div)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if ((dis > 0 && div > 0) || (dis < 0 && div < 0)) {
            return int(ans);
        } else {
            return int(-ans);
        }
    }
};