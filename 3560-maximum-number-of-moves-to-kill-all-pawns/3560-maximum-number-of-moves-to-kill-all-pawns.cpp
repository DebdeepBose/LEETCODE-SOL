class Solution {
public:
    int nPawn, n;
    int dist[16][50][50];
    int dp[16][2][65000];
    vector<vector<int>> pawnPos;

    int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

    bool check(int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= n) {
            return false;
        }
        return true;
    }

    void bfsFromPawn(int pawnIdx) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[pawnIdx][i][j] = 1e9;
            }
        }
        dist[pawnIdx][pawnPos[pawnIdx][0]][pawnPos[pawnIdx][1]] = 0;
        queue<pair<int, int>> q;
        q.push({pawnPos[pawnIdx][0], pawnPos[pawnIdx][1]});
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int curDist = dist[pawnIdx][cur.first][cur.second];
            for (int k = 0; k < 8; k++) {
                int nx = cur.first + dx[k];
                int ny = cur.second + dy[k];
                if (!check(nx, ny))
                    continue;
                if (dist[pawnIdx][nx][ny] > curDist + 1) {
                    dist[pawnIdx][nx][ny] = curDist + 1;
                    q.push({nx, ny});
                }
            }
        }
        return;
    }

    int rec(int pawnIdx, int isAlice, int mask) {
        if (mask == ((1 << nPawn) - 1)) {
            return 0;
        }

        if (dp[pawnIdx][isAlice][mask] != -1) {
            return dp[pawnIdx][isAlice][mask];
        }

        int ans = (isAlice) ? -1e9 : 1e9;

        for (int i = 0; i < nPawn; i++) {
            if ((1 << i) & mask)
                continue;
            if (isAlice) {
                ans = max(ans, rec(i, !isAlice, (mask | (1 << i))) +
                                   dist[pawnIdx][pawnPos[i][0]][pawnPos[i][1]]);
            } else {
                ans = min(ans, rec(i, !isAlice, (mask | (1 << i))) +
                                   dist[pawnIdx][pawnPos[i][0]][pawnPos[i][1]]);
            }
        }

        return dp[pawnIdx][isAlice][mask] = ans;
    }

    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        memset(dp, -1, sizeof(dp));
        pawnPos = positions;
        nPawn = positions.size();
        n = 50;
        pawnPos.push_back({kx, ky});
        for (int i = 0; i <= nPawn; i++) {
            bfsFromPawn(i);
        }
        return rec(nPawn, 1, 0);
    }
};