class Solution {
public:
    void findComb(vector<int>& v, int i, int t, vector<int>& tmp,
                  vector<vector<int>>& ans) {
        if (i >= v.size()) {
            if (t == 0) {
                ans.push_back(tmp);
            }
            return;
        }
        if (v[i] <= t) {
            tmp.push_back(v[i]);
            findComb(v, i, t - v[i], tmp, ans);
            tmp.pop_back();
        }
        findComb(v, i + 1, t, tmp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        vector<int> tmp;
        vector<vector<int>> ans;
        findComb(v, 0, t, tmp, ans);
        return ans;
    }
};