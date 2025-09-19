class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int rowSize = mat.size();
        int columnSize = mat[0].size();

        /* Aight so we will be applying a weird algo to solve this, look
        instead of checking every element we will choose one column, yes a
        column aka vertical, and within that column we gonna try and find out
        the max element what happens next, we'll see later*/

        int low = 0;
        int high =
            columnSize - 1; // Yeah cuz we checking which column to search in

        while (low <= high) {
            int mid = low + (high - low) / 2;
            /*So now mid gives us the index of the column we will be
               seacrhing our max element in */

            int maxElement = INT_MIN;
            int maxElementIndex = -1;

            // Since we going down the column so we use rowSize cuz its
            // vertical
            for (int i = 0; i < rowSize; i++) {
                if (mat[i][mid] > maxElement) {
                    maxElement = mat[i][mid];

                    // Yeah by index we mean rowNumber
                    maxElementIndex = i;
                }
            }

            /* Now we check if it has a left or right, if it does we store it
             * cuz undertsand this we already found the max element in the
             * vertical mannaer aka column wise so there is no point in checking
             * the top and bottom neighbor cuz the current one is maximum so it
             * kinda reduces to a horizontal array check, so we store our
             * left/right, also if it doesnt exist we just store -1 */

            int midLeft, midRight;

            if (mid - 1 >= 0) {
                midLeft = mat[maxElementIndex][mid - 1];
            } else {
                midLeft = -1;
            }

            if (mid + 1 < columnSize) {
                midRight = mat[maxElementIndex][mid + 1];
            } else {
                midRight = -1;
            }

            /* Now we check if the current middle element is larger than its
             * right and left neighbour using standard BS, if it IS then we
             * return {maxElementIndex,mid} cuz thats our row and column */
            if (mat[maxElementIndex][mid] > midLeft &&
                mat[maxElementIndex][mid] > midRight) {
                return {maxElementIndex, mid};
            }
            /*Yeah so if someone on their left is greater so there is no point
               in checking the right side so we do high = mid - 1, else low =
               mid + 1*/
            else if (mat[maxElementIndex][mid] < midLeft) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return {-1, -1}; // Dummy Line
    }
};