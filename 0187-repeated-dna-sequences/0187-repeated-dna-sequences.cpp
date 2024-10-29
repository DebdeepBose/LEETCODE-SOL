class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        if (n < 10) {
            return {};
        }
        unordered_map<string, int> mp;
        vector<string> v;
        int l = 0;
        int r = 10;
        while (r <= n) {
            string sub = s.substr(l, r - l);
            mp[sub]++;
            l++;
            r++;
        }
        for (auto e : mp) {
            if (e.second > 1) {
                v.emplace_back(e.first);
            }
        }
        return v;
    }
};