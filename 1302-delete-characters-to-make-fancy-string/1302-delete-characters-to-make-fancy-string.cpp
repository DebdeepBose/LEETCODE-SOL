class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int c = 0;
        for (auto e : s) {
            if (!ans.empty() && ans.back() == e) {
                c++;
            } else {
                c = 1;
            }

            if (c <= 2) {
                ans += e;
            }
        }
        return ans;
    }
};