class Solution {
public:
    long long countSubarrays(vector<int>& v, long long k) {
        multiset<int> st;
        int n = v.size();
        long long ans = 0;
        int i = 0;
        int j = 0;
        while (j < n) {
            st.insert(v[j]);
            while (1LL*(*st.rbegin() - *st.begin()) * (j - i + 1) > k) {
                auto it = st.find(v[i]);
                if (it != st.end()) {
                    st.erase(it);
                }
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
};