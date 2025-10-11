class Solution {
public:
    vector<vector<int>> specialGrid(int n) {
        vector<vector<int>> ans(pow(2, n), vector<int>(pow(2, n), -1));
        int stVal = 0;
        make(0, pow(2, n), 0, pow(2, n), ans, stVal);

        return ans;
    }
    void make(int stRow, int endRow, int stCol, int endCol,
              vector<vector<int>>& ans, int& stVal) {

        int m = endRow - stRow;
        if (m == 1) {
            ans[stRow][stCol] = stVal;
            stVal++;
            return;
        }

        int midRow = stRow + m / 2;
        int midCol = stCol + m / 2;

        // Top right
        make(stRow, midRow, midCol, endCol, ans, stVal);

        // Bottom right
        make(midRow, endRow, midCol, endCol, ans, stVal);

        // Bottom Left
        make(midRow, endRow, stCol, midCol, ans, stVal);

        // Top Left
        make(stRow, midRow, stCol, midCol, ans, stVal);
    }
};