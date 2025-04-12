class Solution {
public:
    void gen(vector<int>& v, int n, vector<vector<int>>& ans, vector<int>& tmp,
             int k, int d, int sum) {
        if (sum > k) {
            return;
        }
        if (sum == k) {
            ans.push_back(tmp);
            return;
        }
        if (d >= n) {
            return;
        }

        tmp.push_back(v[d]);
        gen(v, n, ans, tmp, k, d, sum + v[d]);

        tmp.pop_back();
        gen(v, n, ans, tmp, k, d + 1, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& v, int k) {
        int n = v.size();
        vector<vector<int>> ans;
        vector<int> tmp;

        gen(v, n, ans, tmp, k, 0, 0);

        return ans;
    }
};
