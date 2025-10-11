class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int battleShips = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && board[i][j] == 'X') {
                    battleShips++;
                    dfs(i, j, m, n, dx, dy, vis, board);
                }
            }
        }

        return battleShips;
    }

    void dfs(int r, int c, int m, int n, vector<int>& dx, vector<int>& dy,
             vector<vector<bool>>& vis, vector<vector<char>>& board) {

        vis[r][c] = true;

        for (int d = 0; d < 4; d++) {
            int x = r + dx[d];
            int y = c + dy[d];

            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] &&
                board[x][y] == 'X') {

                dfs(x, y, m, n, dx, dy, vis, board);
            }
        }
    }
};