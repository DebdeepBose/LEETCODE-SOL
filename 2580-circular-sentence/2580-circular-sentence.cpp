class Solution {
public:
    bool isCircularSentence(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (isspace(s[i])) {
                if (s[i - 1] != s[i + 1]) {
                    return false;
                }
            }
        }
        return s[0] == s.back();
    }
};