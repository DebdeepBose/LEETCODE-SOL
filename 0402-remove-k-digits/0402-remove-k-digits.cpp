class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size();
        if (n == k) {
            return "0";
        }
        stack<int> st;
        for (char c : s) {
            while (k > 0 && !st.empty() && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
            if (st.size() == 1 && c == '0') {
                st.pop();
            }
        }

        while (k > 0 && !st.empty()) {
            k--;
            st.pop();
        }

        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        if (ans.size() == 0) {
            return "0";
        }
        return ans;
    }
};