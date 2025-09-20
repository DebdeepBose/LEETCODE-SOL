class Solution {
public:
    int reachNumber(int n) {
        n = abs(n);
        int low = 1;
        int high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long sum = 1LL * mid * (mid + 1) / 2;
            if (sum >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        long long sum = 1LL * ans * (ans + 1) / 2;
        while ((sum - n) % 2 != 0) {
            ans++;
            sum += ans;
        }
        return ans;
    }
};
