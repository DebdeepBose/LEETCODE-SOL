class Solution {
public:
    bool validQueenPosition(int n, vector<string>& chessRow, int row, int col) {
        // Check vertical column ↑
        for (int i = row - 1; i >= 0; i--) {
            if (chessRow[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal ↖
        int i = row - 1, j = col - 1;
        while (i >= 0 && j >= 0) {
            if (chessRow[i][j] == 'Q') {
                return false;
            }
            i--; j--;
        }

        // Check upper-right diagonal ↗
        i = row - 1, j = col + 1;
        while (i >= 0 && j < n) {
            if (chessRow[i][j] == 'Q') {
                return false;
            }
            i--; j++;
        }

        return true;
    }

    void placeQueens(int n, vector<string>& chessRow,
                     vector<vector<string>>& chessBoard, int row) {
        if (row >= n) {
            chessBoard.push_back(chessRow);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (validQueenPosition(n, chessRow, row, col)) {
                chessRow[row][col] = 'Q';
                placeQueens(n, chessRow, chessBoard, row + 1);
                chessRow[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessRow(n, string(n, '.'));
        vector<vector<string>> chessBoard;
        placeQueens(n, chessRow, chessBoard, 0);
        return chessBoard;
    }
};
