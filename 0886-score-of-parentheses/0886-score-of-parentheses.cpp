class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> ans(1, 0);
        int i = 0;

        for (auto e : s) {
            if (e == '(') {
                ans.push_back(0);
                i++;
            } else {
                ans[i - 1] += max(ans[i] * 2, 1);
                ans.pop_back();
                i--;
            }
        }

        return ans[0];
    }
};