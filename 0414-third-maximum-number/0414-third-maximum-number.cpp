class Solution {
public:
    int thirdMax(vector<int>& v) {
        set<int> st(v.begin(), v.end());
        v.clear();
        v.assign(st.begin(), st.end());
        if (v.size() < 3) {
            return v.back();
        }
        return v[v.size() - 3];
    }
};