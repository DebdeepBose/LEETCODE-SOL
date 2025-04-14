class Solution {
public:
    bool isValid(vector<string>& b, int row, int col, int n) {
        for (int i = row - 1; i >= 0; i--) {
            if (b[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (b[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (b[i][j] == 'Q') return false;
        }
        return true;
    }

    void findQ(int n, vector<vector<string>>& ans, vector<string>& b, int row) {
        if (row == n) {
            ans.push_back(b);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(b, row, col, n)) {
                b[row][col] = 'Q';
                findQ(n, ans, b, row + 1);
                b[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> b(n, string(n, '.'));
        findQ(n, ans, b, 0);
        return ans;
    }
};
