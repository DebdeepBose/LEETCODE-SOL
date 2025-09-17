class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int k) {
        int m = v.size();
        int n = v[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == k) {
                    return true;
                }
            }
        }
        return false;
    }
};