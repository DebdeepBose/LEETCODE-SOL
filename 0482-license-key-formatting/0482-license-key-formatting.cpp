class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string r = "";
        for (auto e : s) {
            if (e != '-') {
                r += toupper(e);
            }
        }
        int n = r.size();
        int f = n % k;
        string ans = "";
        if (f > 0) {
            ans += r.substr(0, f);
        }
        for (int i = f; i < n; i += k) {
            if (i > 0 || f > 0) {
                ans += '-';
            }
            ans += r.substr(i, k);
        }
        return ans;
    }
};
