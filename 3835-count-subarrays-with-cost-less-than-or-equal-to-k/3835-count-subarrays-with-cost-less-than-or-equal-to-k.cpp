class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0;
        int l = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        set<pair<int, int>> st;
        for (int r = 0; r < n; r++) {
            st.insert({nums[r], r});
            maxi = (st.rbegin()->first);
            mini = (st.begin()->first);
            while (!st.empty() && (1LL * (maxi - mini) * (r - l + 1) > k)) {
                int temp = nums[l];
                st.erase({nums[l], l});
                if (st.size() > 0) {
                    mini = (st.begin()->first);
                    maxi = (st.rbegin()->first);
                } else
                    break;
                l++;
            }
            if (1LL * (maxi - mini) * (r - l + 1) <= k)
                ans += (r - l + 1);
        }
        return ans;
    }
};