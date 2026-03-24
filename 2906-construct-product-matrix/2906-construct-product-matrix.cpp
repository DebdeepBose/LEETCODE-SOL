class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 12345;
        int total = m * n;

        vector<long long> flat;
        flat.reserve(total);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                flat.push_back(grid[i][j] % MOD);
            }
        }

        vector<int> prefProd(total), sufProd(total);

        prefProd[0] = flat[0];
        for (int i = 1; i < total; i++) {
            prefProd[i] = (prefProd[i - 1] * flat[i]) % MOD;
        }

        sufProd[total - 1] = flat[total - 1] % MOD;
        for (int i = total - 2; i >= 0; i--) {
            sufProd[i] = (sufProd[i + 1] * flat[i]) % MOD;
        }

        vector<int> ans(total);
        ans[0] = sufProd[1] % MOD;
        ans[total - 1] = prefProd[total - 2] % MOD;
        for (int i = 1; i < total - 1; i++) {
            ans[i] = (1LL * prefProd[i - 1] * sufProd[i + 1]) % MOD;
        }

        int k = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = ans[k++];
            }
        }

        return grid;
    }
};