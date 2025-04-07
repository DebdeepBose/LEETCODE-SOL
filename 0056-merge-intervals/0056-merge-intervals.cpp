class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = v.size();
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            int start = v[i][0];
            int end = v[i][1];
            if (!ans.empty() && end <= ans.back()[1]) {
                continue;
            }
            for (int j = i; j < n; j++) {
                if (v[j][0] <= end) {
                    end = max(end, v[j][1]);
                } else {
                    break;
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};