class Solution {
public:
    void subf(vector<int>& v, int st, vector<int>& way,
              vector<vector<int>>& ans, int n) {
        ans.push_back(way);
        for (int i = st; i < n; i++) {
            way.push_back(v[i]);
            subf(v, i + 1, way, ans, n);
            way.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>> ans;
        vector<int> way;
        int n = v.size();
        subf(v, 0, way, ans, n);
        return ans;
    }
};
