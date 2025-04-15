class Solution {
public:
    void gen(vector<vector<int>>& ans, vector<int> &tmp, int n, int idx,
             vector<int>& v) {
        if (idx == n) {
            ans.push_back(tmp);
            return;
        }

        gen(ans, tmp, n, idx + 1, v);
        tmp.push_back(v[idx]);
        gen(ans, tmp, n, idx + 1, v);
        tmp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> ans;
        vector<int> tmp;
        gen(ans, tmp, n, 0, v);
        return ans;
    }
};