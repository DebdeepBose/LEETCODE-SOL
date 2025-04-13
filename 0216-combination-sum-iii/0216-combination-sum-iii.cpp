class Solution {
public:
    void combo(vector<int>& v, vector<vector<int>>& ans, vector<int>& tmp,
               int k, int n, int i, int m) {
        if (k == 0) {
            if (tmp.size() == m) {
                ans.push_back(tmp);
            }
            return;
        }

        for (int j = i; j < n; j++) {
            if (v[j] > k) {
                break;
            }
            tmp.push_back(v[j]);
            combo(v, ans, tmp, k - v[j], n, j + 1, m);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int m, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int n = v.size();
        combo(v, ans, tmp, k, n, 0, m);
        return ans;
    }
};