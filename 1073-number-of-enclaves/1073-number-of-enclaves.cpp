class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Top Boundary
        for (int j = 0; j < n; j++) {
            if (!visited[0][j] && grid[0][j] == 1) {
                dfs(0, j, dx, dy, visited, grid, m, n);
            }
        }

        // Bottom Boundary
        for (int j = 0; j < n; j++) {
            if (!visited[m - 1][j] && grid[m - 1][j] == 1) {
                dfs(m - 1, j, dx, dy, visited, grid, m, n);
            }
        }

        // Left Boundary
        for (int i = 0; i < m; i++) {
            if (!visited[i][0] && grid[i][0] == 1) {
                dfs(i, 0, dx, dy, visited, grid, m, n);
            }
        }

        // Right Boundary
        for (int i = 0; i < m; i++) {
            if (!visited[i][n - 1] && grid[i][n - 1] == 1) {
                dfs(i, n - 1, dx, dy, visited, grid, m, n);
            }
        }

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }

    void dfs(int r, int c, vector<int>& dx, vector<int>& dy,
             vector<vector<bool>>& visited, vector<vector<int>>& grid, int m,
             int n) {

        visited[r][c] = true;
        for (int d = 0; d < 4; d++) {
            int x = r + dx[d];
            int y = c + dy[d];

            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] &&
                grid[x][y] == 1) {
                dfs(x, y, dx, dy, visited, grid, m, n);
            }
        }
    }
};