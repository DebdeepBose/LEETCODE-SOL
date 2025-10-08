class Solution {
public:
    void solve(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Top Boundary
        for (int j = 0; j < n; j++) {
            if (!vis[0][j] && grid[0][j] == 'O') {
                dfs(0, j, dx, dy, vis, grid, m, n);
            }
        }

        // Left Boundary
        for (int i = 0; i < m; i++) {
            if (!vis[i][0] && grid[i][0] == 'O') {
                dfs(i, 0, dx, dy, vis, grid, m, n);
            }
        }

        // Right Boundary
        for (int i = 0; i < m; i++) {
            if (!vis[i][n - 1] && grid[i][n - 1] == 'O') {
                dfs(i, n - 1, dx, dy, vis, grid, m, n);
            }
        }

        // Bottom Boundary
        for (int j = 0; j < n; j++) {
            if (!vis[m - 1][j] && grid[m - 1][j] == 'O') {
                dfs(m - 1, j, dx, dy, vis, grid, m, n);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'O' && !vis[i][j]) {
                    grid[i][j] = 'X';
                }
            }
        }

    }
    void dfs(int r, int c, vector<int>& dx, vector<int>& dy,
             vector<vector<bool>>& vis, vector<vector<char>>& grid, int m,
             int n) {

        vis[r][c] = true;

        for (int d = 0; d < 4; d++) {
            int x = r + dx[d];
            int y = c + dy[d];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] &&
                grid[x][y] == 'O') {
                dfs(x, y, dx, dy, vis, grid, m, n);
            }
        }
    }
};