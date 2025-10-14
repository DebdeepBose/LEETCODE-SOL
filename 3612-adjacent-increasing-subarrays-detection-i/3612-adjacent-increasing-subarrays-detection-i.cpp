class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& v, int k) {

        int n = v.size();
        int w = 1;
        int prev = 0;
        int maxLen = 0;

        for (int i = 1; i < n; i++) {
            if (v[i] > v[i - 1]) {
                w++;
            } else {
                prev = w;
                w = 1;
            }
            maxLen = max(maxLen, max(w / 2, min(prev, w)));
            if (maxLen >= k) {
                return true;
            }
        }
        return false;
    }
};