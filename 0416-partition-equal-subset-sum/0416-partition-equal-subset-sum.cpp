class Solution {
public:
    bool help(vector<int>& v, int n, int hs, vector<vector<int>>& dp) {
        if (hs == 0) {
            return true;
        }
        if (n == 0) {
            return false;
        }
        if (dp[n][hs] != -1) {
            return dp[n][hs];
        }

        if (v[n - 1] <= hs) {
            bool take = help(v, n - 1, hs - v[n - 1], dp);
            bool notTake = help(v, n - 1, hs, dp);
            if (take || notTake) {
                dp[n][hs] = true;
            } else {
                dp[n][hs] = false;
            }
        } else {
            dp[n][hs] = help(v, n - 1, hs, dp);
        }
        return dp[n][hs];
    }
    bool canPartition(vector<int>& v) {
        int n = v.size();
        int sum = accumulate(v.begin(), v.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        int hs = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(hs + 1, -1));
        return help(v, n, hs, dp);
    }
};