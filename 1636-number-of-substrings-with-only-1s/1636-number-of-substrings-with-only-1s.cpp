class Solution {
public:
    int numSub(string s) {
        long long o = 0;
        long long c = 0;
        const int MOD = 1000000007;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                o++;
            }
            if ((i == s.size() - 1 || s[i] == '0') && o > 0) {
                long long sum = o * (o + 1) / 2;
                c = (c + sum) % MOD;
                o = 0;
            }
        }
        return (int)c ;
    }
};
