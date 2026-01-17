class NumMatrix {
public:
    vector<vector<int>> pref;

    NumMatrix(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        pref.assign(m, vector<int>(n));

        pref[0][0] = v[0][0];

        // first row
        for (int j = 1; j < n; j++) {
            pref[0][j] = v[0][j] + pref[0][j - 1];
        }

        // first column
        for (int i = 1; i < m; i++) {
            pref[i][0] = v[i][0] + pref[i - 1][0];
        }

        // rest of the matrix
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                pref[i][j] = v[i][j] + pref[i - 1][j] + pref[i][j - 1] -
                             pref[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
        int ans = pref[r2][c2];

        if (r1 > 0) {
            ans -= pref[r1 - 1][c2];
        }
        if (c1 > 0) {
            ans -= pref[r2][c1 - 1];
        }
        if (r1 > 0 && c1 > 0) {
            ans += pref[r1 - 1][c1 - 1];
        }

        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */