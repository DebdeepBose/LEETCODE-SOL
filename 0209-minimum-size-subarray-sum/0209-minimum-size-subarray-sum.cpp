class Solution {
public:
    int minSubArrayLen(int k, vector<int>& v) {
        int l = 0;
        int r = 0;
        int n = v.size();
        int s = 0;
        int minlen = INT_MAX;

        while (r < n) {
            s += v[r];
            while (s >= k) {
                minlen = min(minlen, r - l + 1);
                s -= v[l];
                l++;
            }
            r++;
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};
