class Solution {
public:
    vector<int> resultsArray(vector<int>& v, int k) {
        const int n = v.size();
        if (n == 1 || k == 1) {
            return v;
        }
        vector<int> ans(n - k + 1, -1);
        int len = 1;
        for (int r = 1; r < n; r++) {
            if (v[r] == v[r - 1] + 1) {
                len++;
            } else {
                len = 1;
            }
            if (len >= k) {
                ans[r - k + 1] = v[r];
            }
        }

        return ans;
    }
};
