class Solution {
public:
    void gameOfLife(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int alive = 0;
                if (i > 0) {
                    if (v[i - 1][j] == 1 || v[i - 1][j] == -1) {
                        alive++;
                    }
                }
                if (i < n - 1) {
                    if (v[i + 1][j] == 1 || v[i + 1][j] == -1) {
                        alive++;
                    }
                }
                if (j > 0) {
                    if (v[i][j - 1] == 1 || v[i][j - 1] == -1) {
                        alive++;
                    }
                }
                if (j < m - 1) {
                    if (v[i][j + 1] == 1 || v[i][j + 1] == -1) {
                        alive++;
                    }
                }
                if (i > 0 && j > 0) {
                    if (v[i - 1][j - 1] == 1 || v[i - 1][j - 1] == -1) {
                        alive++;
                    }
                }
                if (i < n - 1 && j > 0) {
                    if (v[i + 1][j - 1] == 1 || v[i + 1][j - 1] == -1) {
                        alive++;
                    }
                }
                if (i > 0 && j < m - 1) {
                    if (v[i - 1][j + 1] == 1 || v[i - 1][j + 1] == -1) {
                        alive++;
                    }
                }
                if (i < n - 1 && j < m - 1) {
                    if (v[i + 1][j + 1] == 1 || v[i + 1][j + 1] == -1) {
                        alive++;
                    }
                }

                if (v[i][j] == 1) {
                    if (alive < 2 || alive > 3) {
                        v[i][j] = -1; 
                    }
                } else if (v[i][j] == 0) {
                    if (alive == 3) {
                        v[i][j] = 2; 
                    }
                }
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == -1) {
                    v[i][j] = 0;
                } else if (v[i][j] == 2) {
                    v[i][j] = 1;
                }
            }
        }
    }
};
