class Solution {
public:
    string answerString(string s, int n) {
        if (n == 1) {
            return s;
        }
        int len = s.size();
        int fin = len - n + 1;
        string r = "";
        for (int i = 0; i < len; i++) {
            r = max(r, s.substr(i, fin));
        }
        return r;
    }
};