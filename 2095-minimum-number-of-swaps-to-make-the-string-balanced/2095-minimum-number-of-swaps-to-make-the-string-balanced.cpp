class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for (auto e : s) {
            if (e == '[') {
                st.push(e);
            } else {
                if (!st.empty()) {
                    st.pop();
                }
            }
        }
        int n = st.size();
        return (n + 1) / 2;
    }
};