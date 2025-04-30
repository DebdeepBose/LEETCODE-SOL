class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) {
            return 0;
        }
        stack<int> st;
        string tmp = s;

        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && s[i] == ')' && s[st.top()] == '(') {
                tmp[i] = 'd';
                tmp[st.top()] = 'd';
                st.pop();
            } else {
                st.push(i);
            }
        }

        int len = 0, maxlen = 0;
        for (char c : tmp) {
            if (c == 'd') {
                len++;
                maxlen = max(maxlen,len);
            } else {
                len = 0;
            }
        }

        return maxlen;
    }
};
