class Solution {
public:
    int helper(vector<int>& v, int st, int end, vector<int>& dp) {

        // Base Case
        if (st > end) {
            return 0;
        }

        if (dp[st] != -1) {
            return dp[st];
        }

        // We take the current element
        int take = v[st] + helper(v, st + 2, end, dp);

        // We don't take the current element
        int skip = helper(v, st + 1, end, dp);

        // We will return whoever gives the greater sum
        dp[st] = max(take, skip);

        return dp[st];
    }
    int rob(vector<int>& v) {
        int n = v.size();
        int st = 0;

        // If there is only 1 element we cannot start from index 1(element : 2)
        // so in that case we return v[0]
        if (n == 1) {
            return v[0];
        }

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        // From index 1 to n - 1
        int s1 = helper(v, st + 1, n - 1, dp1);

        // From index 0 to n - 2
        int s2 = helper(v, st, n - 2, dp2);

        // We will return whoever gives the greater sum
        return max(s1, s2);
    }
};