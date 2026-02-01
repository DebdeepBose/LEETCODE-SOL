class Solution {
public:
    int minimumCost(vector<int>& v) {
        int n = v.size();
        int c = v[0];
        int secMx = INT_MAX;
        int secIdx = -1;
        for (int i = 1; i < n; i++) {
            if (v[i] < secMx) {
                secMx = v[i];
                secIdx = i;
            }
        }
        int thiMx = INT_MAX;
        for (int i = 1; i < n; i++) {
            if (v[i] >= secMx && i != secIdx) {
                thiMx = min(thiMx, v[i]);
            }
        }
        return c + secMx + thiMx;
    }
};