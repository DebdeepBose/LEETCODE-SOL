class Solution {
public:
    void cs(vector<int>& v, int k, vector<vector<int>>& ans, vector<int>& tmp,
            int n) {
        if (k == 0) {
            ans.push_back(tmp);
            return;
        }
        if (n < 0 || k < 0) {
            return;
        }

        tmp.push_back(v[n]);
        cs(v, k - v[n], ans, tmp, n);

        tmp.pop_back();
        cs(v, k, ans, tmp, n - 1);
    }
    vector<vector<int>> combinationSum(vector<int>& v, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        cs(v, k, ans, tmp, v.size() - 1);

        return ans;
    }
};