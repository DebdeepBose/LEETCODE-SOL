class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& v, int m, int n) {
        if (m * n < v.size() || m * n > v.size()) {
            return {};
        }
        vector<vector<int>> ans(m, vector<int>(n));
        int k = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = v[k++];
            }
        }
        return ans;
    }
};