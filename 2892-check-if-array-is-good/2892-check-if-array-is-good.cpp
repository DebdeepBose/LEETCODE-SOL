class Solution {
public:
    bool isGood(vector<int>& v) {
        vector<int> ans(201, 0);
        int n = v.size();
        for (auto e : v) {
            ans[e]++;
        }
        if (ans[n - 1] != 2) {
            return false;
        }
        for (int i = 1; i < n - 1; i++) {
            if (ans[i] != 1) {
                return false;
            }
        }
        return true;
    }
};