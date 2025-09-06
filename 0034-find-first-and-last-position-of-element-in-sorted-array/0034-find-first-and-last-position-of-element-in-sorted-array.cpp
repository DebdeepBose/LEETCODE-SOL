class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};  // handle empty array

        auto lb = lower_bound(nums.begin(), nums.end(), target);
        auto ub = upper_bound(nums.begin(), nums.end(), target);

        // Target not found
        if (lb == nums.end() || *lb != target) {
            return {-1, -1};
        }

        int start = lb - nums.begin();
        int end = ub - nums.begin() - 1;

        return {start, end};
    }
};
