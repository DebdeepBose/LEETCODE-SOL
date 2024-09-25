class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int n = v.size();
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int z = 0;
        for (int r = 0; r < n; r++) {
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
        }
        return maxlen;
    }
};