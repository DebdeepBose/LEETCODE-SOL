class Solution {
public:
    // Helper function to generate all valid combinations
    void gen(vector<string>& ans, string& tmp, int n, int op, int cl) {
     
        if (op > n) {return;}

   
        if (op == n && cl == n) {
            ans.push_back(tmp);
            return;
        }

    
        if (op < n) {
            tmp.push_back('(');
            gen(ans, tmp, n, op + 1, cl);
            tmp.pop_back(); 
        }


        if (cl < op) {
            tmp.push_back(')');
            gen(ans, tmp, n, op, cl + 1);
            tmp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string tmp = "";
        gen(ans, tmp, n, 0, 0);
        return ans;
    }
};
