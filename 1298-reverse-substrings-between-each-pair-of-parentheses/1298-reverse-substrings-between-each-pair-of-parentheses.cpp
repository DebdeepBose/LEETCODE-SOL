class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            string ans = "";
            if (s[i] == ')') {
                while (!st.empty()) {
                    char top = st.top();
                    if (top == '(') {
                        st.pop();
                        break;
                    }
                    ans += top; // dcba
                    st.pop();
                }
                int j = 0;
                while (j < ans.size()) {
                    st.push(ans[j]);
                    j++;
                }
            }

            if (s[i] != ')') {
                st.push(s[i]);
            }
        }

        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};