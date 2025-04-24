class Solution {
public:
    int countNicePairs(vector<int>& v) {
        unordered_map<int, int> mp; // To store frequency of nums[i] - rev(nums[i])
        int n = v.size();
        long long c = 0; // To count number of nice pairs
        int MOD = 1e9 + 7; // Modulo value to avoid overflow
        
        for (int i = 0; i < n; i++) {
            // Convert the number to string and reverse it to get the reversed number
            string s = to_string(v[i]);
            reverse(s.begin(), s.end());
            int rev = stoi(s);
            
            // Calculate the difference between original number and its reversed version
            int diff = v[i] - rev;

            // If we've already seen this difference before, it can form nice pairs
            // Add the frequency of this difference to the count
            c = (c + mp[diff]) % MOD;

            // Increment the frequency of this difference for future matches
            mp[diff]++;
        }

        // Return the total number of nice pairs found, modulo 1e9+7
        return c;
    }
};
