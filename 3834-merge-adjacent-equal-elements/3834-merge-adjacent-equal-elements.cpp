class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& v) {
        stack<long long> st;
        for (auto e : v) {
            long long cur = e;

            while (!st.empty() && st.top() == cur) {
                cur *= 2;
                st.pop();
            }

            st.push(cur);
        }

        vector<long long> ans(st.size());
        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};