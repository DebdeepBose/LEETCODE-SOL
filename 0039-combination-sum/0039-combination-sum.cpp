class Solution {
public:
    void combo(vector<int>& v, int k, vector<vector<int>>& ans,
               vector<int>& tmp, int n, int d) {
        if (d >= n) {
            if (k == 0) {
                ans.push_back(tmp);
            }
            return;
        }
        if (v[d] <= k) {

            tmp.push_back(v[d]); //[2,2,2,2]
            combo(v, k - v[d], ans, tmp, n, d);

            tmp.pop_back();
        }
        combo(v, k, ans, tmp, n, d + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& v, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int n = v.size();
        combo(v, k, ans, tmp, n, 0);
        return ans;
    }
};