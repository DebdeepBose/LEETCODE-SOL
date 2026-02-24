class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        int len = 0;
        for (auto& e : mp) {
            if (e.second % 2 == 0) {
                e.second = 2;
            } else {
                e.second = 1;
            }
            len += e.second;
        }

        return len;
    }
};