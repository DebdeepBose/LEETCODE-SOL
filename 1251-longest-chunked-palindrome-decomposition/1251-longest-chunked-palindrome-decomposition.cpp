class Solution {
public:
    int longestDecomposition(string s) {
        int c = 0;
        int n = s.size();
        string l = "";
        string r = "";
        for (int i = 0; i < n; i++) {
            l += s[i];
            r = s[n - i - 1] + r;
            if (l == r) {
                c++;
                l = "";
                r = "";
            }
        }
        return c;
    }
};