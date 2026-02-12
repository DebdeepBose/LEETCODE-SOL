class Solution {
public:
    vector<int> intersection(vector<int>& u, vector<int>& v) {
        unordered_set<int> st(u.begin(), u.end());
        unordered_set<int> order;
        vector<int> ans;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            if (st.find(v[i]) != st.end()) {
                order.insert(v[i]);
            }
        }
        ans.assign(order.begin(), order.end());
        return ans;
    }
};