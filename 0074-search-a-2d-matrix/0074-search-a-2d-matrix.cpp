class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int k) {
        int m = v.size();
        int n = v[0].size();
        int j = n - 1;
        for (int i = 0; i < m; i++) {
            if (v[i][n - 1] < k) {
                continue;
            }
            if (v[i][n - 1] == k) {
                return true;
            }
            while (j >= 0) {
                if (v[i][j] == k) {
                    return true;
                }
                j--;
            }
        }
        return false;
    }
};