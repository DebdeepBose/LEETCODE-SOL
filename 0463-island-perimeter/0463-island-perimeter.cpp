class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        /* Pretty standard graph question, the approach is simpls if you are
         * standing at cell 'C' and the next cell is the Boundary or water
         * simply increase perimeter by 1, on close observation you shud be able
         * to figure out the logic*/

        int m = grid.size();
        int n = grid[0].size();

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int perimeter = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    dfs(i, j, m, n, dx, dy, vis, perimeter, grid);
                }
            }
        }
        return perimeter;
    }
    void dfs(int row, int column, int m, int n, vector<int>& dx,
             vector<int>& dy, vector<vector<bool>>& vis, int& perimeter,
             vector<vector<int>>& grid) {
        vis[row][column] = true;

        for (int k = 0; k < 4; k++) {
            int x = row + dx[k];
            int y = column + dy[k];

            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
                perimeter++;
            } else if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] &&
                       grid[x][y] == 1) {
                dfs(x, y, m, n, dx, dy, vis, perimeter, grid);
            }
        }
    }
};
