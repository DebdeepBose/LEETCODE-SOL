class Solution {
public:
    int coinChange(vector<int>& v, int amt) {
        int n = v.size();
        vector<int> dp(amt + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = v[i]; j <= amt; j++) {
                dp[j] = min(dp[j], 1 + dp[j - v[i]]);
            }
        }
        if (dp[amt] >= 1e9) {
            return -1;
        }
        return dp[amt];
    }
};