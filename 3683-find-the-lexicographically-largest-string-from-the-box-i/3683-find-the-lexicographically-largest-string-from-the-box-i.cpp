class Solution {
public:
    string answerString(string s, int f) {
        if (f == 1) {
            return s;
        }
        int n = s.size();
        int maxlen = n - f + 1;
        string ans;
        for (int i = 0; i < n; i++) {
            ans = max(ans, s.substr(i, maxlen));
        }
        return ans;
    }
};