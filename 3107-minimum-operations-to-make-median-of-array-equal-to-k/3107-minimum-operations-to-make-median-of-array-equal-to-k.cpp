class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& v, int k) {
        long long ops = 0LL;
        int n = v.size();
        if (n == 1) {
            return abs(v[0] - k);
        }
        int medIdx = n / 2;
        sort(v.begin(), v.end());
        if (v[medIdx] == k) {
            return 0;
        } else if (v[medIdx] > k) {
            int firstIdxOfNumLargerThanK =
                lower_bound(v.begin(), v.end(), k) - v.begin();
            for (int i = firstIdxOfNumLargerThanK; i <= medIdx; i++) {
                ops += abs(k - v[i]);
            }
        } else {
            int firstIdxOfNumLargerThanK =
                lower_bound(v.begin() + medIdx, v.end(), k) - v.begin();
            for (int i = medIdx; i < firstIdxOfNumLargerThanK; i++) {
                ops += abs(k - v[i]);
            }
        }
        return ops;
    }
};