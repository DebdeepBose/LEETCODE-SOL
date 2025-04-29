class Solution {
public:
    long long countSubarrays(vector<int>& v, int k) {
        long long maxi = *max_element(v.begin(), v.end());
        unordered_map<int, int> mp;
        int n = v.size();
        int l = 0;
        int r = 0;
        int c = 0;
        long long ans = 0;
        while (r < n) {
            if (v[r] == maxi) {
                c++;
            }
            while (c >= k) {
                if (v[l] == maxi) {
                    c--;
                }
                l++;
                ans += n - r;
            }
            r++;
        }
        return ans;
    }
};