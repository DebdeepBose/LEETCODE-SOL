class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> st, pair(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push_back(i);
            }
            if (s[i] == ')') {
                int j = st.back();
                st.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }

        string res = "";
        for (int i = 0, d = 1; i < n; i += d) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                d = -d;
            } else {
                res += s[i];
            }
        }

        return res;
    }
};
