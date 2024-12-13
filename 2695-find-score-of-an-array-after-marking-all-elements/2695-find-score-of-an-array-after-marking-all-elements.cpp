class Solution {
public:
    long long findScore(vector<int>& v) {
        long long s = 0;
        vector<pair<int, int>> st;
        int n = v.size();

        for (int i = 0; i < n; i++) {
            st.push_back({v[i], i + 1});
        }
        sort(st.begin(), st.end());
        vector<int> u(n + 2, 0);
        for (auto e : st) {
            if (u[e.second] == 1) {
                continue;
            }
            s += e.first;
            u[e.second] = 1;
            u[e.second - 1] = 1;
            u[e.second + 1] = 1;
        }
        return s;
    }
};