class Solution {
public:
    void findAC(int k, int n, int i, vector<vector<int>>& ans,
                vector<int>& tmp) {

        if (tmp.size() == k) {
            if (n == 0) {
                ans.push_back(tmp);
            }
            return;
        }
        if (i > 9) {
            return;
        }

        tmp.push_back(i);
        findAC(k, n - i, i + 1, ans, tmp);
        tmp.pop_back();
        findAC(k, n, i + 1, ans, tmp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n > k * 9 || n < k) {
            return {};
        }
        vector<vector<int>> ans;
        vector<int> tmp;
        findAC(k, n, 1, ans, tmp);

        return ans;
    }
};