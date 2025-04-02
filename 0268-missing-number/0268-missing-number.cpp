class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        
        // Initialize 'missing' with 'size' (since numbers range from 0 to size)
        int missing = size;  
        
        // XOR all elements in 'nums' and their indices
        for (int i = 0; i < size; i++) {
            missing ^= nums[i] ^ i;  
        }
        
        // Return the missing number
        return missing;
    }
};
