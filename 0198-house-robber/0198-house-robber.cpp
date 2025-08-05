class Solution {
public:
    int rob(vector<int>& v) {
        int n = v.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return v[0];
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = v[0];
        for (int i = 2; i <= n; i++) {
            int take = v[i - 1] + dp[i - 2];
            int skip = dp[i - 1];
            dp[i] = max(take, skip);
        }
        return dp[n];
    }
};