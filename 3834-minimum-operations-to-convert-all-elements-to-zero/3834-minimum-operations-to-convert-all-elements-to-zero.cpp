class Solution {
public:
    int minOperations(vector<int>& v) {

        stack<int> st;
        int count = 0;
        int n = v.size();

        for (int i = 0; i < n; i++) {

            while (!st.empty() && v[i] < st.top()) {
                st.pop();
            }

            if (v[i] > 0 && (st.empty() || v[i] != st.top())) {
                count++;
                st.push(v[i]);
            }
        }
        return count;
    }
};