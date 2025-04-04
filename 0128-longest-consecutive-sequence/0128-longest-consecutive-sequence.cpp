class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        if (v.empty()) {
            return 0;
        }
        set<int> st;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            st.insert(v[i]);
        }
        int c = 1, maxc = INT_MIN;
        for (auto e : st) {
            if (st.find(e + 1) != st.end()) {
                c++;
            } else {
                maxc = max(maxc, c);
                c = 1;
            }
        }
        return maxc;
    }
};