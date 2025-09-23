class Solution {
public:
    void lc(string s, int n, vector<string>& ans, string tmp, int i,
            vector<string>& mp) {
        if (i == n) {
            ans.push_back(tmp);
            return;
        }

        string r = mp[s[i] - '0'];
        for (auto e : r) {
            tmp.push_back(e);
            lc(s, n, ans, tmp, i + 1, mp);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string s) {
        if(s.empty()){
            return {};
        }
        vector<string> ans;
        string tmp = "";
        int n = s.length();
        vector<string> mp = {"",    "",    "abc",  "def", "ghi",
                             "jkl", "mno", "pqrs", "tuv", "wxyz"};
        lc(s, n, ans, tmp, 0, mp);

        return ans;
    }
};