class Solution {
public:
    int findMaxLength(vector<int>& v) {
        int n = v.size();
        int sum = 0;
        int maxLen = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) {
                sum--;
            } else {
                sum++;
            }
            if (sum == 0) {
                maxLen = i + 1;
            }
            if (mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};