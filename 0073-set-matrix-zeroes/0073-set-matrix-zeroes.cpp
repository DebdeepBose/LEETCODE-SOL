class Solution {
public:
    void markr(vector<vector<int>>& v, int i , int m) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] != 0) {
                v[i][j] = -98;
            }
        }
    }
    void markc(vector<vector<int>>& v, int j, int n) {
        for (int i = 0; i < n; i++) {
            if (v[i][j] != 0) {
                v[i][j] = -98;
            }
        }
    }
    void setZeroes(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 0) {
                    markr(v, i, m);
                    markc(v, j, n);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == -98) {
                    v[i][j] = 0;
                }
            }
        }
    }
};