class Solution {
public:
    int maxProduct(vector<int>& v) {
        int pprod = 1;
        int sprod = 1;
        int n = v.size();
        int maxp = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (pprod == 0) {
                pprod = 1;
            }
            if (sprod == 0) {
                sprod = 1;
            }
            pprod *= v[i];
            sprod *= v[n - i - 1];
            maxp = max(maxp, max(pprod, sprod));
        }
        return maxp;
    }
};