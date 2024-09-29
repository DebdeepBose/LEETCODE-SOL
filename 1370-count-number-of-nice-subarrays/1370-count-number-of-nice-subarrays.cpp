class Solution {
public:
    int numberOfSubarrays(vector<int>& v, int k) {
        int n = v.size();
        int l = 0, r = 0, ssum = 0, res = 0;

        while (r < n) {
            ssum += (v[r] % 2);

            while (ssum > k) {
                ssum -= (v[l] % 2);
                l++;
            }

            if (ssum == k) {
                int tmpl = l;
                while (tmpl <= r && v[tmpl] % 2 == 0) {
                    tmpl++;
                }
                res += (tmpl - l + 1);
            }
            r++;
        }
        return res;
    }
};
