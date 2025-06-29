class Solution {
public:
    int numSubseq(vector<int>& v, int k) {
        int n = v.size();
        int mod = 1e9 + 7;
        sort(v.begin(), v.end());

        if (v[0] > k) {
            return 0;
        }

        vector<int> pre(n, 1);
        for (int i = 1; i < n; i++) {
            pre[i] = (pre[i - 1] * 2) % mod;
        }

        int l = 0;
        int r = n - 1;
        int ans = 0;

        while (l <= r) {
            if (v[l] + v[r] > k) {
                r--;
            } else {
                ans = (ans + pre[r - l]) % mod;
                l++;
            }
        }
        return ans;
    }
};