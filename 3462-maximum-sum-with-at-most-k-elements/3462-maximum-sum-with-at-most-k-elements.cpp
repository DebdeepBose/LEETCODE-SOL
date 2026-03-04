class Solution {
public:
    long long maxSum(vector<vector<int>>& v, vector<int>& u, int k) {
        for (auto& row : v) {
            sort(row.begin(), row.end());
        }
        vector<int> el;
        int m = v.size();
        int n = v[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0 && u[i] > 0; j--) {
                el.push_back(v[i][j]);
                u[i]--;
            }
        }
        sort(el.rbegin(), el.rend());
        long long sum = 0LL;
        int i = 0;
        while (k--) {
            sum += el[i++];
        }
        return sum;
    }
};