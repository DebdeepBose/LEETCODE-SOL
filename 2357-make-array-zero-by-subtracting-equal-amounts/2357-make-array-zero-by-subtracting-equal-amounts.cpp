class Solution {
public:
    int minimumOperations(vector<int>& v) {
        int n = v.size();
        unordered_set<int> st;
        for (auto& e : v) {
            if (e != 0) {
                st.insert(e);
            }
        }
        return st.size();
    }
};