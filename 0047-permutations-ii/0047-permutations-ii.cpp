class Solution {
public:
    void helper(vector<int> v, int i, int j, vector<vector<int>>& ans) {
        if (i == j) {
            ans.push_back(v);
            return;
        }

        for (int k = i; k < j; k++) {
            bool shouldSwap = true;
            for (int l = i; l < k; l++) {
                if (v[l] == v[k]) {
                    shouldSwap = false;
                    break;
                }
            }
            if (!shouldSwap) continue;

            swap(v[i], v[k]);
            helper(v, i + 1, j, ans);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        helper(v, 0, v.size(), ans);
        return ans;
    }
};
