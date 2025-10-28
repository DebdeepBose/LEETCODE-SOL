class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int n = nums.size();

        int num_i = INT_MAX;
        int num_j = INT_MAX;

        for (int k = 0; k < n; k++) {
            if (nums[k] <= num_i) {
                num_i = nums[k];
            } else if (nums[k] <= num_j) {
                num_j = nums[k];
            } else {
                return true;
            }
        }
        return false;
    }
};