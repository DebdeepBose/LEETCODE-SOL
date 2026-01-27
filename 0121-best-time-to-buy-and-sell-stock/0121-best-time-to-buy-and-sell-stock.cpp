class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int mxp = 0;
        int cur = v[0];
        for (int i = 1; i < n; i++) {
            mxp = max(mxp, v[i] - cur);
            cur = min(cur, v[i]);
        }
        return mxp;
    }
};