class Solution {
public:
    int findMaxFish(vector<vector<int>>& pool) {

        int m = pool.size();
        int n = pool[0].size();

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};

        vector<vector<bool>> vis(m, vector<bool>(n, 0));

        int maxFishes = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && pool[i][j] > 0) {
                    int fishCount = pool[i][j];
                    dfs(i, j, m, n, dx, dy, vis, pool, fishCount);
                    maxFishes = max(maxFishes, fishCount);
                }
            }
        }

        return maxFishes;
    }

    void dfs(int row, int col, int m, int n, vector<int>& dx, vector<int>& dy,
             vector<vector<bool>>& vis, vector<vector<int>>& pool,
             int& fishCount) {

        vis[row][col] = true;
        for (int k = 0; k < 4; k++) {
            int x = row + dx[k];
            int y = col + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] &&
                pool[x][y] > 0) {
                fishCount += pool[x][y];
                dfs(x, y, m, n, dx, dy, vis, pool, fishCount);
            }
        }
    }
};