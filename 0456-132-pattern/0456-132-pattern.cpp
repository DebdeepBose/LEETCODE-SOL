class Solution {
public:
    bool find132pattern(vector<int>& v) {
        int n = v.size();

        if (n < 3) {
            return false;
        }

        stack<int> st;
        int maxThird = INT_MIN;

        for (int i = n - 1; i >= 0; i--) {
            if (v[i] < maxThird) {
                return true;
            }
            while (!st.empty() && st.top() < v[i]) {
                maxThird = st.top();
                st.pop();
            }
            st.push(v[i]);
        }
        return false;
    }
};