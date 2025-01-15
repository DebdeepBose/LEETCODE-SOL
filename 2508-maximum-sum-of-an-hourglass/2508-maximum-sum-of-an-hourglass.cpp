class Solution {
public:
    int maxSum(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        int ans = INT_MIN;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                int s = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 1] +
                        v[i + 2][j] + v[i + 2][j + 1] + v[i + 2][j + 2];
                ans = max(ans, s);
            }
        }
        return ans;
    }
};