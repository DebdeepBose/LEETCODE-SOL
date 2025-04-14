class Solution {
public:
    bool isValidPosition(vector<string>& boardRow, int n, int RowIndex,
                         int ColumnIndex) {

        // Vertiacl check
        for (int i = RowIndex - 1; i >= 0; i--) {
            if (boardRow[i][ColumnIndex] == 'Q') {
                return false;
            }
        }

        // Left Diagonal Check
        for (int i = RowIndex - 1, j = ColumnIndex - 1; i >= 0 && j >= 0; i--, j--) {
            if (boardRow[i][j] == 'Q') {
                return false;
            }
        }

        // Right diagonal check
        for (int i = RowIndex - 1, j = ColumnIndex + 1; i >= 0 && j < n; i--, j++) {
            if (boardRow[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    // Helper Function
    void placeQueens(vector<vector<string>>& chessBoard,
                     vector<string>& boardRow, int n, int RowIndex) {

        // Base Case
        if (RowIndex == n) {

            // Adding the row to our chessboard
            chessBoard.push_back(boardRow);

            return;
        }

        for (int  ColumnIndex = 0;  ColumnIndex < n;  ColumnIndex++) {

            // If position is valid , assign a queen.
            if (isValidPosition(boardRow, n, RowIndex, ColumnIndex)) {

                boardRow[RowIndex][ ColumnIndex] = 'Q';
                placeQueens(chessBoard, boardRow, n, RowIndex + 1);

                // Remove the queen and replace with '.'
                boardRow[RowIndex][ ColumnIndex] = '.';
            }
        }
    }

    // Main Function
    vector<vector<string>> solveNQueens(int n) {

        // Final chess board that we would return
        vector<vector<string>> chessBoard;

        // Temporary strip/row for conducting operations
        vector<string> boardRow(n, string(n, '.'));

        int RowIndex = 0;

        // Calling our helper function
        placeQueens(chessBoard, boardRow, n, RowIndex);

        return chessBoard;
    }
};