class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        stack<int> st;
        int res = 0;
        v.push_back(0);
        for (int i = 0; i < v.size(); i++) {
            while (!st.empty() && v[st.top()] > v[i]) {
                int top = v[st.top()];
                st.pop();
                int archeck = st.empty() ? -1 : st.top();
                res = max(res, top * (i - archeck - 1));
            }
            st.push(i);
        }
        return res;
    }
};
