class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        /*
         Alright so here is the optimal approach that i like had to rack my
         brains for even tho i did it previously*/

        /*
         This problem involves us to imagine a 2D matrix flattened to a 1D
         array and then apply binary search to it. Naturally [0,0] would be
         low and m*n-1 would be high.*/

        int rowSize = matrix.size();
        int columnSize = matrix[0].size();

        int low = 0;
        int high = columnSize * rowSize - 1; // Cuz index is 1 less than size

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Now whether to use % or / is purely based of observation
            int columnIndex = mid % columnSize;
            int rowIndex = mid / columnSize;

            // Standard BS
            if (matrix[rowIndex][columnIndex] == target) {
                return true;
            } else if (matrix[rowIndex][columnIndex] > target) {
                high = mid - 1;

            } else {
                low = mid + 1;
            }
        }

        return false;
    }
};