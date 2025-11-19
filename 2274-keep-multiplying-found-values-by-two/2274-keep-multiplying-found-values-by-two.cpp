class Solution {
public:
    int findFinalValue(vector<int>& v, int x) {
        unordered_set<int> st(v.begin(), v.end());
        int n = v.size();
        while (true) {
            if (st.count(x)) {
                x *= 2;
            } else {
                break;
            }
        }
        return x;
    }
};