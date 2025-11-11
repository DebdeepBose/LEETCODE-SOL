class Solution {
public:
    int findMaxForm(vector<string>& v, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (auto s : v) {
            int zeros = count(s.begin(), s.end(), '0');
            int ones = s.size() - zeros;

            // reverse loops to avoid overwriting states we still need
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }
        return dp[m][n];
    }
};
