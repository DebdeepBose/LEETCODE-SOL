class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {

        int rowSize = nums[0].size();
        int score = 0;

        priority_queue<int> rowMax;
        for (auto& row : nums) {
            sort(row.begin(), row.end());
        }
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