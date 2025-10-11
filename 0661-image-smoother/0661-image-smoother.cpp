class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        int m = img.size();
        int n = img[0].size();

        vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int neighborSum = img[i][j];
                int validNeighborCount = 1;
                for (int k = 0; k < 8; k++) {

                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        neighborSum += img[x][y];
                        validNeighborCount++;
                    }
                }
                ans[i][j] = floor(neighborSum / validNeighborCount);
            }
        }
        return ans;
    }
};