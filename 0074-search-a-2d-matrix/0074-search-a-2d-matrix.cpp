class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int k) {
        int m = v.size();
        int n = v[0].size();
        for (int i = 0; i < m; i++) {
            if (v[i][n - 1] < k) {
                continue;
            }
            auto it = lower_bound(v[i].begin(), v[i].end(), k);
            if (*it == k) {
                return true;
            }
        }
        return false;
    }
};