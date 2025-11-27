class Solution {
public:
    long long maxSubarraySum(vector<int>& v, int k) {
        int n = v.size();
        vector<long long> mini(k, LLONG_MAX / 2);
        long long pref = 0;
        mini[(k - 1) % k] = 0;
        long long maxSub = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            pref += v[i];
            maxSub = max(maxSub, pref - mini[i % k]);
            mini[i % k] = min(mini[i % k], pref);
        }
        return maxSub;
    }
};