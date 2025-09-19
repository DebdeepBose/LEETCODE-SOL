class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int k) {
        int m = v.size();
        int n = v[0].size();
        for (int i = 0; i < m; i++) {
            auto it = lower_bound(v[i].begin(), v[i].end(), k);
            if (it != v[i].end() && *it == k) {
                return true;
            }
        }
        return false;
    }
};