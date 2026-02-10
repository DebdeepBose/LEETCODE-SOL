class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        unordered_map<int, int> mp;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            int req = t - v[i];
            if (mp.find(req) != mp.end()) {
                return {mp[req], i};
            }
            mp[v[i]] = i;
        }
        return {-1, -1};
    }
};