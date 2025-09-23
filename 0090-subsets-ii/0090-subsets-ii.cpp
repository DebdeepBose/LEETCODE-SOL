class Solution {
public:
    void help(vector<int>& v, int n, vector<vector<int>>& ans,
              vector<int>& tmp) {
        if (n < 0) {
            ans.push_back(tmp);
            return;
        }

        tmp.push_back(v[n]);
        help(v, n - 1, ans, tmp);
        tmp.pop_back();

        int prev = v[n];
        while (n > 0 && prev == v[n - 1]) {
            n--;
        }
        help(v, n - 1, ans, tmp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        vector<vector<int>> ans;
        vector<int> tmp;
        help(v, n - 1, ans, tmp);
        return ans;
    }
};