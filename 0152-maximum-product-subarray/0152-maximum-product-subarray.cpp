class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        int lprod = 1;
        int rprod = 1;
        int maxp = INT_MIN;
        for (int i = 0; i < n; i++) {
            lprod *= v[i];
            rprod *= v[n - i - 1];
            maxp = max(maxp, max(lprod, rprod));
            if (lprod == 0) {
                lprod = 1;
            }
            if (rprod == 0) {
                rprod = 1;
            }
        }
        return maxp;
    }
};