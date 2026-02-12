class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        string newS = "";
        string newT = "";
        for (auto& ch : s) {
            if (!st.empty() && ch == '#') {
                st.pop();
            }
            if (ch != '#') {
                st.push(ch);
            }
        }
        while (!st.empty()) {
            newS += st.top();
            st.pop();
        }
        for (auto& ch : t) {
            if (!st.empty() && ch == '#') {
                st.pop();
            }
            if (ch != '#') {
                st.push(ch);
            }
        }
        while (!st.empty()) {
            newT += st.top();
            st.pop();
        }
        return newS == newT;
    }
};