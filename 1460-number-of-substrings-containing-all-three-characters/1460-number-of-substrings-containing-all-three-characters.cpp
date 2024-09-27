class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int subs = 0;
        int n = size(s);
        unordered_map<char, int> mp;

        while (r < n) {
            mp[s[r]]++;
            while (mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1) {
                subs += (n - r);
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return subs;
    }
};