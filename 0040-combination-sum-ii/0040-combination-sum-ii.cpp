class Solution {
public:
    void combo(vector<int>& v, set<vector<int>>& ans, vector<int>& tmp, int k,
               int n, int i) {

        if (i >= n) {
            if (k == 0) {
                ans.insert(tmp);
            }
            return;
        }

        if (v[i] <= k) {
            tmp.push_back(v[i]);
            combo(v, ans, tmp, k - v[i], n, i + 1);
            tmp.pop_back();
        }
        combo(v, ans, tmp, k, n, i + 1);
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int k) {
        set<vector<int>> ans;
        vector<int> tmp;
        int n = v.size();
        sort(v.begin(), v.end());
        combo(v, ans, tmp, k, n, 0);
        vector<vector<int>> finalans(ans.begin(), ans.end());
        return finalans;
    }
};