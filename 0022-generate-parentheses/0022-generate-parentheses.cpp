class Solution {
public:
    void generate(int open, int close, vector<string>& ans, string s, int n) {
        if (open == n && close == n) {
            ans.push_back(s);
            return;
        }
        if (open < n) {
            generate(open + 1, close, ans, s + '(', n);
        }
        if (close < open) {
            generate(open, close + 1, ans, s + ')', n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        generate(0, 0, ans, s, n);
        return ans;
    }
};