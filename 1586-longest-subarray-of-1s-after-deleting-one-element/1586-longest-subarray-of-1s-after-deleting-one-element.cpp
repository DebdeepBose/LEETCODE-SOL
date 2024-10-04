class Solution {
public:
    int longestSubarray(vector<int>& v) {
        int l = 0;
        int r = 0;
        int c = 0;
        int n = v.size();
        int maxlen = 0;
        while (r < n) {
            if (v[r] == 0) {
                c++;
            }
            while (c > 1) {
                if (v[l] == 0) {
                    c--;
                }
                l++;
            }
            maxlen = max(maxlen, r - l);
            r++;
        }
        return maxlen;
    }
};
