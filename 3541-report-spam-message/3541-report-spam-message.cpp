class Solution {
public:
    bool reportSpam(vector<string>& v, vector<string>& v2) {
        unordered_set<string> st;
        for (auto e : v2) {
            st.insert(e);
        }
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
