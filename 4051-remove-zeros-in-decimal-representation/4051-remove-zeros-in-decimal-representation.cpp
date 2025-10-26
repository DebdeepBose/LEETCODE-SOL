class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n);
        string r = "";
        for (auto e : s) {
            if (e != '0') {
                r += e;
            }
        }
        long long x = stoll(r);
        return x;
    }
};