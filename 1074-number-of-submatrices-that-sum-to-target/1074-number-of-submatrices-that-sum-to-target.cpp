class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& v, int t) {
        int n = v.size();
        int m = v[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                v[i][j] += v[i][j - 1];
            }
        }

        unordered_map<int, int> mp;

        for (int left = 0; left < m; left++) {
            for (int right = left; right < m; right++) {
                mp.clear();
                mp[0] = 1;
                int cur = 0;
                for (int row = 0; row < n; row++) {
                    cur += v[row][right] - (left > 0 ? v[row][left - 1] : 0);
                    ans += mp[cur - t];
                    mp[cur]++;
                }
            }
        }
        return ans;
    }
};
