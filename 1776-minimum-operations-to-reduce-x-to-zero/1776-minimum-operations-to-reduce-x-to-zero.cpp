class Solution {
public:
    int minOperations(vector<int>& v, int x) {
        int sum = accumulate(v.begin(), v.end(), 0);
        int np = sum - x;
        int r = 0;
        int l = 0;
        int n = v.size();
        int s = 0;
        int maxi = 0;
        if (np == 0) {
            return n;
        }
        while (r < n) {
            s += v[r];
            while (s > np && l <= r) {
                s -= v[l];
                l++;
            }
            if (s == np) {
                maxi = max(maxi, r - l + 1);
            }
            r++;
        }

        return maxi == 0 ? -1 : n - maxi;
    }
};
