class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        int l = 0;
        int n = v.size();
        int r = 1;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (v[i] < 0) {
                ans[r] = v[i];
                r += 2;
            } else if (v[i] > 0) {
                ans[l] = v[i];
                l += 2;
            }
        }
        return ans;
    }
};