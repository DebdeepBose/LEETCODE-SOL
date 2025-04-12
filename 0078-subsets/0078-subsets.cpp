class Solution {
public:
    void gen(vector<int>& v, vector<vector<int>>& ans, vector<int>& tmp, int n,
             int recStackDepth) {
        if (recStackDepth >= n) {
            ans.push_back(tmp);
            return;
        }

        // Exclude current element
        gen(v, ans, tmp, n, recStackDepth + 1);

        // Include current element
        tmp.push_back(v[recStackDepth]);
        gen(v, ans, tmp, n, recStackDepth + 1);
        tmp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int n = v.size();
        gen(v, ans, tmp, n, 0);
        return ans;
    }
};
