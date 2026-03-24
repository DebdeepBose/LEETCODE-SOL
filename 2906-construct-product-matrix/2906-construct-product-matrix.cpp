class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<tuple<int, int, int>> flat; 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                flat.push_back({grid[i][j] % 12345, i, j});
            }
        }

        vector<int> prefProd(flat.size()), sufProd(flat.size());

        prefProd[0] = get<0>(flat[0]);
        for (int i = 1; i < flat.size(); i++) {
            prefProd[i] = (prefProd[i - 1] * get<0>(flat[i])) % 12345;
        }

        sufProd[flat.size() - 1] = get<0>(flat.back());
        for (int i = flat.size() - 2; i >= 0; i--) {
            sufProd[i] = (sufProd[i + 1] * get<0>(flat[i])) % 12345;
        }

        vector<int> ans(flat.size());
        ans[0] = (sufProd[1]) % 12345;
        ans[flat.size() - 1] = (prefProd[flat.size() - 2]) % 12345;
        for (int i = 1; i < flat.size() - 1; i++) {
            ans[i] = (prefProd[i - 1] * sufProd[i + 1]) % 12345;
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