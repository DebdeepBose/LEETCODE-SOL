class Solution {
public:
    string restoreString(string s, vector<int>& v) {
        int n = s.size();
        vector<char> mp(n);
        for (int i = 0; i < n; i++) {
            mp[v[i]] = s[i];
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            ans += mp[i];
        }
        return ans;
    }
};
