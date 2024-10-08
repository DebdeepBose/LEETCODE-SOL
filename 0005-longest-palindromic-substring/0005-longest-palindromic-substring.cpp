class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string lps = "";

        for (int i = 0; i < n; i++) {
            int l = i;
            int h = i;
            while (l >= 0 && h < n && s[l] == s[h]) {
                l--;
                h++;
            }
            string pali = s.substr(l + 1, h - l - 1);
            if (pali.size() > lps.size()) {
                lps = pali;
            }

            l = i;
            h = i + 1;
            while (l >= 0 && h < n && s[l] == s[h]) {
                l--;
                h++;
            }
            pali = s.substr(l + 1, h - l - 1);
            if (pali.size() > lps.size()) {
                lps = pali;
            }
        }
        return lps;
    }
};
