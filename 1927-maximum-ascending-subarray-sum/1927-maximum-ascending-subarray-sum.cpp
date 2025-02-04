class Solution {
public:
    int maxAscendingSum(vector<int>& v) {
        int s = 0;
        int l = 0;
        int r = 0;
        int n = v.size();
        int maxs = INT_MIN;
        while (r < n) {
            if (r == 0 || v[r] > v[r - 1]) {
                s += v[r];
                maxs = max(maxs, s);
            } else {
                while (r != l) {
                    s -= v[l];
                    l++;
                }
                s += v[r];
            }
            r++;
        }
        return maxs;
    }
};