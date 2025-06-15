class Solution {
public:
    string generateTag(string c) {
        int n = c.size();
        string s = "#";

        for (int i = 0; i < n; i++) {
            if (c[i] == ' ') {
                continue;
            }

            if (i > 0 && c[i - 1] == ' ') {
                if (islower(c[i])) {
                    c[i] = toupper(c[i]);
                }
            } else {
                if (isupper(c[i])) {
                    c[i] = tolower(c[i]);
                }
            }

            s += c[i];
        }

        if (s.size() >= 2) {
            s[1] = tolower(s[1]);
        }

        return s.substr(0, 100);
    }
};
