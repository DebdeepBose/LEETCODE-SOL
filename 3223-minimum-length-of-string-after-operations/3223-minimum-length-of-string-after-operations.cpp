class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        for (auto& e : mp) {
            while (e.second > 2) {
                e.second -= 2;
            }
        }
        int len = 0;
        for (auto& e : mp) {
            len += e.second;
        }
        return len;
    }
};