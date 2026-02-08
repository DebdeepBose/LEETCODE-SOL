class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& v) {
        int n = v.size();
        stack<long long> st;
        for (int i = 0; i < n; i++) {
            bool eq = false;
            long long toIns = v[i];
            while (!st.empty() && st.top() == toIns) {
                toIns = 2 * st.top();
                st.pop();
                eq = true;
            }
            if (eq) {
                st.push(toIns);
            }
            if (st.empty() || eq == false) {
                st.push(v[i]);
            }
        }
        vector<long long> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};