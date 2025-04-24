class Solution {
public:
    int subarraysDivByK(vector<int>& v, int k) {
        int n = v.size();
        unordered_map<int, int> freq;
        freq[0] = 1; // To count subarrays that directly sum to a multiple of k
        int sum = 0, c = 0;

        for (int i = 0; i < n; i++) {
            sum += v[i];  // Add the current element to the sum
            int mod = (sum % k + k) % k;  // Ensure the mod is always non-negative
            c += freq[mod];  // If the same mod value has appeared before, it means we found a valid subarray
            freq[mod]++;  // Increment the count of this mod value
        }

        return c;
    }
};
