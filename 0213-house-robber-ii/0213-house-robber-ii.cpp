class Solution {
public:
    int robLinear(vector<int>& v, int st, int end) {
        int n = end - st + 1;
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return v[st];
        }

        vector<int> dp(n, 0);
        dp[0] = v[st];
        dp[1] = max(v[st], v[st + 1]);

        for (int i = 2; i < n; i++) {
            int take = v[st + i] + dp[i - 2];
            int skip = dp[i - 1];
            dp[i] = max(take, skip);
        }

        return dp[n - 1];
    }

    int rob(vector<int>& v) {
        int n = v.size();
        if (n == 1) {
            return v[0];
        }

        int case1 = robLinear(v, 0, n - 2);
        int case2 = robLinear(v, 1, n - 1);

        return max(case1, case2);
    }
};
