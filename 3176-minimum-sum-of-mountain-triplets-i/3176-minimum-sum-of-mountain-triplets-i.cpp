class Solution {
public:
    int minimumSum(vector<int>& v) {
        int n = v.size();
        long long minsum = INT_MAX;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (v[j] > v[i] && v[j] > v[k]) {
                        long long sum = v[i] + v[j] + v[k];
                        minsum = min(minsum, sum);
                    }
                }
            }
        }
        if (minsum == INT_MAX) {
            return -1;
        } else {
            return minsum;
        }
    }
};