class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        stack<int> st;
        int n = v.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(-1);
        }
        for (int i = 0; i < 2 * n; i++) {
            while (!st.empty() && v[st.top()] < v[i % n]) {
                ans[st.top()] = v[i % n];
                st.pop();
            }
            if (i < n) {
                st.push(i);
            }
        }

        return ans;
    }
};