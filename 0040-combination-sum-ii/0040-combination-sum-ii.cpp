class Solution {
public:
    void combo(vector<int>& v, vector<vector<int>>& ans, vector<int>& tmp, int k, int n, int i) {
        if (k == 0) {
            ans.push_back(tmp);
            return;
        }

        for (int j = i; j < n; j++) {
            if (j > i && v[j] == v[j - 1]) {
                continue;
            }
            if (v[j] > k) {
                break;
            }
            tmp.push_back(v[j]);
            combo(v, ans, tmp, k - v[j], n, j + 1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& v, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int n = v.size();
        sort(v.begin(), v.end());
        combo(v, ans, tmp, k, n, 0);
        return ans;
    }
};
