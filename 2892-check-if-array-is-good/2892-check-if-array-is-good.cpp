class Solution {
public:
    bool isGood(vector<int>& v) {
        vector<int> ans(201, 0);
        for (auto n : v) {
            ans[n]++;
        }
        if (ans[v.size() - 1] != 2) {
            return false;
        }
        for (int i = 1; i < v.size() - 1; i++) {
            if (ans[i] != 1) {
                return false;
            }
        }
        return true;
    }
};