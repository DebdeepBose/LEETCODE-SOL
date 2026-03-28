class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        // My Approach :
        /*
           Sort All Rows, then take a max heap, now we run a while loop until
           rowSize becomes 0. For each row push the last element of the sorted
           row into the priority queue. After that add the top element of the
           priority_queue to the final score. Make sure to empty the queue
           before the next cycle.
        */

        int rowSize = nums[0].size();
        int score = 0;

        for (auto& row : nums) {
            sort(row.begin(), row.end());
        }

        priority_queue<int> rowMax;

        while (rowSize--) {
            for (auto& row : nums) {
                rowMax.push(row.back());
                row.pop_back();
            }
            score += rowMax.top();
            while (!rowMax.empty()) {
                rowMax.pop();
            }
        }
        return score;
    }
};