class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        // Easy ahh problem once you do a few questions of graph
        // Btw this isnt a graph problem

        int m = img.size();
        int n = img[0].size();

        /*It needs 8 directions so either use 2 loops or 2 vectors and save the
         * directions*/
        vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};

        // We make an ans 2d vector cuz idk how to do it in-place
        //  is that even possible
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Need these 2
                int neighborSum = img[i][j];
                int validNeighborCount = 1;

                // We search 8 directions
                for (int k = 0; k < 8; k++) {

                    int x = i + dx[k];
                    int y = j + dy[k];

                    // This is a simple valididty check u see a lot in graphs
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