class Solution {
public:
    int help(vector<int>& v, int n, int i, vector<int>& dp) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int lsum = v[i] + help(v, n, i + 2, dp);
        int rsum = help(v, n, i + 1, dp);
        dp[i] = max(lsum, rsum);
        return dp[i];
    }
    int rob(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n, -1);
        return help(v, n, 0, dp);
    }
};