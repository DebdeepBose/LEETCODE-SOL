class Solution {
public:
    bool canPartition(vector<int>& v) {
        int n = v.size();
        int sum = accumulate(v.begin(), v.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        int hs = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(hs + 1, false));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= hs; j++) {
                if (v[i - 1] <= j) {
                    bool take = dp[i - 1][j - v[i - 1]];
                    bool notTake = dp[i - 1][j];
                    dp[i][j] = take || notTake;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][hs];
    }
};