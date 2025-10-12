class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int maxlen = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    int len = 1;
                    dfs(i, j, m, n, dx, dy, vis, grid, len);
                    maxlen = max(maxlen, len);
                }
            }
        }
        return maxlen;
    }
    void dfs(int r, int c, int m, int n, vector<int>& dx, vector<int>& dy,
             vector<vector<bool>>& vis, vector<vector<int>> grid, int& len) {

        vis[r][c] = true;

        for (int k = 0; k < 4; k++) {
            int x = r + dx[k];
            int y = c + dy[k];

            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] &&
                grid[x][y] == 1) {
                len++;
                dfs(x, y, m, n, dx, dy, vis, grid, len);
            }
        }
    }
};