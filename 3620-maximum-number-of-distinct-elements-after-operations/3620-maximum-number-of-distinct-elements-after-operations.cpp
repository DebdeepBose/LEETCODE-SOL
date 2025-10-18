class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {

        int n = nums.size();

        if (n == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int ans = 0;
        int prev = INT_MIN;

        for (int i = 0; i < n; i++) {
            int last = max(nums[i] - k, prev + 1);
            if (last <= nums[i] + k) {
                prev = last;
                ans++;
            }
        }
        return ans;
    }
};