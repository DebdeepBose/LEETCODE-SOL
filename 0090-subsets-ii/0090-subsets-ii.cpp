class Solution {
public:
    void gen(vector<int>& v, vector<vector<int>>& ans, vector<int>& tmp, int n, int i) {
        ans.push_back(tmp);

        for (int j = i; j < n; j++) {
            if (j > i && v[j] == v[j - 1]) {
                continue;
            }
            tmp.push_back(v[j]);
            gen(v, ans, tmp, n, j + 1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int n = v.size();
        sort(v.begin(), v.end());
        gen(v, ans, tmp, n, 0);
        return ans;
    }
};
