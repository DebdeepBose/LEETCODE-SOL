class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = i; j < n; j++) {
                swap(v[i][j], v[j][i]);
            }
        }
        for (int i = 0; i < m; i++) {
            reverse(v[i].begin(), v[i].end());
        }
    }
};