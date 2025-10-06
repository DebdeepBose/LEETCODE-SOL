class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};

        int oldColor = image[sr][sc];

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        image[sr][sc] = color;
        dfs(sr, sc, dx, dy, visited, m, n, image, color, oldColor);

        return image;
    }
    void dfs(int i, int j, vector<int>& dx, vector<int>& dy,
             vector<vector<bool>>& visited, int m, int n,
             vector<vector<int>>& image, int color, int oldColor) {
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] &&
                image[x][y] == oldColor) {
                image[x][y] = color;
                dfs(x, y, dx, dy, visited, m, n, image, color, oldColor);
            }
        }
    }
};