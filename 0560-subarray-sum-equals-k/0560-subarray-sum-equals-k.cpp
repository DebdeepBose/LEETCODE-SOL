class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // Stores frequency of prefix sums
        unordered_map<int, int> prefixSumFreq; 

        int n = nums.size();

        // Setting it as a reference if excludeFromTarget = 0
        prefixSumFreq[0] = 1; 

        // Keeps track of the prefix sum
        int prefixSum = 0;      

        // Number of subarrays with sum equal to k
        int subarray_count = 0; 

        for (int i = 0; i < n; i++) {
            // Add the current element to the running prefix sum
            prefixSum += nums[i];

            // Calculate the required prefix sum that would have led to a
            // subarray summing to k
            int excludeFromTarget = prefixSum - k;

            // If this required prefix sum has occurred before, add its
            // frequency to the count (each occurrence represents a valid
            // subarray ending at index i)
            subarray_count += prefixSumFreq[excludeFromTarget];

            // Record the current prefix sum in the map for future subarrays
            prefixSumFreq[prefixSum]++;
        }

        return subarray_count;
    }
};
