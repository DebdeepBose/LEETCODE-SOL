class Solution {
public:
    // Function to find all unique triplets that sum up to 0
    void findTriplets(vector<int>& nums, int size,
                      vector<vector<int>>& allTriplets) {  // Passed by reference to store results

        for (int i = 0; i < size - 2; i++) {  // Loop through each element until the third last
            if (nums[i] >= 1) {
                // Since the array is sorted, if current number > 0, all further elements will also be > 0.
                // Hence no triplet can sum to 0 from this point.
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                // Skip duplicate elements to avoid repeating the same triplet starting number
                continue;
            }

            int j = i + 1;         // Start of the second pointer
            int k = size - 1;      // Start of the third pointer

            while (j < k) {        // Two-pointer approach to find the remaining two elements
                int tripletSum = nums[i] + nums[j] + nums[k];  // Sum of the current triplet

                if (tripletSum == 0) {
                    // Valid triplet found
                    allTriplets.push_back({nums[i], nums[j], nums[k]});

                    // Move j forward while next element is the same to skip duplicates
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }

                    // Move k backward while previous element is the same to skip duplicates
                    while (j < k && nums[k] == nums[k - 1]) {
                        k--;
                    }

                    j++;  // Move j forward after processing this valid triplet
                    k--;  // Move k backward after processing this valid triplet
                }
                else if (tripletSum > 0) {
                    // If sum is too large, decrease it by moving k to the left
                    k--;
                }
                else {
                    // If sum is too small, increase it by moving j to the right
                    j++;
                }
            }
        }
    }

    // Main function called to solve the problem
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();  // Store array size

        if (size < 3) {
            // If less than 3 elements, we cannot form any triplet
            return {{}};
        }

        sort(nums.begin(), nums.end());  // Sort the array to apply two-pointer method

        vector<vector<int>> allTriplets;  // Vector to store all unique valid triplets

        findTriplets(nums, size, allTriplets);  //Pass to helper function

        return allTriplets;  // Return result to the caller
    }
};
