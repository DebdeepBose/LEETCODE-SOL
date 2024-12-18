class Solution {
public:
    vector<int> finalPrices(vector<int>& v) {
        stack<int> st;
        int n = v.size();
        vector<int> ans(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && v[i] < st.top()) {
                st.pop();
            }
            if (!st.empty() && v[i] >= st.top()) {
                ans[i] = v[i] - st.top();
            }
            st.push(v[i]);
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] == -1) {
                ans[i] = v[i];
            }
        }
        return ans;
    }
};