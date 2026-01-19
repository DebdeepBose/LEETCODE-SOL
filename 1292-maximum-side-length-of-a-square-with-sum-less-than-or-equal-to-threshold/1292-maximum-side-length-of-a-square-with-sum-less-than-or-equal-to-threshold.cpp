class Solution {
public:
    int maxSideLength(vector<vector<int>>& v, int k) {
        int m = v.size();
        int n = v[0].size();

        vector<vector<int>> pref(m, vector<int>(n));
        pref[0][0] = v[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                } else if (i == 0) {
                    pref[i][j] = pref[i][j - 1] + v[i][j];
                } else if (j == 0) {
                    pref[i][j] = pref[i - 1][j] + v[i][j];
                } else {
                    pref[i][j] = pref[i - 1][j] + pref[i][j - 1] + v[i][j] -
                                 pref[i - 1][j - 1];
                }
            }
        }

        int maxSide = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int len = maxSide + 1; len <= min(i + 1, j + 1); len++) {

                    int r = i - len;
                    int c = j - len;

                    int sum = pref[i][j] - (r >= 0 ? pref[r][j] : 0) -
                              (c >= 0 ? pref[i][c] : 0) +
                              (r >= 0 && c >= 0 ? pref[r][c] : 0);

                    if (sum <= k) {
                        maxSide = len;
                    } else {
                        break;
                    }
                }
            }
        }

        return maxSide;
    }
};
