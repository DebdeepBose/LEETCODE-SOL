class Solution {
public:
    void gen(int zero, int one, vector<string>& v, string s, int n) {
        if (zero + one == n) {
            v.push_back(s);
            return;
        }
        if (zero + one <= n) {
            gen(zero, one + 1, v, s + '1', n);
        }
        if (s.empty() && zero + one <= n) {
            gen(zero + 1, one, v, s + '0', n);
        } else if (zero + one <= n && (!s.empty() && s.back() != '0')) {
            gen(zero + 1, one, v, s + '0', n);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> v;
        string s = "";
        gen(0, 0, v, s, n);
        return v;
    }
};