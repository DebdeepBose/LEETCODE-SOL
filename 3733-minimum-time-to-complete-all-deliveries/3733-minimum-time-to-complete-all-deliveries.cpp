class Solution {
private:
    bool check(long long mid, vector<int>& d, vector<int>& r) {
        long long del1 = mid - mid / r[0];
        long long del2 = mid - mid / r[1];
        long long del3 =
            mid - (mid / r[0] + mid / r[1] - mid / lcm(r[0], r[1]));

        if (del1 >= d[0] && del2 >= d[1] && del1 + del2 - del3 >= d[0] + d[1]) {
            return true;
        }

        return false;
    }

public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long low = 0LL;
        long long high = 1LL * 1e18;
        long long minDel = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, d, r)) {
                minDel = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return minDel;
    }
};