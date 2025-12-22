class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_map<string, int> mp;
        for (int i = 0; i < s.size() - 1; i++) {
            mp[s.substr(i, 2)]++;
        }
        for (int i = s.size() - 1; i >= 1; i--) {
            string t = "";
            t += s[i];
            t += s[i - 1];
            if (mp.count(t)) {
                return true;
            }
        }

        return false;
    }
};