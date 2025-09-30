class Solution {
public:
    void gameOfLife(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> copy = v;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 0) {
                    int zo = 0;

                    if (i > 0) {
                        if (v[i - 1][j] == 1) {
                            zo++;
                        }
                    }
                    if (i < n - 1) {
                        if (v[i + 1][j] == 1) {
                            zo++;
                        }
                    }
                    if (j > 0) {
                        if (v[i][j - 1] == 1) {
                            zo++;
                        }
                    }
                    if (j < m - 1) {
                        if (v[i][j + 1] == 1) {
                            zo++;
                        }
                    }
                    if (i > 0 && j > 0) {
                        if (v[i - 1][j - 1] == 1) {
                            zo++;
                        }
                    }
                    if (i < n - 1 && j > 0) {
                        if (v[i + 1][j - 1] == 1) {
                            zo++;
                        }
                    }
                    if (i > 0 && j < m - 1) {
                        if (v[i - 1][j + 1] == 1) {
                            zo++;
                        }
                    }
                    if (i < n - 1 && j < m - 1) {
                        if (v[i + 1][j + 1] == 1) {
                            zo++;
                        }
                    }

                    if (zo == 3) {
                        copy[i][j] = 1;
                    }
                } else if (v[i][j] == 1) {
                    int oo = 0;

                    if (i > 0) {
                        if (v[i - 1][j] == 1) {
                            oo++;
                        }
                    }
                    if (i < n - 1) {
                        if (v[i + 1][j] == 1) {
                            oo++;
                        }
                    }
                    if (j > 0) {
                        if (v[i][j - 1] == 1) {
                            oo++;
                        }
                    }
                    if (j < m - 1) {
                        if (v[i][j + 1] == 1) {
                            oo++;
                        }
                    }
                    if (i > 0 && j > 0) {
                        if (v[i - 1][j - 1] == 1) {
                            oo++;
                        }
                    }
                    if (i < n - 1 && j > 0) {
                        if (v[i + 1][j - 1] == 1) {
                            oo++;
                        }
                    }
                    if (i > 0 && j < m - 1) {
                        if (v[i - 1][j + 1] == 1) {
                            oo++;
                        }
                    }
                    if (i < n - 1 && j < m - 1) {
                        if (v[i + 1][j + 1] == 1) {
                            oo++;
                        }
                    }

                    if (oo < 2 || oo > 3) {
                        copy[i][j] = 0;
                    }
                }
            }
        }
        v = copy;
    }
};
