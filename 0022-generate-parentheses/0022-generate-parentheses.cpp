class Solution {
public:
    void gen(int n, vector<string>& ans, int op, int cl, string s) {
        if (op + cl == n * 2) {
            ans.push_back(s);
            return;
        }

        if (op < n) {
            s += '(';
            gen(n, ans, op + 1, cl, s);
            s.pop_back();
        }

        if (cl < op) {
            s += ')';
            gen(n, ans, op, cl + 1, s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string s = "";
        int op = 0;
        int cl = 0;

        gen(n, ans, op, cl, s);

        return ans;
    }
};