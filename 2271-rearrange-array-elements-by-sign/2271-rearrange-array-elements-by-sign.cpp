class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        // Storing length of the array
        int len = nums.size();

        // Initializing result vector with the same size
        vector<int> ans(len);

        // Initializing pointers: even index for positive numbers, odd index for negative numbers
        int positive_ptr = 0;
        int negative_ptr = 1;

        for (int i = 0; i < len; i++) {
            if (nums[i] > 0) {
                ans[positive_ptr] = nums[i];

                // Move to the next available even index
                positive_ptr += 2; 
            } else {
                ans[negative_ptr] = nums[i];

                // Move to the next available odd index
                negative_ptr += 2; 
            }
        }
        return ans;
    }
};