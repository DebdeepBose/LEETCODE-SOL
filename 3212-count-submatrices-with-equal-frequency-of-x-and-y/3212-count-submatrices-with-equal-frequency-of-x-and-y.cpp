class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& v) {
        int m = v.size(), n = v[0].size();

        vector<vector<int>> sum(m, vector<int>(n, 0));
        vector<vector<int>> cntX(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = 0;

                if (v[i][j] == 'X') {
                    val = 1;
                } else {
                    if (v[i][j] == 'Y') {
                        val = -1;
                    } else {
                        val = 0;
                    }
                }

                sum[i][j] = val;

                if (v[i][j] == 'X') {
                    cntX[i][j] = 1;
                } else {
                    cntX[i][j] = 0;
                }

                if (i > 0) {
                    sum[i][j] += sum[i - 1][j];
                    cntX[i][j] += cntX[i - 1][j];
                }

                if (j > 0) {
                    sum[i][j] += sum[i][j - 1];
                    cntX[i][j] += cntX[i][j - 1];
                }

                if (i > 0 && j > 0) {
                    sum[i][j] -= sum[i - 1][j - 1];
                    cntX[i][j] -= cntX[i - 1][j - 1];
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (sum[i][j] == 0) {
                    if (cntX[i][j] > 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};