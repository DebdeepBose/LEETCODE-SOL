class Solution {
public:
    void gen(vector<string>& ans, string s, int n, int idx, string& tmp,
             vector<string> digitMap) {

        if (idx == n) {
            ans.push_back(tmp);
            return;
        }

        string letter = digitMap[s[idx] - '0'];

        for (auto ch : letter) {

            tmp.push_back(ch);
            gen(ans, s, n, idx + 1, tmp, digitMap);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string s) {
        if (s.empty()) {
            return {};
        }
        int n = s.length();
        vector<string> ans;
        string tmp = "";
        vector<string> digitMap = {"",    "",    "abc",  "def", "ghi",
                                   "jkl", "mno", "pqrs", "tuv", "wxyz"};
        gen(ans, s, n, 0, tmp, digitMap);
        return ans;
    }
};