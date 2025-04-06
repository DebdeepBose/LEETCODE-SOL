class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Handle empty matrix edge case
        if (matrix.empty()) {
            return {};
        }

        // Number of rows
        int rows = matrix.size();            

        // Number of columns
        int columns = matrix[0].size();      

        // Vector to store elements in spiral order
        vector<int> spiral_result;           

        // 4 pointers for top, bottom, right and left positions
        int top = 0;
        int bottom = rows - 1;
        int left = 0;
        int right = columns - 1;

        // Continue looping until all boundaries collapse
        while (left <= right && top <= bottom) {

            // Traverse from left to right on the top row
            for (int i = left; i <= right; i++) {
                spiral_result.push_back(matrix[top][i]);
            }

            // Move the top boundary down since the top row has been traversed
            top++;

            // Traverse from top to bottom on the right column
            for (int i = top; i <= bottom; i++) {
                spiral_result.push_back(matrix[i][right]);
            }

            // Move the right boundary left since the right column has been traversed
            right--;

            // Traverse from right to left on the bottom row, if still in bounds
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    spiral_result.push_back(matrix[bottom][i]);
                }

                // Move the bottom boundary up since the bottom row has been traversed
                bottom--;
            }

            // Traverse from bottom to top on the left column, if still in bounds
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    spiral_result.push_back(matrix[i][left]);
                }

                // Move the left boundary right since the left column has been traversed
                left++;
            }
        }

        return spiral_result;
    }
};
