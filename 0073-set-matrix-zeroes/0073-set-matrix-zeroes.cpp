class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Flags to check if first row and first column should be zeroed
        bool first_row = false;
        bool first_column = false;

        int rows = matrix.size();
        int columns = matrix[0].size();

        // First pass to mark rows and columns
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) first_row = true;
                    if (j == 0) first_column = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Second pass to set zeroes using markers (excluding first row and column)
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < columns; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // If first row had any zero, set entire first row to 0
        if (first_row) {
            for (int j = 0; j < columns; j++) {
                matrix[0][j] = 0;
            }
        }

        // If first column had any zero, set entire first column to 0
        if (first_column) {
            for (int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
