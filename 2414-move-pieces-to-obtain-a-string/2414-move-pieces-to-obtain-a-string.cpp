class Solution {
public:
    bool canChange(string s, string t) {
        int n = t.size();
        int i = 0, j = 0;
        while (i <= n && j <= n) {
            while (i < n && t[i] == '_') {
                i++;
            }
            while (j < n && s[j] == '_') {
                j++;
            }
            if (i == n || j == n) {
                return i == n && j == n;
            }

            if (t[i] != s[j])
                return false;

            if (t[i] == 'L') {
                if (j < i)
                    return false;
            } else {
                if (i < j)
                    return false;
            }

            i++;
            j++;
        }
        return true;
    }
};