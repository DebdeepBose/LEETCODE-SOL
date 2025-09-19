class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        int columnSize = matrix[0].size();

        int rowIndex = 0;
        int columnIndex = columnSize - 1;

        while (rowIndex < rowSize && columnIndex >= 0) {
            if (matrix[rowIndex][columnIndex] == target) {
                return true;
            } else if (matrix[rowIndex][columnIndex] > target) {
                columnIndex--;
            } else {
                rowIndex++;
            }
        }
        return false;
    }
};