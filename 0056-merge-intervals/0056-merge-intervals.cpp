class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int n = v.size();
        if (n == 1) {
            return v;
        }

        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (ans.empty() || v[i][0] > ans.back()[1]) {
                ans.push_back(v[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], v[i][1]);
            }
        }
        return ans;
    }
};