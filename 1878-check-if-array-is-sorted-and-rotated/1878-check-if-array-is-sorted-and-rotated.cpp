class Solution {
public:
    bool check(vector<int>& nums) {

        // Storing the array size and initializing a varibale tp store dips
        int size = nums.size();
        int dips = 0;

        // Run a loop to check the number of dips
        for (int i = 1; i < size; i++) {
            if (nums[i - 1] > nums[i]) {
                dips++;
            }
        }

        // Accounting for edge case
        if (nums.back() > nums[0]) {
            dips++;
        }

        // Returning true if dips<=1 else false
        return dips <= 1;
    }
};