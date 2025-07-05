class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc,
                                  int color) {
        int m = img.size();
        int n = img[0].size();
        int ogColor = img[sr][sc];
        if (ogColor == color) {
            return img;
        }
        bfs(img, sr, sc, color, ogColor, m, n);
        return img;
    }

    void bfs(vector<vector<int>>& img, int sr, int sc, int color,
             int ogColor, int m, int n) {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        img[sr][sc] = color;

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            vector<int> dx = {0, 0, -1, 1};
            vector<int> dy = {-1, 1, 0, 0};

            for (int i = 0; i < 4; i++) {
                int newr = r + dx[i];
                int newc = c + dy[i];
                if (newr >= 0 && newr < m && newc >= 0 && newc < n) {
                    if (img[newr][newc] == ogColor) {
                        img[newr][newc] = color;
                        q.push({newr, newc});
                    }
                }
            }
        }
    }
};
