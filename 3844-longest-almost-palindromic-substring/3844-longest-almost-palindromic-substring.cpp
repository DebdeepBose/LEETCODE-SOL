class Solution {
private:
    int getPalindromeLen(string &s, int l, int r, bool skip) {
        int n = s.length();

        if (l < 0 && r >= n) 
            return 0;

        // one edge crossed
        if (l < 0 || r >= n) 
            return skip ? 1 : 0;

        if (s[l] == s[r]) {
            int matchCount = (l == r) ? 1 : 2;
            return matchCount + getPalindromeLen(s, l - 1, r + 1, skip);
        }

        if (skip) {
            return 1 + max(
                getPalindromeLen(s, l - 1, r, false),
                getPalindromeLen(s, l, r + 1, false)
            );
        }

        return 0;
    }

public:
    int almostPalindromic(string s) {
        int res = 2;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            res = max(res, getPalindromeLen(s, i, i, true));     // odd length
            res = max(res, getPalindromeLen(s, i, i + 1, true)); // even length
        }

        return res;
    }
};