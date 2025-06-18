class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int n = v.size();
        vector<vector<int>> ans;
        if (v.back() - v[0] <= k) {
            for (int i = 0; i < n; i = i + 3) {
                ans.push_back({v[i], v[i + 1], v[i + 2]});
            }
            return ans;
        }

        for (int i = 0; i < n; i = i + 3) {
            if (v[i + 2] - v[i] > k) {
                return {};
            } else {
                ans.push_back({v[i], v[i + 1], v[i + 2]});
            }
        }
        return ans;
    }
};