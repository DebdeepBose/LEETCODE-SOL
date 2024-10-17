class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        stack<int> st;
        int maxArea = 0;
        int n = v.size();
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && v[st.top()] > v[i]) {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(v[element] * (nse - pse - 1), maxArea);
            }
            st.push(i);
        }
        
        while(!st.empty()) {
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(v[element] * (nse - pse - 1), maxArea);
        }
        
        return maxArea;
    }
};
