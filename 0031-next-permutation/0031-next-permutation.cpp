class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakPoint = -1;

        // Step 1: Find the rightmost index where nums[i] < nums[i + 1]
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                breakPoint = i;
                break;
            }
        }

        // If no such index is found, reverse the entire array
        if (breakPoint == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the smallest number greater than nums[breakPoint] from the right side
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[breakPoint]) {
                swap(nums[i], nums[breakPoint]);
                break;
            }
        }

        // Step 3: Reverse the portion after the breakPoint index 
        reverse(nums.begin() + breakPoint + 1, nums.end());
    }
};
