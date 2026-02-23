class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int n = s.size();
        int i = 0, j = 0;
        while (j < n) {
            while (j - i + 1 > k) {
                i++;
            }
            if (j - i + 1 == k) {
                st.insert(s.substr(i, k));
                i++;
            }
            j++;
        }
        return st.size() >= pow(2, k);
    }
};