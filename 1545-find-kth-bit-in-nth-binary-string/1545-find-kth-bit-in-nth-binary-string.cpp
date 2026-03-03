class Solution {
private:
    void build(string& s) {
        string r = s;
        s += '1';
        for (int i = 0; i < r.size(); i++) {
            r[i] = (r[i] == '0') ? '1' : '0';
        }
        reverse(r.begin(), r.end());
        s += r;
    }

public:
    char findKthBit(int n, int k) {
        string s = "0";
        while (s.size() <= k) {
            build(s);
        }
        return s[k - 1];
    }
};