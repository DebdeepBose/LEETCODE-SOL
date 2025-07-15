class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n < 3) {
            return false;
        } else {
            int v = 0, co = 0;
            for (int i = 0; i < s.size(); i++) {
                if (!isalnum(s[i])) {
                    return false;
                } else {
                    s[i] = tolower(s[i]);
                    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                        s[i] == 'o' || s[i] == 'u') {
                        v++;
                    } else {
                        if (!isdigit(s[i])) {
                            co++;
                        }
                    }
                }
            }
            if (co == 0 || v == 0) {
                return false;
            }
        }
        return true;
    }
};