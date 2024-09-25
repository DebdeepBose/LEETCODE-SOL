class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int l = 0;
        int r = 0;
        int maxlen = 0;
        while (r < n) {
            if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                l = mp[s[r]] + 1;
            }
            mp[s[r]] = r;
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};