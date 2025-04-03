class Solution {
public:
    vector<int> twoSum(vector<int>& v, int k) {

        int n = v.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int r = k - v[i];

            if (mp.find(r) != mp.end()) {
                return {mp[i], i};
            } else {
                mp[v[i]] = i;
            }
        }
        return {};
    }
};