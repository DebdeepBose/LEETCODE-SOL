class Solution {
public:
    int longestMonotonicSubarray(vector<int>& v) {
        int l = 1, s = 1;
        int maxl = 1, maxsl = 1;
        int n = v.size();
        for (int i = 1; i < n; i++) {
            if (v[i] > v[i - 1]) {
                l++;
                maxl = max(maxl, l);
            } else {
                l = 1;
            }

            if (v[i] < v[i - 1]) {
                s++;
                maxsl = max(maxsl, s);
            } else {
                s = 1;
            }
        }
        return max(maxl, maxsl);
    }
};