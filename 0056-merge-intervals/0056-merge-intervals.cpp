class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> ans;
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i][1] >= v[i + 1][0]) {
                v[i + 1][0] = v[i][0];
                v[i + 1][1] = max(v[i][1], v[i + 1][1]);
            } else {
                ans.push_back({v[i][0], v[i][1]});
            }
        }
        ans.push_back(v.back());
        return ans;
    }
};
