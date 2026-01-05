class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& v) {
        int n = v.size();
        int neg = 0;
        int mini = INT_MAX;
        bool z = false;
        long long sum = 0LL;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 0) {
                    z = true;
                }
                mini = min(mini, abs(v[i][j]));
                sum += (long long)abs(v[i][j]);
                if (v[i][j] < 0) {
                    neg++;
                }
            }
        }
        if (z) {
            return sum;
        }
        if (neg % 2 == 1) {
            sum += (2 * (-mini));
        }
        return sum;
    }
};