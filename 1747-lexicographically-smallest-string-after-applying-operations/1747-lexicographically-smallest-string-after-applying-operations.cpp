class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        unordered_set<string> st;
        string ans = s;
        dfs(s, a, b, n, st, ans);
        return ans;
    }

    void dfs(string s, int a, int b, int n, unordered_set<string>& st,
             string& ans) {
        if (st.find(s) != st.end()) {
            return;
        }
        st.insert(s);
        ans = min(ans, s);

        string added = addToString(s, a, n);
        dfs(added, a, b, n, st, ans);

        string rotated = rotateString(s, b);
        dfs(rotated, a, b, n, st, ans);
    }

    string addToString(string s, int a, int n) {
        for (int i = 1; i < n; i += 2) {
            int ch = (s[i] - '0' + a) % 10;
            s[i] = ch + '0';
        }
        return s;
    }

    string rotateString(string s, int b) {
        int n = s.size();
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
        return s;
    }
};
