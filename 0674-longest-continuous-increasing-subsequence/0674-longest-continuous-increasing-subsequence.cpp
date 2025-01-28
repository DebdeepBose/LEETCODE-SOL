class Solution {
public:
    int findLengthOfLCIS(vector<int>& v) {
        int n = v.size();
        int c = 1;
        int maxc = 0;
        for (int i = 1; i < n; i++) {
            if (v[i] > v[i - 1]) {
                c++;
            } else {
                maxc = max(maxc, c);
                c = 1;
            }
        }
        return max(maxc, c);
    }
};