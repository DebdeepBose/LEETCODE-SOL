class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        if (v.empty()) {
            return 0;
        }
        unordered_set<int> st(v.begin(), v.end());
        int maxc = 1;
        for (auto e : st) {
            if (st.find(e - 1) == st.end()) {
                int el = e;
                int c = 1;
                while (st.find(el + 1) != st.end()) {
                    el = el + 1;
                    c++;
                }
                maxc = max(maxc, c);
            }
        }
        return maxc;
    }
};