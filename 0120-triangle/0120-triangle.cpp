class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        int n = v.size();
        vector<vector<int>> dp = v;   

        for (int j = n - 2; j >= 0; j--) {
            for (int i = 0; i < v[j].size(); i++) {
                dp[j][i] = v[j][i] + min(dp[j + 1][i], dp[j + 1][i + 1]);
            }
        }
        return dp[0][0];
    }
};
