class Solution {
public:
    bool canConstruct(string s, string r) {
        if (s.length() > r.length()) {
            return false;
        }
        vector<int> mp(26, 0);
        for (auto e : r) {
            mp[e - 'a']++;
        }
        for (auto e : s) {
            if (mp[e - 'a'] > 0) {
                mp[e - 'a']--;
            } else {
                return false;
            }
        }
        return true;
    }
};