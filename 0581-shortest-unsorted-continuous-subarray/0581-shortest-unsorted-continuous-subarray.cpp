class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1, end = -1;
        int maxSeen = INT_MIN, minSeen = INT_MAX;

        for (int i = 0; i < n; i++) {
            maxSeen = max(maxSeen, nums[i]);
            if (nums[i] < maxSeen) {
                end = i;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            minSeen = min(minSeen, nums[i]);
            if (nums[i] > minSeen) {
                start = i;
            }
        }

        if (start == -1) {
            return 0;
        }

        return end - start + 1;
    }
};
