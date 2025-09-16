class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& v) {
        stack<int> st;
        int n = v.size();

        for (int i = 0; i < n; i++) {
            int toCompare = v[i];
            while (!st.empty()) {
                long long gcd = __gcd(toCompare, st.top());
                if (gcd != 1) {
                    long long lcm = ((long long)toCompare * (long long)st.top()) / gcd;
                    st.pop();
                    toCompare = (int)lcm;
                } else {
                    break;
                }
            }
            st.push(toCompare);
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};