class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
                continue;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};