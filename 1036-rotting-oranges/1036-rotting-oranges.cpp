class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        vector<vector<int>> time(m, vector<int>(n, INT_MAX));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    time[i][j] = 0;
                    dfs(i, j, grid, time, dx, dy, m, n, 0);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && time[i][j] == INT_MAX) {
                    return -1; 
                }
                if (grid[i][j] != 0 && time[i][j] != INT_MAX) {
                    ans = max(ans, time[i][j]);
                }
            }
        }

        return ans;
    }

private:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& time,
             vector<int>& dx, vector<int>& dy, int m, int n, int t) {

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n) {
            
                if (grid[x][y] != 0 && time[x][y] > t + 1) {
                    time[x][y] = t + 1;
                    dfs(x, y, grid, time, dx, dy, m, n, t + 1);
                }
            }
        }
    }
};
