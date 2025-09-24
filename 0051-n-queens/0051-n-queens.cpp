class Solution {
public:
    bool isSafe(vector<string>& tmp, int row, int col, int n) {
        // Horizontal check (row fixed, scan columns)
        for (int i = 0; i < n; i++) {
            if (tmp[row][i] == 'Q') {
                return false;
            }
        }

        // Vertical check (col fixed, scan rows)
        for (int j = 0; j < n; j++) {
            if (tmp[j][col] == 'Q') {
                return false;
            }
        }

        // Top-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (tmp[i][j] == 'Q') {
                return false;
            }
        }

        // Top-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (tmp[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void nqueen(int n, vector<vector<string>>& ans, vector<string>& tmp, int row) {
        if (row == n) {
            ans.push_back(tmp);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(tmp, row, col, n)) {
                tmp[row][col] = 'Q';
                nqueen(n, ans, tmp, row + 1);
                tmp[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n == 1) {
            return {{"Q"}};
        }
        if (n < 4) {
            return {};
        }

        vector<vector<string>> ans;
        vector<string> tmp(n, string(n, '.'));

        nqueen(n, ans, tmp, 0);
        return ans;
    }
};
