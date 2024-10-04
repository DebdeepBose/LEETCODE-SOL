class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        int n = v.size();
        vector<int> ans;
        stack<int> st;
        ans.push_back(0);
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && v[i] >= v[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(abs(i - st.top()));
            }
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};