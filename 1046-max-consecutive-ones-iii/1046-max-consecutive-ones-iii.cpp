class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int n = v.size();
        int l = 0, r = 0;
        int maxlen = 0;
        int z = 0;
        while (r < n) {
            if (v[r] == 0) {
                z++;
            }
            if (z > k) {
                if (v[l] == 0) {
                    z--;
                }
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};
