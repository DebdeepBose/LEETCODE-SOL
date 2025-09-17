class Solution {
public:
    bool buddyStrings(string s, string g) {
        int c = 0;
        int n = s.size();
        int m = g.size();
        if (n != m) {
            return false;
        }
        if (s == g) {
            sort(s.begin(), s.end());
            for (int i = 0; i < s.size() - 1; i++) {
                if (s[i] == s[i + 1]) {
                    return true;
                }
            }
            return false;
        }
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != g[i]) {
                c++;
            }
            mp[s[i]]++;
        }
        for (auto e : g) {
            mp[e]--;
            if (mp[e] == 0) {
                mp.erase(e);
            }
        }

        return c <= 2 && mp.empty();
    }
};