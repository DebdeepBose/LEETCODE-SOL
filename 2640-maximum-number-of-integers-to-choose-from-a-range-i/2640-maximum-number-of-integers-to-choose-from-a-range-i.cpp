class Solution {
public:
    int maxCount(vector<int>& b, int n, int maxi) {
        set<int> st(b.begin(), b.end());
        b.clear();
        b.assign(st.begin(), st.end());
        int s = 0;
        int idx = 0;
        int c = 0;

        for (int i = 1; i <= n; i++) {
            if (idx < b.size() && i == b[idx]) {
                idx++;
            } else {
                if (s + i <= maxi) {
                    s += i;
                    c++;
                } else {
                    return c;
                }
            }
        }

        return c;
    }
};
