class Solution {
public:
    string finalString(string s) {
        int i = 0;
        int n = s.size();
        string r = "";
        while (i < n) {
            if (s[i] == 'i') {
                if (i != n - 1 && s[i + 1] == 'i') {
                    i++;
                } else {
                    reverse(r.begin(), r.end());
                }
            }
            if (s[i] != 'i') {
                r += s[i];
            }
            i++;
        }
        return r;
    }
};