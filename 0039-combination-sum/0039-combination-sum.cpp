class Solution {
public:
    void gen(vector<int>& v, vector<vector<int>>& ans, vector<int>& tmp, int k,
             int n, int i) {
        if (i >= n) {
            if (k == 0) {
                ans.push_back(tmp);
            }
            return;
        }
        if (v[i] <= k) {
            tmp.push_back(v[i]);
            gen(v, ans, tmp, k - v[i], n, i);
            tmp.pop_back();
        }
        gen(v, ans, tmp, k, n, i + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& v, int k) {
        int n = v.size();
        vector<vector<int>> ans;
        vector<int> tmp;
        gen(v, ans, tmp, k, n, 0);
        return ans;
    }
};