class Solution {
public:
    int maximumGap(vector<int>& v) {
        int n = v.size();
        if (n < 2) {
            return 0;
        }
        sort(v.begin(), v.end());
        int maxdiff = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            int diff = v[i + 1] - v[i];
            maxdiff = max(maxdiff, diff);
        }
        return maxdiff;
    }
};