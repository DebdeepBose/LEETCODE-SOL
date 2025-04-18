class Solution {
public:
    bool isPali(string part) {
        string trap = part;
        reverse(trap.begin(), trap.end());
        return part == trap;
    }

    void gen(vector<string>& tmp, vector<vector<string>>& ans, string s) {
        if (s.empty()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);
            if (isPali(part)) {
                tmp.push_back(part);
                gen(tmp, ans, s.substr(i + 1)); 
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        vector<vector<string>> ans;
        gen(tmp, ans, s);
        return ans;
    }
};
