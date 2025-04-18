class Solution {
public:
    bool reportSpam(vector<string>& v, vector<string>& v2) {
        ios_base::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
        unordered_set<string> st(v2.begin(), v2.end());
        int c = 0;
        for (auto e : v) {
            if (st.find(e) != st.end()) {
                c++;
            }
            if (c == 2) {
                return true;
            }
        }
        return false;
    }
};
