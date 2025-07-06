class Solution {
public:
    int m, n;

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, queue<pair<int, int>>& q,
             vector<vector<int>>& timeGrid) {
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newr = r + dx[i];
                int newc = c + dy[i];
                if (newr >= 0 && newr < m && newc >= 0 && newc < n &&
                    !vis[newr][newc] && grid[newr][newc] == 1) {
                    q.push({newr, newc});
                    vis[newr][newc] = 1;
                    grid[newr][newc] = 2; 
                    timeGrid[newr][newc] = timeGrid[r][c] + 1;
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> timeGrid(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        bfs(grid, vis, q, timeGrid);

        int maxTime = 0;
        int rotted = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) return -1;
                maxTime = max(maxTime, timeGrid[i][j]);
            }
        }

        return maxTime;
    }
};
