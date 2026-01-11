class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string tmp = "";
        help(n, tmp, ans, 0, 0);
        return ans;
    }
    void help(int n, string tmp, vector<string>& ans, int op, int cl) {
        if (op + cl == n * 2) {
            ans.push_back(tmp);
            return;
        }

        if (op < n) {
            tmp.push_back('(');
            help(n, tmp, ans, op + 1, cl);
            tmp.pop_back();
        }

        if (!tmp.empty() && cl < op) {
            tmp.push_back(')');
            help(n, tmp, ans, op, cl + 1);
            tmp.pop_back();
        }
    }
};