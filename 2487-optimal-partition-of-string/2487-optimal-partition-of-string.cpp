class Solution {
public:
    int partitionString(string s) {
        int l = 0;
        int r = 0;
        vector<int> mp(26, 0);
        int n = s.length();
        int c = 0;

        while (r < n) {
            mp[s[r] - 'a']++;
            while (mp[s[r] - 'a'] > 1) {
                l = r;
                mp.assign(26, 0);
                mp[s[l] - 'a']++;
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
