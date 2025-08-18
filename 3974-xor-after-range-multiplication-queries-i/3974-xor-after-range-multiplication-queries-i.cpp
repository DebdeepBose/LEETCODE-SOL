class Solution {
public:
    const int mod = 1e9 + 7;
    int xorAfterQueries(vector<int>& v, vector<vector<int>>& q) {
        for (auto e : q) {
            int l = e[0];
            int r = e[1];
            int k = e[2];
            int j = e[3];
            while (l <= r) {
                v[l] = (1LL * v[l] * j) % mod;
                l += k;
            }
        }
        int ans = 0;
        for (auto e : v) {
            ans ^= e;
        }
        return ans;
    }
};