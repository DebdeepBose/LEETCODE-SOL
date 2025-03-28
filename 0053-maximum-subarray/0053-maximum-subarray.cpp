class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Using Kadane's Algorithm to find the maximum subarray sum

        int size = nums.size();
        int sum = 0;               // Current subarray sum
        int maximum_sum = INT_MIN; // Maximum subarray sum found so far

        for (int i = 0; i < size; i++) {
            sum += nums[i];                     // Add current element to subarray sum
            maximum_sum = max(maximum_sum, sum); // Update max sum if current sum is greater
            if (sum < 0) sum = 0;               // Reset subarray sum if it becomes negative
        }

        return maximum_sum; // Return the maximum subarray sum
    }
};
