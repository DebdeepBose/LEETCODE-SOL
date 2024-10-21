class Solution {
public:
    bool checkValidString(string s) {
        int pmin = 0, pmax = 0;
        for (char c : s) {
            if (c == '(') {
                pmax++;
                pmin++;
            } else if (c == ')') {
                pmax--;
                pmin--;
            } else if (c == '*') {
                pmax++;
                pmin--;
            }
            if (pmax < 0) {
                return false;
            }
            pmin = max(pmin, 0);
        }
        return pmin == 0;
    }
};
