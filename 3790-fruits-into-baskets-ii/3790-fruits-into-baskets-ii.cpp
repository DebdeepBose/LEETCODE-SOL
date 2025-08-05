class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int n = f.size();
        int c = n;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (f[i] <= b[j] && (st.find(j) == st.end())) {
                    c--;
                    st.insert(j);
                    break;
                }
            }
        }
        return c;
    }
};