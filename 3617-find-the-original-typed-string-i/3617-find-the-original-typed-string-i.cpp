class Solution {
public:
    int possibleStringCount(string s) {
        int extra = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                extra++;
            }
        }
        return extra + 1;
    }
};