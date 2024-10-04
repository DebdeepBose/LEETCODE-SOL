class Solution {
public:
    int maxVowels(string s, int k) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int maxv = 0;
        vector<int> mp(26, 0);
        while (r < n) {
            mp[s[r] - 'a']++;
            if (r - l + 1 == k) {
                int v = mp['a' - 'a'] + mp['e' - 'a'] + mp['i' - 'a'] +
                        mp['o' - 'a'] + mp['u' - 'a'];
                maxv = max(maxv, v);
                mp[s[l] - 'a']--;
                l++;
            }
            r++;
        }
        return maxv;
    }
};
