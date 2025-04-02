class Solution {
public:
    int missingNumber(vector<int>& v) {
        int n = v.size();
        
        // Initialize 'x' with 'n' (since numbers range from 0 to n)
        int x = n;  
        
        // XOR all elements in 'v' and their indices
        for (int i = 0; i < n; i++) {
            x ^= v[i] ^ i;  
        }
        
        // XOR with 'n' again to cancel out the extra term introduced earlier
        return x;
    }
};
