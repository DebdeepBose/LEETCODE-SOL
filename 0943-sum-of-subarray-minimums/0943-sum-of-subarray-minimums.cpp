class Solution {
public:
    int mod = 1e9 + 7;

    vector<int> prev_sm_eq_idx(vector<int>& v, int n) {
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && v[st.top()] > v[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> next_sm_eq_idx(vector<int>& v, int n) {
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && v[st.top()] >= v[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& v) {
        int n = v.size();
        vector<int> prev(n);
        vector<int> next(n);
        prev = prev_sm_eq_idx(v, n);
        next = next_sm_eq_idx(v, n);
        long long sum = 0;
        for (int i = 0; i < v.size(); i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            sum = (sum + (left * right * v[i]) % mod) % mod;
        }
        return sum;
    }
};
