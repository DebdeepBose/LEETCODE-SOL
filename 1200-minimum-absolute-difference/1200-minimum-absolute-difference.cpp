class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        vector<vector<int>> ans;
        int mini = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            mini = min(mini, v[i + 1] - v[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            if (v[i + 1] - v[i] == mini) {
                ans.push_back({v[i], v[i + 1]});
            }
        }
        return ans;
    }
};