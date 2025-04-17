class Solution {
public:
    int minimumSum(vector<int>& v) {
         int n = v.size();
        vector<int> left_min(n, INT_MAX);
        vector<int> right_min(n, INT_MAX);

        int mini = v[0];
        for (int i = 1; i < n; i++) {
            left_min[i] = mini;
            mini = min(mini, v[i]);
        }

        int mini2 = v[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_min[i] = mini2;
            mini2 = min(mini2, v[i]);
        }

        int ans = INT_MAX;
        
        for (int i = 1; i < n - 1; i++) {
            if (v[i] > left_min[i] && v[i] > right_min[i]) {
                ans = min(ans, v[i] + left_min[i] + right_min[i]);
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};