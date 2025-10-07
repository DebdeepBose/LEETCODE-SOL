class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> dist(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            dist[r][c] = d;

            for (int k = 0; k < 4; k++) {
                int x = r + dx[k];
                int y = c + dy[k];

                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                    vis[x][y] = true;
                    q.push({{x, y}, d + 1});
                }
            }
        }
        return dist;
    }
};