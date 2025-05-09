class Solution {
public:
    void findTriplets(vector<int>& nums, int size,
                      vector<vector<int>> &allTriplets) {

        for (int i = 0; i < size - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = size - 1;

            while (j < k) {
                int tripletSum = nums[i] + nums[j] + nums[k];

                if (tripletSum == 0) {
                    allTriplets.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    j++;
                    k--;
                } else if (tripletSum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {

        int size = nums.size();

        if (size < 3) {
            return {{}};
        }

        sort(nums.begin(), nums.end());

        vector<vector<int>> allTriplets;

        findTriplets(nums, size, allTriplets);

        return allTriplets;
    }
};