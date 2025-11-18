class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& v) {
        vector<int> ans;
        int n = v.size();
        unordered_set<int> st(v.begin(), v.end());
        int i = 0;
        while (i < n) {
            if (!st.count(i + 1)) {
                ans.push_back(i + 1);
            }
            i++;
        }
        return ans;
    }
};