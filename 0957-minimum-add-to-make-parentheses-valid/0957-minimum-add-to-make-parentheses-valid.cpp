class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        for (auto e : s) {
            if (!st.empty() && st.top() == '(' && e == ')') {
                st.pop();
            } else {
                st.push(e);
            }
        }
        return st.size();
    }
};