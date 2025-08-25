class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<int> ans;
        for (int s = 0; s < m + n - 1; s++) {
            vector<int> tmp;
            for (int i = 0; i < m; i++) {
                int j = s - i;
                if (j >= 0 && j < n) {
                    tmp.push_back(v[i][j]);
                }
            }
            if (s % 2 == 0) {
                reverse(tmp.begin(), tmp.end());
            }
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
        return ans;
    }
};
