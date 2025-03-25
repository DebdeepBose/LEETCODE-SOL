class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Get the size of the array
        int size = nums.size();

        // Variable to store the XOR result (initialized to 0)
        int xor_leftout = 0;

        // XOR all elements in the array
        for (int i = 0; i < size; i++) {
            xor_leftout ^= nums[i];  
            // Since x ^ x = 0 and x ^ 0 = x, all duplicate numbers cancel out, leaving only the unique number
        }

        // The remaining value is the single non-repeating number
        return xor_leftout;
    }
};
