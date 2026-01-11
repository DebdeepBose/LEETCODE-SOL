class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        vector<vector<int>> ans;
        vector<int> tmp;
        help(ans, tmp, v, v.size(), t);
        return ans;
    }
    void help(vector<vector<int>>& ans, vector<int>& tmp, vector<int>& v, int n,
              int t) {

        if (t == 0) {
            ans.push_back(tmp);
            return;
        }

        if (n <= 0 || t < 0) {
            return;
        }

        tmp.push_back(v[n - 1]);
        help(ans, tmp, v, n, t - v[n - 1]);
        tmp.pop_back();
        help(ans, tmp, v, n - 1, t);
    }
};