class Solution {
public:
    long long maximumSubarraySum(vector<int>& v, int k) {
        int n = v.size();
        int l = 0;
        int r = 0;
        long long sum = 0;
        long long maxsum = 0;
        unordered_set<int> st;
        
        while (r < n) {
            while (st.find(v[r]) != st.end()) {
                st.erase(v[l]);
                sum -= v[l];
                l++;
            }
            st.insert(v[r]);
            sum += v[r];
            
            if (st.size() == k) {
                maxsum = max(maxsum, sum);
                st.erase(v[l]);
                sum -= v[l];
                l++;
            }
            r++;
        }
        
        return maxsum;
    }
};
