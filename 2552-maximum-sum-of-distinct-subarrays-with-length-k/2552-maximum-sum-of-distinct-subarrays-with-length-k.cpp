class Solution {
public:
    long long maximumSubarraySum(vector<int>& v, int k) {
        long long maxsum = 0, sum = 0;
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        int n = v.size();  
        while (r < k && r < n) {
            mp[v[r]]++;
            sum += v[r];
            r++;
        } 
        if (mp.size() == k) {
            maxsum = sum;
        }
        while (r < n) {
            mp[v[r]]++;
            sum += v[r];
            mp[v[l]]--;
            if (mp[v[l]] == 0) {
                mp.erase(v[l]);
            }
            sum -= v[l];
            l++;
            if (mp.size() == k) {
                maxsum = max(maxsum, sum);
            }
            r++;
        }
        return maxsum;
    }
};
