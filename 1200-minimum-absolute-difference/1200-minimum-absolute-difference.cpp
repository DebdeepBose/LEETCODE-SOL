class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        int mind = INT_MAX;
        for (int i = 1; i < n; i++) {
            mind = min(mind, (v[i] - v[i - 1]));
        }
        vector<vector<int>> ans;
        for (int i = 1; i < n; i++) {
            int dif = abs(v[i] - v[i - 1]);
            if (dif == mind) {
                ans.push_back({v[i - 1], v[i]});
            }
        }
        return ans;
    }
};