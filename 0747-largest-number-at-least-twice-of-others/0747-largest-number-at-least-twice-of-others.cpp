class Solution {
public:
    int dominantIndex(vector<int>& v) {
        int l = -1, li = -1;
        int sl = -1, sli = -1;
        int n = v.size();

        for (int i = 0; i < n; i++) {
            if (v[i] > l) {
                sl = l;
                sli = li;
                l = v[i];
                li = i;
            } else if (v[i] > sl) {
                sl = v[i];
                sli = i;
            }
        }

        return l >= 2 * sl ? li : -1;
    }
};
