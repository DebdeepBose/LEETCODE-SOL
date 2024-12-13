class Solution {
public:
    long long findScore(vector<int>& v) {
        long long s = 0;
        int n = v.size();
        set<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            st.insert({v[i], i});
        }
        for (auto e : st) {
            if (v[e.second] == 0) {
                continue;
            }
            s += e.first;
            v[e.second] = 0;
            if (e.second - 1 >= 0) {
                v[e.second - 1] = 0;
            }
            if (e.second + 1 < n) {
                v[e.second + 1] = 0;
            }
        }
        return s;
    }
};