class Solution {
public:
    string processStr(string s) {
        string res = "";
        for (auto e : s) {
            if (isalpha(e)) {
                res += e;
            } else if (e == '#') {
                res += res;
            } else if (e == '%') {
                reverse(res.begin(), res.end());
            } else if (e == '*') {
                if (res.size() > 0) {
                    res.pop_back();
                }
            }
        }
        return res;
    }
};