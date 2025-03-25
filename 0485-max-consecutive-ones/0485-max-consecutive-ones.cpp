class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // Get the size of the array
        int size = nums.size();

        // Variables to track the current count of consecutive 1s and the maximum found
        int one_count = 0;  
        int max_one_count = 0;

        // Iterate through the array
        for (int i = 0; i < size; i++) {

            if (nums[i] == 1) {

                // If we find a 1, increment the current count
                one_count++;

                // Update the maximum consecutive 1s count
                max_one_count = max(max_one_count, one_count);

            } else {

                // If we encounter a 0, reset the current count
                one_count = 0;
                
            }
        }
        
        // Return the maximum count of consecutive 1s
        return max_one_count;
    }
};
