class Solution {
public:
    string addSpaces(string s, vector<int>& v) {
        string ans;
        int idx = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (idx < v.size() && i == v[idx]) {
                ans += ' ';
                idx++;
            }
            ans += s[i];
        }
        return ans;
    }
};