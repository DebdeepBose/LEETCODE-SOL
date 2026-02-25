class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int n = v.size();
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = 1;
        int c = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i];
            int req = sum - k;
            if (mp.find(req) != mp.end()) {
                c += mp[req];
            }

            mp[sum]++;
        }
        return c;
    }
};