class Solution {
public:
    int findLHS(vector<int>& v) {
        sort(v.begin(), v.end());
        int len = 0;
        int maxlen = 0;
        int l = 0;
        int r = 0;
        int n = v.size();
        while (r < n) {
            while (v[r] - v[l] > 1) {
                l++;
            }
            if (v[r] - v[l] == 1) {
                int len = r - l + 1;
                maxlen = max(maxlen, len);
            }
            r++;
        }
        return maxlen;
    }
};
