class Solution {
public:
    void genPerm(vector<int>& v, int n, int id, vector<vector<int>>& ans) {
        if (id >= n) {
            ans.push_back(v);
            return;
        }
        for (int i = id; i < n; i++) {
            swap(v[id], v[i]);
            genPerm(v, n, id + 1, ans);
            swap(v[id], v[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>> ans;
        genPerm(v, v.size(), 0, ans);
        return ans;
    }
};