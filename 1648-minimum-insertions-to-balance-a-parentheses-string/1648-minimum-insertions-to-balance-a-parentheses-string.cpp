class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int insert = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(') {
                st.push(c);
            } else {
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++;
                } else {
                    insert++;
                }

                if (!st.empty()) {
                    st.pop();
                } else {
                    insert++;
                }
            }
        }

        insert += 2 * st.size();
        return insert;
    }
};
