class Solution {
public:
    vector<int> twoSum(vector<int>& v, int k) {
        unordered_map<int, int> mp;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            int req = k - v[i];
            if (mp.find(req) != mp.end()) {
                return {i, mp[req]};
            }
            mp[v[i]] = i;
        }
        return {-1,-1};
    }
};