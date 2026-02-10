class Solution {
public:
    int minimumOperations(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        int op = 0;

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] <= v[i - 1][j]) {
                    int inc = abs(v[i - 1][j] - v[i][j]) + 1;
                    v[i][j] += inc;
                    op += inc;
                }
            }
        }
        return op;
    }
};