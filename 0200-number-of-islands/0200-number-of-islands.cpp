class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        int m = grid.size();
        int n = grid[0].size();
        int c = 0;
        vector<vector<bool>> vis(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    c++;
                    dfs(i, j, grid, vis, dx, dy);
                }
            }
        }
        return c;
    }

    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis,
             vector<int>& dx, vector<int>& dy) {

        vis[i][j] = true;
        for (int d = 0; d < 4; d++) {
            int x = i + dx[d];
            int y = j + dy[d];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                if (!vis[x][y] && grid[x][y] == '1') {
                    dfs(x, y, grid, vis, dx, dy);
                }
            }
        }
    }
};
