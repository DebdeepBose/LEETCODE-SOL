class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int idx = 0;
        int n = s2.length();
        for (char c : s1) {
            if (idx < n && (s2[idx] - c + 26) % 26 <= 1) {
                idx++;
            }
        }
        return idx == n;
    }
};