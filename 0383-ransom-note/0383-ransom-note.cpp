class Solution {
public:
    bool canConstruct(string s, string r) {
        unordered_map<char, int> mp;
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