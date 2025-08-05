class Solution {
public:
    int rob(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n, 0);
        dp[0] = v[0];
        for (int i = 1; i < n; i++) {
            int take = v[i];
            if (i > 1) {
                take += dp[i - 2];
            }
            int skip = dp[i - 1];
            dp[i] = max(take, skip);
        }
        return dp[n - 1];
    }
};