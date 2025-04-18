class Solution {
public:
    int minimumSum(vector<int>& v) {
        int n = v.size();
        vector<int> l(n, INT_MAX);
        vector<int> r(n, INT_MAX);
        int lmin = v[0];
        int rmin = v.back();
        for (int i = 1; i < n; i++) {
            l[i] = lmin;
            lmin = min(lmin, v[i]);
        }
        for (int i = n - 1; i >= 1; i--) {
            r[i] = rmin;
            rmin = min(rmin, v[i]);
        }
        int ans = INT_MAX;
        for (int i = 1; i < n - 1; i++) {
            if (v[i] > l[i] && v[i] > r[i]) {
                int sum = v[i] + l[i] + r[i];
                ans = min(ans, sum);
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};