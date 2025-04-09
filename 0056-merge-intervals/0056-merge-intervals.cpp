class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int n = v.size();
        vector<vector<int>> ans;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            if (ans.empty() || ans.back()[1] < v[i][0]) {
                ans.push_back(v[i]);
            } else {
                ans.back()[1] = max(v[i][1], ans.back()[1]);
            }
        }
        return ans;
    }
};