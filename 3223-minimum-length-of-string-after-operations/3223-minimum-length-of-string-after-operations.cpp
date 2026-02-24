class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
            if (mp[s[i]] > 2) {
                mp[s[i]] -= 2;
            }
        }
        int len = 0;
        for (auto& e : mp) {
            len += e.second;
        }

        return len;
    }
};