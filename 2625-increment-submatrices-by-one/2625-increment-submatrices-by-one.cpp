class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {

        vector<vector<int>> v(n, vector<int>(n, 0));

        for (int i = 0; i < q.size(); i++) {
            int topLeftX = q[i][0];
            int topLeftY = q[i][1];
            int bottomRightX = q[i][2];
            int bottomRightY = q[i][3];

      
            for (int r = topLeftX; r <= bottomRightX; r++) {
                for (int c = topLeftY; c <= bottomRightY; c++) {
                    v[r][c] += 1;
                }
            }
        }

        return v;
    }
};
