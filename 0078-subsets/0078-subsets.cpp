class Solution {
public:
    void gen(vector<int>& v, vector<vector<int>>& ans, vector<int>& tmp, int n,
             int st) {
        if (st >= n) {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(v[st]);
        gen(v, ans, tmp, n, st + 1);
        tmp.pop_back();
        gen(v, ans, tmp, n, st + 1);
    }
    vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int n = v.size();
        gen(v, ans, tmp, n, 0);
        return ans;
    }
};