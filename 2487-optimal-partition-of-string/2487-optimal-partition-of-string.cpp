class Solution {
public:
    int partitionString(string s) {
        int l = 0;
        int r = 0;
        unordered_map<char, int> mp;
        int n = s.length();
        int c = 0;

        while (r < n) {
            mp[s[r]]++;
            while (mp[s[r]] > 1) {
                l = r;
                mp.clear();
                mp[s[l]]++;
                c++;
            }
            r++;
        }
        if (!mp.empty()) {
            c++;
        }
        return c;
    }
};