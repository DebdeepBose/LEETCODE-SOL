class Solution {
public:
    void gen(vector<int>& v, vector<vector<int>>& ans, vector<int>& tmp, int n,
             int i) {
        if (i >= n) {
            ans.push_back(tmp);
            return;
        }
        gen(v, ans, tmp, n, i + 1);
        tmp.push_back(v[i]);
        gen(v, ans, tmp, n, i + 1);
        tmp.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& v) {
        int n = v.size();
        vector<int> tmp;
        vector<vector<int>> ans;
        gen(v, ans, tmp, n, 0);
        return ans;
    }
};