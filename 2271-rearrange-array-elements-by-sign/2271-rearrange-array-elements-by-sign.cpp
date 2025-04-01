class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        int n = v.size();
        int pos = 0, neg = 1;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (v[i] < 0) {
                ans[neg] = v[i];
                neg += 2;
            } else if (v[i] >= 0) {
                ans[pos] = v[i];
                pos += 2;
            }
        }
        return ans;
    }
};