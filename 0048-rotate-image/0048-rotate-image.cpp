class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // rows -> number of rows
        int rows = matrix.size();

        // columns -> number of columns
        int columns = matrix[0].size();

        // Aim to find the transpose of the matrix
        for (int i = 0; i < rows; i++) {
            for (int j = i + 1; j < columns; j++) {
                // We can simply swap the numbers
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Finally reverse each of the inner array to get the rotated matrix
        for (int i = 0; i < rows; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
