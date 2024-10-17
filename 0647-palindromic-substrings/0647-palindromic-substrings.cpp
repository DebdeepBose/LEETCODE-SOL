class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int sub = 0;
        for (int i = 0; i < n; i++) {
            int l = i;
            int h = i;
            while (l >= 0 && h < n && s[l] == s[h]) {
                sub++;
                l--;
                h++;
            }
            l = i;
            h = i + 1;
            while (l >= 0 && h < n && s[l] == s[h]) {
                sub++;
                l--;
                h++;
            }
        }
        return sub;
    }
};
