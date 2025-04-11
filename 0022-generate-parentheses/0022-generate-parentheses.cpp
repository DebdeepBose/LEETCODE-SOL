class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s = "";
        int op = 0;
        int cl = 0;
        generate(op, cl, v, s, n);

        return v;
    }
    void generate(int open, int close, vector<string>& v, string s, int n) {
        if (open + close == n * 2) {
            v.push_back(s);
            return;
        }

        if (open < n) {
            generate(open + 1, close, v, s + '(', n);
        }
        if (close < open) {
            generate(open, close + 1, v, s + ')', n);
        }
    }
};