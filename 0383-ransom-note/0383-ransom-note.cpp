class Solution {
public:
    bool canConstruct(string s, string r) {
        vector<char> mp(128, 0);
        for (auto e : r) {
            mp[e]++;
        }
        for (auto e : s) {
            if (mp[e] > 0) {
                mp[e]--;
            } else {
                return false;
            }
        }
        return true;
    }
};