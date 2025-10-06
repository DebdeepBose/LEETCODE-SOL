class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int time = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = r + dx[i];
                int y = c + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] &&
                    grid[x][y] == 1 && grid[x][y] != 2) {
                    q.push({{x, y}, t + 1});
                    grid[x][y] = 2;
                    visited[x][y] = true;
                }
            }
        }
        for (auto e : grid) {
            for (auto ee : e) {
                if (ee == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};