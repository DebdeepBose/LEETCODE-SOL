class Solution {
public:
    int numSubarraysWithSum(vector<int>& v, int k) {
        return totlsubarr(v, k) - totlsubarr(v, k - 1);
    }
    int totlsubarr(vector<int>& v, int k) {
        if (k < 0) {
            return 0;
        }
        int l = 0;
        int r = 0;
        int n = v.size();
        int c = 0;
        int s = 0;

        while (r < n) {
            s += v[r];
            while (s > k) {
                s -= v[l];
                l++;
            }
            c += r - l + 1;
            r++;
        }

        return c;
    }
};
