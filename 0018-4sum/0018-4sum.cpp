class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;

        // Sort the array to easily skip duplicates and apply two-pointer technique
        sort(nums.begin(), nums.end());
        int size = nums.size();

        for (int i = 0; i < size - 3; i++) {
            // Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < size - 2; j++) {
                // Skip duplicate elements for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = size - 1;

                while (left < right) {
                    // Use 1LL to convert the entire sum to long long to avoid integer overflow
                    long long currentSum = 1LL * nums[i] + nums[j] + nums[left] + nums[right];

                    if (currentSum == target) {
                        // Found a valid quadruplet
                        quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for the third number
                        while (left < right && nums[left] == nums[left + 1]) left++;

                        // Skip duplicates for the fourth number
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        // Move pointers inward
                        left++;
                        right--;
                    } else if (currentSum > target) {
                        // Try smaller sum by moving right pointer to the left
                        right--;
                    } else {
                        // Try larger sum by moving left pointer to the right
                        left++;
                    }
                }
            }
        }

        return quadruplets;
    }
};
