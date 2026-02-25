class Solution {
public:
    vector<int> sortByBits(vector<int>& v) {

        sort(v.begin(), v.end(), [](int a, int b) {
            int ca = __builtin_popcount(a);
            int cb = __builtin_popcount(b);
            return ca != cb ? ca < cb : a < b;
        });

        return v;
    }
};