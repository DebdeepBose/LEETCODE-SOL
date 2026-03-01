class Solution {
public:
    string trimTrailingVowels(string s) {
        int lastConsIdx = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' &&
                s[i] != 'u') {
                lastConsIdx = i;
            }
        }
        if (lastConsIdx == -1) {
            return "";
        }
        return s.substr(0, lastConsIdx + 1);
    }
};