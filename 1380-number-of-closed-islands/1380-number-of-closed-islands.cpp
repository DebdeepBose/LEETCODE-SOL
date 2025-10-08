class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Top boundary
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0 && !vis[0][j])
                dfs(0, j, dx, dy, vis, grid, m, n);
        }

        // Bottom boundary
        for (int j = 0; j < n; j++) {
            if (grid[m - 1][j] == 0 && !vis[m - 1][j])
                dfs(m - 1, j, dx, dy, vis, grid, m, n);
        }

        // Left boundary
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0 && !vis[i][0])
                dfs(i, 0, dx, dy, vis, grid, m, n);
        }

        // Right boundary
        for (int i = 0; i < m; i++) {
            if (grid[i][n - 1] == 0 && !vis[i][n - 1])
                dfs(i, n - 1, dx, dy, vis, grid, m, n);
        }


        int count = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    count++;
                    dfs(i, j, dx, dy, vis, grid, m, n);
                }
            }
        }

        return count;
    }

private:
    void dfs(int row, int col, vector<int>& dx, vector<int>& dy,
             vector<vector<bool>>& vis, vector<vector<int>>& grid, int m, int n) {
        vis[row][col] = true;

        for (int i = 0; i < 4; i++) {
            int x = row + dx[i];
            int y = col + dy[i];

            if (x >= 0 && x < m && y >= 0 && y < n &&
                !vis[x][y] && grid[x][y] == 0) {
                dfs(x, y, dx, dy, vis, grid, m, n);
            }
        }
    }
};
