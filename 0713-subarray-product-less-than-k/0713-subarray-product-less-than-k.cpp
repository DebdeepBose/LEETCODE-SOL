class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& v, int k) {
        int l = 0;
        int r = 0;
        int c = 0;
        int n = v.size();
        long long p = 1;
        while (r < n) {
            p *= v[r];
            while (l <= r && p >= k) {
                if (v[l] > 0) {
                    p /= v[l];
                }
                l++;
            }
            if (p < k) {
                c += r - l + 1;
            }
            r++;
        }
        return c;
    }
};