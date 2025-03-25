class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int size = nums.size();
        int one_count = 0;
        int max_one_count = 0;

        for (int i = 0; i < size; i++) {
            if (nums[i] == 1) {
                one_count++;
                max_one_count = max(max_one_count, one_count);
            } else {
                one_count = 0;
            }
        }
        return max_one_count;
    }
};