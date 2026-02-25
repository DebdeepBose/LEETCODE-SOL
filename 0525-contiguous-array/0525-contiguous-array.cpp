class Solution {
public:
    int findMaxLength(vector<int>& v) {
        int n = v.size();
        int sum = 0;
        int maxLen = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            !v[i] ? sum++ : sum--;
            maxLen = !sum ? i + 1 : maxLen;
            (mp.find(sum) != mp.end()) ? maxLen = max(maxLen, i - mp[sum]) : mp[sum] = i;
        }
        return maxLen;
    }
};