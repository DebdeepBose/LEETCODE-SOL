class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int sum = 0;
        int maxsum = INT_MIN;
        int n = v.size();
        if (n == 1) {
            return v[0];
        }
        for (int i = 0; i < n; i++) {
            sum += v[i];
            maxsum = max(maxsum, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxsum;
    }
};