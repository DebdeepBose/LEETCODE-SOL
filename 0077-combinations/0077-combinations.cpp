class Solution {
public:
    void gen(vector<vector<int>>& ans, vector<int>& tmp, int n, int k, int id) {
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        if (id > n) {
            return;
        }

        tmp.push_back(id);
        gen(ans, tmp, n, k, id + 1);
        tmp.pop_back();
        gen(ans, tmp, n, k, id + 1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        vector<vector<int>> ans;
        int id = 1;
        gen(ans, tmp, n, k, id);
        return ans;
    }
};