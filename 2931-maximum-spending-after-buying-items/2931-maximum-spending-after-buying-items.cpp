class Solution {
public:
    long long maxSpending(vector<vector<int>>& mat) {
        vector<long long> v;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v.push_back(mat[i][j]);
            }
        }
        sort(v.begin(), v.end());
        long long amt = 0LL;
        for (int i = 0; i < v.size(); i++) {
            amt += (v[i] * (i + 1));
        }
        return amt;
    }
};