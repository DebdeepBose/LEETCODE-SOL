class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // Length of the array
        int length = nums.size();

        // Initiallising 'j' at index 0;
        int j = 0;

        // Running a loop and swapping whenever conditions are met
        for (int i = 0; i < length; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);

                // Incrementing after swapping
                j++;
            }
        }

        // Nothing to return since its Void
    }
};