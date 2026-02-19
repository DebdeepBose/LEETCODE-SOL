class Solution {
public:
    vector<long long> minOperations(vector<int>& v, vector<int>& q) {
        int m = q.size();
        int n = v.size();
        sort(v.begin(), v.end());
        vector<long long> pref(n);
        pref[0] = v[0] * 1LL;
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + v[i];
        }
        vector<long long> ans(m);
        for (int i = 0; i < m; i++) {
            int idx = upper_bound(v.begin(), v.end(), q[i]) - v.begin();
            if (idx == n || idx == 0) {
                long long mul = 1LL * n * q[i];
                ans[i] = abs(mul - pref[n - 1]);
            } else {
                long long left = abs((long long)q[i] * idx - pref[idx - 1]);
                long long right = abs((long long)q[i] * (n - idx) -
                                      abs(pref[n - 1] - pref[idx - 1]));
                ans[i] = left + right;
            }
        }
        return ans;
    }
};