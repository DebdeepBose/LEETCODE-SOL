class Solution {
public:
    int helper(vector<int>& v, int n, int end, vector<int>& dp) {
        if (n <= end) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int take = v[n - 1] + helper(v, n - 2, end, dp);
        int skip = helper(v, n - 1, end, dp);
        dp[n] = max(take, skip);
        return dp[n];
    }
    int rob(vector<int>& v) {
        int n = v.size();
        if (n == 1) {
            return v[0];
        }
        vector<int> dp1(n + 1, -1);
        vector<int> dp2(n + 1, -1);
        int s1 = helper(v, n - 1, 0, dp1);
        int s2 = helper(v, n, 1, dp2);
        return max(s1, s2);
    }
};