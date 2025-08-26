class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> cmp(26, 0);
        for (char ch : s) {
            cmp[ch - 'a']++;
        }
        for (int i = 0; i < t; i++) {
            vector<long long> newCmp(26, 0);
            for (int j = 0; j < 26; j++) {
                if (j == 25) {
                    newCmp[0] = (newCmp[0] + cmp[j]) % MOD;
                    newCmp[1] = (newCmp[1] + cmp[j]) % MOD;
                } else {
                    newCmp[j + 1] = (newCmp[j + 1] + cmp[j]) % MOD;
                }
            }
            cmp = newCmp;
        }
        long long e = 0;
        for (long long cn : cmp) {
            e = (e + cn) % MOD;
        }
        return e;
    }
};
