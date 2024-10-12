class Solution {
public:
    string restoreString(string s, vector<int>& v) {
        int n = s.size();
        unordered_map<int, char> mp;
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
