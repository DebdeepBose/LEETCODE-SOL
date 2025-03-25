class Solution {
public:
    int missingNumber(vector<int>& nums) {

        //Storing the size into a static varibale
        int static_size = nums.size();

        // Initializing xor_sum with n since it's the missing number's expected XOR pair
        int xor_sum = static_size;

        // XOR all indices and array elements; matching pairs cancel out, leaving only the missing number
        for (int i = 0; i < static_size; i++) {
            xor_sum ^= nums[i] ^ i;
        }

        // The remaining value in xor_sum is the missing number
        return xor_sum;
    }
};