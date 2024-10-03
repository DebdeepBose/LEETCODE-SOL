class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size(), l = 1, r = n - 2;
        int rain = 0, lmax = v[0], rmax = v[n - 1];
        while (l <= r) {
            if (lmax < rmax) {
                if (v[l] >= lmax) {
                    lmax = v[l];
                } else {
                    rain += lmax - v[l];
                }
                l++;
            } else {
                if (v[r] >= rmax) {
                    rmax = v[r];
                } else {
                    rain += rmax - v[r];
                }
                r--;
            }
        }
        return rain;
    }
};
