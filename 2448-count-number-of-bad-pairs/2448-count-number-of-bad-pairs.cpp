class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // Total number of index pairs (i, j) such that 0 <= i < j < n
        long long badPairs = (nums.size() * (nums.size() - 1)) / 2;

        // HashMap to store the frequency of (i - nums[i]) values
        unordered_map<long long, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            /*
              Good pair condition: nums[j] - j == nums[i] - i ⇒ j - nums[j] == i - nums[i]
              So we store (i - nums[i]) and count how many times it has occurred so far.
              For every match found, we subtract the number of good pairs from the total pairs
              to get the number of bad pairs.
            */
            long long key = i - nums[i];
            if (freq.count(key)) {
                // Subtract the count of good pairs formed with this key
                badPairs -= freq[key];
            }

            // Update the frequency of the current key
            freq[key]++;
        }

        return badPairs;
    }
};
