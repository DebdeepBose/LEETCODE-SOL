class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int n = v.size();
        if (n == 0) return {};
        
        sort(v.begin(), v.end());
        
        vector<vector<int>> ans;
        int start = v[0][0];
        int end = v[0][1];
        
        for (int i = 1; i < n; i++) {
            if (v[i][0] <= end) {
                end = max(end, v[i][1]);
            } else {
                ans.push_back({start, end});
                start = v[i][0];
                end = v[i][1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};
