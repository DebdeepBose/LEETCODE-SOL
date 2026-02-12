class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        for (int i = 0; i < m; i++) {
            if (n % 2 == 1) {
                v[i][n / 2] = !v[i][n / 2];
            }
            for (int j = 0; j < n / 2; j++) {
                swap(v[i][j], v[i][n - j - 1]);
                v[i][j] = !v[i][j];
                v[i][n - j - 1] = !v[i][n - j - 1];
            }
        }
        return v;
    }
};