class Solution {
public:
    long long maximumScore(vector<int>& v) {
        int n = v.size();

        vector<long long> ps(n);
        vector<int> sufMin(n);

        ps[0] = v[0];
        for (int i = 1; i < n; i++) {
            ps[i] = ps[i - 1] + 1LL * v[i];
        }

        sufMin[n - 1] = v[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            sufMin[i] = min(sufMin[i + 1], v[i]);
        }

        long long ans = LLONG_MIN;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, ps[i] - sufMin[i + 1]);
        }

        return ans;
    }
};
