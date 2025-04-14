class Solution {
public:
    bool isValid(vector<string>& b, int row, int col) {
        for (int i = row - 1; i >= 0; i--) {
            if (b[i][col] == 'Q')
                return false;
        }

        int i = row - 1;
        int j = col - 1;
        while (i >= 0 && j >= 0) {
            if (b[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        i = row - 1;
        j = col + 1;
        while (i >= 0 && j < b.size()) {
            if (b[i][j] == 'Q')
                return false;
            i--;
            j++;
        }

        return true;
    }

    void findQ(vector<vector<string>>& ans, vector<string>& b, int row) {
        if (row == b.size()) {
            ans.push_back(b);
            return;
        }

        int n = b.size();
        for (int col = 0; col < n; col++) {
            if (isValid(b, row, col)) {
                b[row][col] = 'Q';
                findQ(ans, b, row + 1);
                b[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> b(n, string(n, '.'));
        findQ(ans, b, 0);
        return ans;
    }
};
