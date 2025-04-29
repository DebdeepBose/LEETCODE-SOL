class Solution {
public:
    int evalRPN(vector<string> v) {
        int n = v.size();
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (v[i] != "+" && v[i] != "-" && v[i] != "*" && v[i] != "/") {
                int x = stoi(v[i]);
                st.push(x);
            } else {
                int sec = st.top();
                st.pop();
                int fir = st.top();
                st.pop();

                if (v[i] == "+") {
                    ans = fir + sec;
                } else if (v[i] == "-") {
                    ans = fir - sec;
                } else if (v[i] == "*") {
                    ans = fir * sec;
                } else if (v[i] == "/") {
                    ans = fir / sec;
                }

                st.push(ans);
            }
        }
        return st.top();
    }
};
