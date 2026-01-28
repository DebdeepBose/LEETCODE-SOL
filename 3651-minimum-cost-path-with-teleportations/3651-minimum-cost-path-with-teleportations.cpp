class Solution {
public:
    int minCost(vector<vector<int>>& v, int k) {
        int m = v.size();
        int n = v[0].size();

        vector<vector<long long>> dp(m, vector<long long>(n, LLONG_MAX));

        dp[0][0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + v[i][j]);
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + v[i][j]);
            }
        }

        vector<tuple<int, int, int>> cells;
        cells.reserve(m * n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cells.emplace_back(v[i][j], i, j);

        sort(cells.begin(), cells.end(),
             [](auto& a, auto& b) { return get<0>(a) > get<0>(b); });

        for (int step = 0; step < k; step++) {
            vector<vector<long long>> start(m, vector<long long>(n, LLONG_MAX));

            long long running_min = LLONG_MAX;
            int idx = 0;

            while (idx < (int)cells.size()) {
                int val = get<0>(cells[idx]);
                int j = idx;
                long long min_group = LLONG_MAX;

                while (j < (int)cells.size() && get<0>(cells[j]) == val) {
                    int x = get<1>(cells[j]);
                    int y = get<2>(cells[j]);
                    min_group = min(min_group, dp[x][y]);
                    j++;
                }

                running_min = min(running_min, min_group);

                for (int p = idx; p < j; p++) {
                    int x = get<1>(cells[p]);
                    int y = get<2>(cells[p]);
                    start[x][y] = min(dp[x][y], running_min);
                }

                idx = j;
            }

            vector<vector<long long>> dp2(m, vector<long long>(n, LLONG_MAX));

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (start[i][j] < LLONG_MAX) {
                        dp2[i][j] = min(dp2[i][j], start[i][j]);

                        if (i + 1 < m)
                            dp2[i + 1][j] =
                                min(dp2[i + 1][j], dp2[i][j] + v[i + 1][j]);

                        if (j + 1 < n)
                            dp2[i][j + 1] =
                                min(dp2[i][j + 1], dp2[i][j] + v[i][j + 1]);
                    }
                }
            }

            dp.swap(dp2);
        }

        return (int)dp[m - 1][n - 1];
    }
};
