class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        if (n < 10) {
            return {};
        }
        unordered_map<string, int> mp;
        set<string> st;
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
                st.insert(e.first);
            }
        }
        vector<string> v(st.begin(), st.end());
        return v;
    }
};