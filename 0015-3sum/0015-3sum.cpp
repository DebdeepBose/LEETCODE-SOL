class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Size of the input array
        int size = nums.size();

        // Final result to store all unique triplets with sum = 0
        vector<vector<int>> triplets;

        // Sort the array to use two-pointer approach and handle duplicates
        sort(nums.begin(), nums.end());

        // Iterate through each number as potential first element of triplet
        for (int i = 0; i < size - 2; i++) {

            // Optimization: since array is sorted, if current number > 0, no triplet can sum to 0
            if (nums[i] > 0) {
                break;
            }

            // Skip duplicate elements for the first element of the triplet
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Two-pointer setup for remaining two elements
            int j = i + 1;
            int k = size - 1;

            // Search for valid pairs whose sum with nums[i] == 0
            while (j < k) {
                int currentSum = nums[i] + nums[j] + nums[k];

                if (currentSum == 0) {
                    // Found a valid triplet
                    triplets.push_back({nums[i], nums[j], nums[k]});

                    // Skip duplicate elements for the second number
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }

                    // Skip duplicate elements for the third number
                    while (j < k && nums[k] == nums[k - 1]) {
                        k--;
                    }

                    // Move both pointers after recording triplet
                    j++;
                    k--;
                } 
                else if (currentSum > 0) {
                    // Sum too high, decrease largest element
                    k--;
                } 
                else {
                    // Sum too low, increase smallest element
                    j++;
                }
            }
        }

        return triplets;
    }
};
