class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& v, vector<vector<int>>& q) {
        int n = v.size();
        int m = q.size();
        vector<bool> ans(m);
        vector<int> check(n, 0);

        for (int i = 1; i < n; i++) {
            check[i] = check[i - 1];
            if (v[i - 1] % 2 == v[i] % 2) {
                check[i]++;
            }
        }
        for (int i = 0; i < m; i++) {
            int left = q[i][0], right = q[i][1];
            int c = check[right] - check[left];
            if (c > 0) {
                ans[i] = false;
            } else {
                ans[i] = true;
            }
        }
        return ans;
    }
};
