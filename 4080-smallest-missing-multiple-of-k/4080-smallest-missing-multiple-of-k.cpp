class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int mul = 1;
        while (true) {
            int cur = k * mul;
            auto idx = lower_bound(nums.begin(), nums.end(), cur);
            if (idx == nums.end() || *idx != cur) {
                return cur;
            }
            mul++;
        }
        return -1;
    }
};