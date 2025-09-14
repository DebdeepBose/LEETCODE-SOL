class Solution {
public:
    vector<int> maxKDistinct(vector<int>& v, int k) {
        int n = v.size();
        set<int> st;
        for (auto e : v) {
            st.insert(e); 
        }

        vector<int> ans;
        for (auto it = st.rbegin(); it != st.rend() && k > 0; ++it, --k) {
            ans.push_back(*it);
        }

        return ans;
    }
};
