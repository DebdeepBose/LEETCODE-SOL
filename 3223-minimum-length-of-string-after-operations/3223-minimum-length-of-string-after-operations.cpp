class Solution {
public:
    int minimumLength(string s) {
        vector<int> mp(26);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            mp[s[i] - 'a']++;
            if (mp[s[i] - 'a'] > 2) {
                mp[s[i] - 'a'] -= 2;
            }
        }
        int len = 0;
        for (int i = 0; i < 26; i++) {
            len += mp[i];
        }

        return len;
    }
};