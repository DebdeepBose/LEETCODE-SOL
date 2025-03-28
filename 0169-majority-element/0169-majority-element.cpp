class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Using Moore's Voting Algorithm to find the majority element

        int size = nums.size();

        // Step 1: Initialize candidate and count
        int current_candidate = 0;
        int count = 0;

        // Step 2: Iterate through the array to find the potential majority element
        for (int i = 0; i < size; i++) {
            if (count == 0) {  // If count is 0, set a new candidate
                current_candidate = nums[i];
            }
            if (nums[i] == current_candidate) {
                count++;  // Increment count if it's the candidate
            } else {
                count--;  // Decrement count if it's a different number
            }
        }

        // Step 3: The final candidate is the majority element
        return current_candidate;
    }
};
