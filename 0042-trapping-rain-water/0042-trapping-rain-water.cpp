class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n - 1;
        int lmax = v[l];
        int rmax = v[r];
        int rain = 0;

        while (l <= r) {
            if (lmax <= rmax) {
                lmax = max(lmax, v[l]);
                rain += lmax - v[l];
                l++;
            } else {
                rmax = max(rmax, v[r]);
                rain += rmax - v[r];
                r--;
            }
        }
        return rain;
    }
};
