class Solution {
public:
    vector<int> findMissingElements(vector<int>& v) {
        set<int> st(v.begin(), v.end());
        int f = *st.begin();
        int l = *st.rbegin();

        vector<int> ans;

        for (int i = f; i <= l; i++) {
            if (!st.count(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};