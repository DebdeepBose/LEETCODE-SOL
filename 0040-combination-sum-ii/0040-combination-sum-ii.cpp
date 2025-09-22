class Solution {
public:
    void gen(vector<int>& v, int k, vector<vector<int>>& ans, vector<int>& tmp, int n) {
        if (k == 0) {
            ans.push_back(tmp);
            return;
        }
        if (n < 0 || k < 0) {
            return;
        }

       
        tmp.push_back(v[n]);
        gen(v, k - v[n], ans, tmp, n - 1);
        tmp.pop_back();

        int prev = v[n];
        while (n - 1 >= 0 && v[n - 1] == prev) {
            n--;
        }

        gen(v, k, ans, tmp, n - 1);
    }

    vector<vector<int>> combinationSum2(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        vector<int> tmp;

        gen(v, k, ans, tmp, v.size() - 1);

        return ans;
    }
};
