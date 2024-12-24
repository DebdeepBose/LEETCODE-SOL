class Solution {
public:
    int mn(int tmp) {
        int mx = 0;
        while (tmp > 0) {
            mx = max(mx, tmp % 10);
            tmp /= 10;
        }
        return mx;
    }

    int maxSum(vector<int>& v) {
        int n = v.size();
        int res = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = v[i], b = v[j];
                if (mn(a) == mn(b)) {
                    res = max(a + b, res);
                }
            }
        }
        return res;
    }
};
