class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void p(string s, vector<vector<string>>& ans, vector<string>& tmp, int n, int index) {
        if (index == n) {
            ans.push_back(tmp);
            return;
        }

        for (int j = index; j < n; j++) {
            if (isPalindrome(s, index, j)) {
                string piece = s.substr(index, j - index + 1);
                tmp.push_back(piece);
                p(s, ans, tmp, n, j + 1);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;

        p(s, ans, tmp, s.size(), 0);

        return ans;
    }
};
