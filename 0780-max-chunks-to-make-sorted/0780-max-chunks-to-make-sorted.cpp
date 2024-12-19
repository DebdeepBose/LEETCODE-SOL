class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        int c = 0;
        int n = v.size();
        int vmax = 0;
        for (int i = 0; i < n; i++) {
            vmax = max(vmax,v[i]);
            if (vmax == i) {
                c++;
            }
        }
        return c;
    }
};