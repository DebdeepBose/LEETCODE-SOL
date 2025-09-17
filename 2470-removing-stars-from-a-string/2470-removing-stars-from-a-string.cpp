class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (auto e : s) {

            if (!st.empty()) {
                if (e == '*' && isalpha(st.top())) {
                    st.pop();
                    continue;
                }
            }

            st.push(e);
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};