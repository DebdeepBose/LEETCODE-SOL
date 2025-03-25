class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int static_size = nums.size();
        int xor_sum = nums.size();

        for (int i = 0; i < static_size; i++) {
            xor_sum ^= nums[i]^i;
        }

        return xor_sum;
    }
};