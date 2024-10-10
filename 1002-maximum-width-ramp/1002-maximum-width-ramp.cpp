class Solution {
public:
    int maxWidthRamp(vector<int>& v) {
        int n = v.size();
        stack<int> st;
        st.push(0);
        for (int i = 0; i < n; i++) {
            if (v[st.top()] > v[i]) {
                st.push(i);
            }
        }
        int maxi = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && v[st.top()] <= v[i]) {
                maxi = max(maxi, i - st.top());
                st.pop();
            }
        }
        return maxi;
    }
};