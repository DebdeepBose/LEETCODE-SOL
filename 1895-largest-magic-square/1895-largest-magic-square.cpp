class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        vector<vector<int>> pr(m, vector<int>(n));
        vector<vector<int>> pc(n, vector<int>(m));

        // prefix sums
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (j == 0)
                    pr[i][j] = v[i][j];
                else
                    pr[i][j] = v[i][j] + pr[i][j - 1];

                if (i == 0)
                    pc[j][i] = v[i][j];
                else
                    pc[j][i] = v[i][j] + pc[j][i - 1];
            }
        }

        int ans = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int maxLen = min(m - i, n - j);

                for (int len = maxLen; len > ans; len--) {

                    // target = first row sum
                    int target = pr[i][j + len - 1] -
                                 (j > 0 ? pr[i][j - 1] : 0);

                    bool ok = true;

                    // check rows
                    for (int r = i; r < i + len && ok; r++) {
                        int sum = pr[r][j + len - 1] -
                                  (j > 0 ? pr[r][j - 1] : 0);
                        if (sum != target) ok = false;
                    }

                    // check columns
                    for (int c = j; c < j + len && ok; c++) {
                        int sum = pc[c][i + len - 1] -
                                  (i > 0 ? pc[c][i - 1] : 0);
                        if (sum != target) ok = false;
                    }

                    // check diagonals
                    int d1 = 0, d2 = 0;
                    for (int k = 0; k < len; k++) {
                        d1 += v[i + k][j + k];
                        d2 += v[i + len - 1 - k][j + k];
                    }

                    if (ok && d1 == target && d2 == target) {
                        ans = len;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
