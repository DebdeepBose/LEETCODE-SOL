class Solution {
private:
    void bfs(int rowNode, int colNode, vector<vector<char>>& grid,
             vector<vector<int>>& vis, int n, int m) {
        vis[rowNode][colNode] = 1;
        queue<pair<int, int>> q;
        q.push({rowNode, colNode});

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    if (abs(i) == 1 && abs(j) == 1) {
                        continue;
                    }

                    int neighborRow = row + i;
                    int neighborCol = col + j;

                    if (neighborRow >= 0 && neighborRow < n &&
                        neighborCol >= 0 && neighborCol < m) {
                        if (grid[neighborRow][neighborCol] == '1' &&
                            !vis[neighborRow][neighborCol]) {
                            vis[neighborRow][neighborCol] = 1;
                            q.push({neighborRow, neighborCol});
                        }
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int c = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    c++;
                    bfs(i, j, grid, vis, n, m);
                }
            }
        }
        return c;
    }
};
