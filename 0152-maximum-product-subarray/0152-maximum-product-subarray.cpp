class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        double ans = INT_MIN;
        double lprod = 1, rprod = 1;
        for (int i = 0; i < n; i++) {
            lprod *= v[i];
            rprod *= v[n - i - 1];
            ans = max({ans, lprod, rprod});
            if (lprod == 0) {
                lprod = 1;
            }
            if (rprod == 0) {
                rprod = 1;
            }
        }
        return ans;
    }
};