class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            int evenCount = 0;
            int oddCount = 0;
            for (int j = i; j < n; j++) {
                int val = nums[j];
                if (mp[val] == 0) {
                    if (val % 2 == 0) {
                        evenCount++;
                    } else
                        oddCount++;
                }
                mp[val]++;
                if (evenCount == oddCount) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};
