class Solution {
public:
    vector<int> decrypt(vector<int>& v, int k) {
        int n = v.size();
        vector<int> ans(n, 0);
        if (k == 0) return ans;
        if (k > 0) {
            int sum = accumulate(v.begin() + 1, v.begin() + k + 1, 0);
            ans[0] = sum;
            for (int l = 1, r = k + 1; l < n; r++, l++) {
                sum += -v[l] + v[r % n];
                ans[l] = sum;
            }
            return ans;
        }
        k = -k;
        int sum = accumulate(v.end() - k, v.end(), 0);
        ans[0] = sum;
        for (int r = 0, l = n - k; r < n - 1; r++, l++) {
            sum += -v[l % n] + v[r];
            ans[r + 1] = sum;
        }
        return ans;
    }
};
