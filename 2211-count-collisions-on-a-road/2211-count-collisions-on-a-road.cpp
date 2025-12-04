class Solution {
public:
    int countCollisions(string s) {
        stack<char> st;
        int c = 0;
        bool col = false;
        for (auto e : s) {
            if (!st.empty() && e == 'L' && st.top() == 'L') {
                if (col) {
                    c++;
                }
            }
            if (!st.empty() && e == 'R' &&
                (st.top() == 'L' || st.top() == 'S')) {
                while (!st.empty()) {
                    st.pop();
                }
            }
            if (!st.empty() && e == 'L') {
                if (st.top() == 'R') {
                    c += 2;
                    st.pop();
                    col = true;
                } else if (st.top() == 'S') {
                    c++;
                    st.pop();
                    col = true;
                }
                while (!st.empty()) {
                    if (st.top() == 'R') {
                        c++;
                        col = true;
                    }
                    st.pop();
                }
            }
            if (!st.empty() && e == 'S') {
                if (st.top() == 'R') {
                    while (!st.empty() && st.top() == 'R') {
                        c++;
                        st.pop();
                        col = true;
                    }
                }
            }
            st.push(e);
        }
        return c;
    }
};