class Solution {
public:
    int minCostClimbingStairs(vector<int>& v) {
        int n = v.size();
        int ans = tryDP(v, n);
        return ans;
    }
    int tryDP(vector<int>& v, int n) {
        vector<int> dp(n, -1);
        dp[0] = v[0];
        dp[1] = v[1];
        for (int i = 2; i < n; i++) {
            dp[i] = v[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};