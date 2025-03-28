class Solution {
public:
    int maxProfit(vector<int>& v) {

        int n = v.size();
        int mp = v[0];
        int mxp = 0;

        for (int i = 1; i < n; i++) {
            if (v[i] > mp) {
                mxp = max(mxp, v[i] - mp);
            } else {
                mp = v[i];
            }
        }
        return mxp;
    }
};