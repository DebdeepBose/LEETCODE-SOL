class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        stack<int> st;
        int n = v.size();
        vector<int> ans(n, -1);

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= v[i % n]) {
                st.pop();
            }
            if (i < n) {
                if (st.empty()) {
                    ans[i] = -1;
                } else {
                    ans[i] = st.top();
                }
            }
            st.push(v[i % n]);
        }

        return ans;
    }
};